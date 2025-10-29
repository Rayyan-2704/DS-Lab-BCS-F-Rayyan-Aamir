#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
    int top;
    T *arr;
    int maxSize;

public:
    Stack(int s = 100) : top(-1), maxSize(s)
    {
        arr = new T[maxSize];
    }

    void push(T val)
    {
        if (top >= maxSize - 1)
        {
            // cout << "Maximum capacity of stack reached!" << endl;
            // return;
            throw overflow_error("Stack overflow: maximum capacity reached!");
        }

        arr[++top] = val;
        cout << "The element pushed is " << val << endl;
    }

    T pop()
    {
        if (top == -1)
        {
            // cout << "Stack already empty!" << endl;
            // return;
            throw underflow_error("Stack underflow: no elements to pop!");
        }

        T x = arr[top];
        top--;
        return x;
    }

    T peek()
    {
        if (top == -1)
        {
            // cout << "Stack already empty!" << endl;
            // return;
            throw underflow_error("Stack underflow: stack is empty!");
        }

        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void printStack()
    {
        if (top == -1)
            return;

        cout << "\n---------------- Printing the stack elements ----------------\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<int> st(5);
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