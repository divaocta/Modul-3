#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void insertBelakang(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->namaProduk << "\t" << current->harga << endl;
            current = current->next;
        }
    }
};
int main()
{
    DoublyLinkedList list;
    // Menambahkan data
    list.insertBelakang("Originote", 60000);
    list.insertBelakang("Somethinc", 150000);
    list.insertBelakang("Skintific", 100000);
    list.insertBelakang("Wardah", 50000);
    list.insertBelakang("Hanasui", 30000);
    cout << "Nama Produk\tHarga" << endl;
    list.display();
    return 0;
}