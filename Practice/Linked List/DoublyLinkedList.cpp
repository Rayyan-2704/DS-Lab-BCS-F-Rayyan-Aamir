/* Doubly Linked List Implementation */
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyList
{
    Node<T> *head;

public:
    DoublyList() : head(nullptr) {}

    void push_front(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertKthNode(int k, T val)
    {
        if (k <= 0 || (head == nullptr && k != 1))
        {
            cout << "Invalid position entered." << endl;
            return;
        }

        if (k == 1)
        {
            push_front(val);
            return;
        }

        int count = 1;
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (count == k)
            {
                Node<T> *newNode = new Node<T>(val);
                Node<T> *prev = temp->prev;
                newNode->next = temp;
                newNode->prev = prev;

                temp->prev = newNode;
                prev->next = newNode;
                return;
            }

            if(temp->next == nullptr && count + 1 == k){
                push_back(val);
                return;
            }

            temp = temp->next;
            count++;
        }

        cout << "Position " << k << " is out of range." << endl;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is already empty!" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T> *tail = head;
        while (tail->next != nullptr)
            tail = tail->next;

        Node<T> *newTail = tail->prev;
        newTail->next = nullptr;
        tail->prev = nullptr;
        delete tail;
    }

    void deleteKthNode(int k)
    {
        if (k <= 0)
        {
            cout << "Invalid position entered." << endl;
            return;
        }

        if (head == nullptr)
        {
            cout << "List is already empty." << endl;
            return;
        }

        if (k == 1)
        {
            pop_front();
            return;
        }

        int count = 2;
        Node<T> *temp = head->next;
        while (temp != nullptr)
        {
            if (count == k)
            {
                Node<T> *prev = temp->prev;
                Node<T> *front = temp->next;

                if (front == nullptr)
                {
                    pop_back();
                    return;
                }

                prev->next = front;
                front->prev = prev;

                temp->prev = nullptr;
                temp->next = nullptr;
                delete temp;
                return;
            }

            temp = temp->next;
            count++;
        }

        cout << "Position " << k << " is out of range." << endl;
    }

    void print_list()
    {
        Node<T> *temp = head;
        cout << "\n----------- Printing the list -----------\n";
        while (temp != nullptr)
        {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL\n\n";
    }

    ~DoublyList()
    {
        while (head != nullptr)
            pop_front();

        /* can also use the below commented lines of code to manually delete the list */
        // Node<T> *currentNode = head;
        // while (currentNode != nullptr)
        // {
        //     Node<T> *nextNode = currentNode->next;
        //     delete currentNode;
        //     currentNode = nextNode;
        // }
    }
};

int main()
{
    DoublyList<int> l1;
    l1.push_front(5);
    l1.push_front(10);
    l1.push_front(8);
    l1.push_front(9);
    l1.push_back(7);

    l1.print_list();

    l1.push_back(20);
    l1.print_list();

    l1.pop_front();
    l1.pop_back();
    l1.print_list();

    l1.deleteKthNode(3);
    l1.print_list();

    return 0;
}