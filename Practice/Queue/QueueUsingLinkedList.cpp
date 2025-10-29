#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue
{
    int size;
    Node<T> *start;
    Node<T> *end;

public:
    Queue() : size(0), start(nullptr), end(nullptr) {}

    void enqueue(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (size == 0)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }

        size++;
        cout << "The element enqueued is " << val << endl;
    }

    T dequeue()
    {
        if (size == 0)
        {
            throw underflow_error("Queue underflow: no elements to dequeue!");
        }

        T x = start->data;
        Node<T> *temp = start;
        start = start->next;
        temp->next = nullptr;
        delete temp;
        size--;
        if (size == 0)
            end = nullptr;
        return x;
    }

    T peek()
    {
        if (start == nullptr)
        {
            throw underflow_error("Queue underflow: Queue is empty!");
        }

        return start->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return start == nullptr;
    }

    void printQueue()
    {
        if (start == nullptr)
            return;

        cout << "\n---------------- Printing the queue elements ----------------\n";
        Node<T> *curr = start;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    ~Queue()
    {
        Node<T> *temp = start;
        while (temp != nullptr)
        {
            Node<T> *delNode = temp;
            temp = temp->next;
            delete delNode;
        }
    }
};

int main()
{
    Queue<int> q;
    try
    {
        cout << "Current size of the queue: " << q.getSize() << endl;
        cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
        // q.dequeue();

        q.enqueue(5);
        q.enqueue(10);
        cout << "Current size of the queue: " << q.getSize() << endl;
        cout << "Top of the queue: " << q.peek() << endl;

        q.enqueue(15);
        q.enqueue(20);
        cout << "Dequeued element from the queue: " << q.dequeue() << endl;
        cout << "Top of the queue: " << q.peek() << endl;
        cout << "Current size of the queue: " << q.getSize() << endl;

        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    try
    {
        cout << "Top of the queue: " << q.peek() << endl;
        cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
        cout << "Current size of the queue: " << q.getSize() << endl;
        q.printQueue();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}