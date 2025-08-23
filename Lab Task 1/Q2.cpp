/* Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records, complete with a shallow copy implementation?
Define attributes such as student name, exam date, and score within the class, and include methods to set these attributes and
display exam details. As part of this exercise, intentionally omit the implementation of the copy constructor and
copy assignment operator. Afterward, create an instance of the "Exam" class, generate a shallow copy, and observe any resulting issues? */

/* The issue observed when the implementation of the custom copy constructor and copy assignment operator (needed for hard copy)
are omitted is that the pointer members of both objects point to the same memory location, resulting in the compiler providing a shallow copy.
Hence if the value of a pointer member of one object is changed, the same change is also reflected on the pointer member of the other object.
Double deletion will also occur if a custom destructor is made to free up the memory. */

#include <iostream>
#include <cstring>
using namespace std;

class Exam
{
    char *studentName;
    char *examDate;
    int *score;

public:
    Exam() {}

    Exam(const char *name, const char *date, int s)
    {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = new int(s);
    }

    void setStudentName(const char *name)
    {
        strcpy(studentName, name);
    }

    void setExamDate(const char *date)
    {
        strcpy(examDate, date);
    }

    void setScore(int s)
    {
        *score = s;
    }

    void displayDetails()
    {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << *score << endl;
    }

    ~Exam()
    {
        delete[] studentName;
        delete[] examDate;
        delete score;
    }
};

int main()
{
    Exam e1("Rayyan Aamir", "23rd August, 2025", 89);
    cout << "----------- Displaying details of exam 1 -----------" << endl;
    e1.displayDetails();

    Exam e2 = e1;
    cout << "\n----------- Displaying details of exam 2 -----------" << endl;
    e2.displayDetails();

    e2.setStudentName("Usaid Khan");
    e2.setExamDate("2nd September, 2025");
    e2.setScore(95);

    cout << "\n----------- Displaying details of exam 1 (After modification of exam 2) -----------" << endl;
    e1.displayDetails();

    cout << "\n----------- Displaying details of exam 2 (After modification of exam 2) -----------" << endl;
    e2.displayDetails();

    return 0;
}