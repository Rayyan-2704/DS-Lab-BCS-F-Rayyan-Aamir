/* Approach 1 where enqueue operation is O(n) and dequeue operation is O(1) */
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
class Stack
{
    int size;
    Node<T> *top;

public:
    Stack() : size(0), top(nullptr) {}

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop()
    {
        if (top == nullptr)
        {
            throw underflow_error("Stack underflow: no elements to pop!");
        }

        T val = top->data;
        Node<T> *temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
        size--;
        return val;
    }

    T peek()
    {
        if (top == nullptr)
        {
            throw underflow_error("Stack underflow: stack is empty!");
        }

        return top->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void printStack()
    {
        if (top == nullptr)
            return;

        Node<T> *curr = top;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    ~Stack()
    {
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            Node<T> *delNode = temp;
            temp = temp->next;
            delete delNode;
        }
    }
};

template <typename T>
class Queue
{
    Stack<T> input;
    Stack<T> output;

public:
    Queue() {}

    void enqueue(T val)
    {
        while (!input.isEmpty())
        {
            output.push(input.peek());
            input.pop();
        }

        input.push(val);

        while (!output.isEmpty())
        {
            input.push(output.peek());
            output.pop();
        }

        cout << "The element enqueued is " << val << endl;
    }

    T dequeue()
    {
        return input.pop();
    }

    T peek()
    {
        return input.peek();
    }

    int size()
    {
        return input.getSize();
    }

    bool isEmpty()
    {
        return input.isEmpty();
    }

    void printQueue()
    {
        cout << "\n---------------- Printing the queue elements ----------------\n";
        input.printStack();
    }

    ~Queue() {}
};

int main()
{
    Queue<int> q;
    try
    {
        cout << "Current size of the queue: " << q.size() << endl;
        cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
        // q.dequeue();

        q.enqueue(5);
        q.enqueue(10);
        cout << "Current size of the queue: " << q.size() << endl;
        cout << "Top of the queue: " << q.peek() << endl;

        q.enqueue(15);
        q.enqueue(20);
        cout << "Dequeued element from the queue: " << q.dequeue() << endl;
        cout << "Top of the queue: " << q.peek() << endl;
        cout << "Current size of the queue: " << q.size() << endl;

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
        cout << "Current size of the queue: " << q.size() << endl;
        q.printQueue();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}