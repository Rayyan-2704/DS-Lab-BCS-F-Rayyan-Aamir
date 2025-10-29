/* Circular Linked List Implementation */
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    int data;
    Node<T> *next;

    Node(int value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularList
{
    Node<T> *head;
    Node<T> *tail;

public:
    CircularList() : head(nullptr), tail(nullptr) {}

    void push_front(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;

        // if only tail was implemented
        // newNode->next = tail->next;
        // tail->next = newNode;
    }

    void push_back(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        newNode->next = head;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != tail)
            temp = temp->next;

        temp->next = head;
        tail->next = nullptr;
        delete tail;
        tail = temp;
    }

    void print_list()
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        cout << "\n----------- Printing the list -----------\n";
        do
        {
            cout << temp->data << " => ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }

    ~CircularList()
    {
        while (head != nullptr)
            pop_front();
    }
};

int main()
{
    CircularList<int> l1;
    l1.push_back(12);
    l1.push_front(8);
    l1.push_front(5);
    l1.push_back(15);
    l1.push_front(1);

    l1.print_list();

    l1.pop_front();
    l1.pop_back();
    l1.print_list();

    return 0;
}