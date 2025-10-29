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

template <typename T>
class Stack
{
    Queue<T> q;

public:
    Stack() {}

    void push(T val)
    {
        int s = q.getSize();
        q.enqueue(val);
        for (int i = 0; i < s; i++)
        {
            q.enqueue(q.peek());
            q.dequeue();
        }

        cout << "The element pushed is " << val << endl;
    }

    T pop()
    {
        return q.dequeue();
    }

    T peek()
    {
        return q.peek();
    }

    int size()
    {
        return q.getSize();
    }

    bool isEmpty()
    {
        return q.isEmpty();
    }

    void printStack()
    {
        cout << "\n---------------- Printing the stack elements ----------------\n";
        q.printQueue();
    }

    ~Stack() {}
};

int main()
{
    Stack<int> st;
    try
    {
        cout << "Current size of the stack: " << st.size() << endl;
        cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
        // st.pop();

        st.push(5);
        st.push(10);
        cout << "Current size of the stack: " << st.size() << endl;
        cout << "Top of the stack: " << st.peek() << endl;

        st.push(15);
        st.push(20);
        cout << "Popped out element from the stack: " << st.pop() << endl;
        cout << "Top of the stack: " << st.peek() << endl;
        cout << "Current size of the stack: " << st.size() << endl;

        st.push(30);
        st.push(40);
        st.push(50);
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    try
    {
        cout << "Top of the stack: " << st.peek() << endl;
        cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
        cout << "Current size of the stack: " << st.size() << endl;
        st.printStack();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}