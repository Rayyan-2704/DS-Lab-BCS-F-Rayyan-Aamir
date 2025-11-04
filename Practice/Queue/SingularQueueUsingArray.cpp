#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int size;  

public:
    Queue(int c) : size(0), capacity(c)
    {
        arr = new int[capacity];
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }

    // Adds an element x at the rear of the queue.
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        arr[size++] = x;
    }

    // Removes the front element of the queue.
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Returns the front element of the queue.
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    // Return the last element of queue
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

int main()
{
    Queue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl << endl;

    q.dequeue();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl << endl;

    q.enqueue(40);
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl << endl;

    return 0;
}