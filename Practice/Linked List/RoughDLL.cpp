#include <iostream>
#include <string>
#include <vector>
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
class List
{
    Node<T> *head;

public:
    List() : head(nullptr) {}
};

template <typename T>
Node<T> *convert2ListFromArr(vector<T> &arr)
{
    Node<T> *head = new Node<T>(arr[0]);
    Node<T> *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node<T> *newNode = new Node<T>(arr[i]);
        prev->next = newNode;
        newNode->prev = prev;
        prev = prev->next;
    }
    return head;
}

template <typename T>
void printList(Node<T> *head)
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " => ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
void deleteNode(Node<T> *temp)
{
    Node<T> *prev = temp->prev;
    Node<T> *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->prev = prev;
    temp->prev = temp->next = nullptr;
    delete temp;
}

template <typename T>
void printListReverse(Node<T> *head)
{
    Node<T> *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "NULL";
    while (temp != nullptr)
    {
        cout << " <= " << temp->data;
        temp = temp->prev;
    }
    cout << endl;
}

template <typename T>
Node<T> *reverseDoublyList(Node<T> *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node<T> *current = head;
    Node<T> *lastNode = nullptr;
    while (current != nullptr)
    {
        lastNode = current->prev;
        current->prev = current->next;
        current->next = lastNode;
        current = current->prev;
    }

    return lastNode->prev; // this is the new head
}

int main()
{
    vector<int> arr = {12, 5, 8, 9};
    Node<int> *head = convert2ListFromArr<int>(arr);
    cout << "First element: " << head->data << endl;

    cout << "\n------------- Printing the Linked List -------------" << endl;
    printList<int>(head);

    cout << "\n------------- Printing the Linked List in Reverse -------------" << endl;
    printListReverse<int>(head);

    head = reverseDoublyList(head);
    cout << "\n------------- Printing the Reversed Linked List -------------" << endl;
    printList(head);

    // cout << endl;
    // deleteNode(head->next->next->next);
    // printList(head);

    return 0;
}