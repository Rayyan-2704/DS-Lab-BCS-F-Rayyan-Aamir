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
        cout << "The element pushed is " << val << endl;
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

        cout << "\n---------------- Printing the stack elements ----------------\n";
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

int main()
{
    Stack<int> st;
    try
    {
        cout << "Current size of the stack: " << st.getSize() << endl;
        cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
        // st.pop();

        st.push(5);
        st.push(10);
        cout << "Current size of the stack: " << st.getSize() << endl;
        cout << "Top of the stack: " << st.peek() << endl;

        st.push(15);
        st.push(20);
        cout << "Popped out element from the stack: " << st.pop() << endl;
        cout << "Top of the stack: " << st.peek() << endl;
        cout << "Current size of the stack: " << st.getSize() << endl;

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
        cout << "Current size of the stack: " << st.getSize() << endl;
        st.printStack();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}