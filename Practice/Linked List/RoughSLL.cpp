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

    Node(T value) : data(value), next(nullptr) {}
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
    Node<T> *parser = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node<T> *newNode = new Node<T>(arr[i]);
        parser->next = newNode;
        parser = parser->next;
    }
    return head;
}

template <typename T>
void printlist(Node<T> *&head)
{
    Node<T> *temp = head;
    while (temp)
    {
        cout << temp->data << " => ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
int lengthLL(Node<T> *&head)
{
    Node<T> *temp = head;
    int size = 0;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

int main()
{
    vector<int> arr = {12, 5, 8, 9};
    Node<int> *head = convert2ListFromArr<int>(arr);
    cout << "First element: " << head->data << endl;

    cout << "\n------------- Printing the Linked List -------------" << endl;
    printlist<int>(head);
    cout << "\nLength of LL: " << lengthLL<int>(head) << endl;

    return 0;
}