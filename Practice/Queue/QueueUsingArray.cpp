#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
    int start, end;
    int currentSize, maxSize;
    T *arr;

public:
    Queue(int s = 100) : start(-1), end(-1), currentSize(0), maxSize(s)
    {
        arr = new T[maxSize];
    }

    void enqueue(T val)
    {
        if (currentSize == maxSize)
        {
            throw overflow_error("Queue overflow: maximum capacity reached!");
        }

        if (currentSize == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }

        arr[end] = val;
        currentSize++;
        cout << "The element enqueued is " << val << endl;
    }

    T dequeue()
    {
        if (currentSize == 0)
        {
            throw underflow_error("Queue underflow: no elements to dequeue!");
        }

        T x = arr[start];
        if (currentSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }

        currentSize--;
        return x;
    }

    T peek()
    {
        if (currentSize == 0)
        {
            throw underflow_error("Queue underflow: queue is empty!");
        }

        return arr[start];
    }

    int size()
    {
        return currentSize;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    void printQueue()
    {
        if (currentSize == 0)
            return;

        cout << "\n---------------- Printing the queue elements ----------------\n";
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[(start + i) % maxSize] << " ";
        }
        cout << endl;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue<int> q(5);
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