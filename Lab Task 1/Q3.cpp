/* Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the Rule of Three by defining a destructor,
copy constructor, and copy assignment operator. Demonstrate the behavior of both shallow and deep copy using test cases. */

/* The Rule of Three states to define a custom copy constructor, a '=' copy assignment operator and a destructor to implement deep copy.
Deep copy ensures that the changes made in one object is not reflected by another object(s) by allocating a different memory everytime the custom 
copy constructor or the copy assignment operator is used, and also freeing up the memory when an object goes out of scope.

If the above mentioned copy constructor, copy assignment operator and the destructor were not defined, then shallow copy would have occured.
This would result in different objects having pointer members pointing to the same memory address. Hence, if the value of one object would have
been changed, the same change would also be reflected by another object(s). For example, b2.setSize(50) would change both the size of b1 and b2 to 50. */

#include <iostream>
using namespace std;

class Box
{
    int *size;

public:
    Box()
    {
        size = new int(0);
    }

    Box(int s)
    {
        size = new int(s);
    }

    Box(const Box &other)
    {
        size = new int(*other.size);
    }

    Box &operator=(const Box &other)
    {
        if (this != &other)
        {
            delete this->size;
            this->size = new int(*other.size);
        }

        return *this;
    }

    void setSize(int s)
    {
        *size = s;
    }

    int getSize() const
    {
        return *size;
    }

    ~Box()
    {
        delete size;
    }
};

int main()
{
    Box b1(10);
    Box b2 = b1;
    Box b3;
    b3 = b1;

    cout << "----------- Displaying the initial sizes of the boxes -----------" << endl;
    cout << "Size of Box 1: " << b1.getSize() << " metres" << endl;
    cout << "Size of Box 2: " << b2.getSize() << " metres" << endl;
    cout << "Size of Box 3: " << b3.getSize() << " metres" << endl;

    // Changing the size of box 2 which was initialized via custom copy constructor
    b2.setSize(50);

    // Changing the size of box 3 which was initialized via the custom '=' copy assignment operator
    b3.setSize(25);

    cout << "\n----------- Displaying the sizes of the boxes after modifications -----------" << endl;
    cout << "Size of Box 1: " << b1.getSize() << " metres" << endl;
    cout << "Size of Box 2: " << b2.getSize() << " metres" << endl;
    cout << "Size of Box 3: " << b3.getSize() << " metres" << endl;

    return 0;
}