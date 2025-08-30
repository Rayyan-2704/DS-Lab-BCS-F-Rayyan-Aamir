/* Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=> Demonstrate the class by storing marks of 5 students and printing them safely without direct pointer manipulation. */

#include <iostream>
using namespace std;

class SafePointer
{
    int *ptr;

public:
    SafePointer()
    {
        ptr = new int(0);
    }

    SafePointer(int val)
    {
        ptr = new int(val);
    }

    void setValue(int val)
    {
        if (ptr != nullptr)
        {
            *ptr = val;
        }
    }

    int getValue() const
    {
        if (ptr != nullptr)
        {
            return *ptr;
        }
        throw runtime_error("Pointer is null!");
    }

    void release()
    {
        if (ptr != nullptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    ~SafePointer()
    {
        delete ptr;
    }
};

int main()
{
    const int size = 5;
    SafePointer students[size];

    cout << "Enter the marks of students out of 100 below\n";
    for (int i = 0; i < size; i++)
    {
        while (true)
        {
            int marks;
            cout << "Marks of student " << (i + 1) << ": ";
            cin >> marks;

            if (marks >= 0 && marks <= 100)
            {
                students[i].setValue(marks);
                break;
            }

            cout << "Invalid marks entered!" << endl;
        }
        cout << endl;
    }

    cout << "\n------------ Displaying the marks of students ------------\n";
    for (int i = 0; i < size; i++)
        cout << "Student " << (i + 1) << ": " << students[i].getValue() << " marks" << endl;

    // To manually deallocate memory, we can call the release() member function
    for (int i = 0; i < size; i++)
        students[i].release();

    return 0;
}
