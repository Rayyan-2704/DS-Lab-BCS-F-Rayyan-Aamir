/* Singly Linked List Implementation (without tail) */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyList
{
    Node<T> *head;
    Node<T> *tail;

public:
    SinglyList() : head(nullptr), tail(nullptr) {}

    void push_front(T val) // O(1)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head == nullptr) // if the linked list is empty
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void push_back(T val) // O(1)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head == nullptr) // if the linked list is empty
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void pop_front() // O(1)
    {
        if (head == nullptr)
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        Node<T> *temp = head;
        head = head->next;

        if (head == nullptr) // if the list becomes empty after the removal of the last element
            tail = nullptr;

        temp->next = nullptr;
        delete temp;
    }

    void pop_back() // O(n)
    {
        if (head == nullptr)
        {
            cout << "Linked List is already empty!" << endl;
            return;
        }

        if (head == tail) // edge case when there's only 1 element present in the linked list
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != tail)
            temp = temp->next;

        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    void insert(T val, int pos) // O(n)
    {
        if (pos < 0)
        {
            cout << "Invalid position entered!" << endl;
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node<T> *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == nullptr) // if a position greater than the size of the linked list has been entered
            {
                cout << "Invalid position entered!" << endl;
                return;
            }

            temp = temp->next;
        }

        Node<T> *newNode = new Node<T>(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) // insertion at the end
            tail = newNode;
    }

    int search(T key) // O(n)
    {
        Node<T> *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (temp->data == key)
                return index;

            temp = temp->next;
            index++;
        }

        return -1; // key not found in the linked list
    }

    void print_list() // O(n)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~SinglyList()
    {
        Node<T> *currentNode = head;
        while (currentNode != nullptr)
        {
            Node<T> *nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }
};

int main()
{
    SinglyList<int> l1;
    l1.push_back(3);
    l1.push_front(2);
    l1.push_front(1);

    l1.insert(4, 1);
    l1.print_list();

    cout << l1.search(4) << endl;
    cout << l1.search(69) << endl;

    return 0;
}