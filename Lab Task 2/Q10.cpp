/* Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category. */

#include <iostream>
#include <string>
using namespace std;

void inputDetails(string **&ids, int *bookCount, string *categoryNames, int categoryCount);
void searchBookID(string **ids, int *bookCount, string *categoryNames, int categoryCount, string searchID);

int main()
{
    int categoryCount;
    while (true)
    {
        cout << "Enter the number of categories: ";
        cin >> categoryCount;

        if (categoryCount > 0)
            break;
        cout << "Invalid number of categories!" << endl;
    }
    cin.ignore();
    cout << endl;

    string **bookIDs = new string *[categoryCount];
    int *bookCount = new int[categoryCount];
    string *categoryNames = new string[categoryCount];

    inputDetails(bookIDs, bookCount, categoryNames, categoryCount);

    string searchID;
    while (true)
    {
        cout << "\nEnter the ID of the book you'd like to search (or type 'exit' to quit): ";
        getline(cin, searchID);

        if (searchID == "exit")
            break;

        searchBookID(bookIDs, bookCount, categoryNames, categoryCount, searchID);
    }

    for (int i = 0; i < categoryCount; i++)
        delete[] bookIDs[i];
    delete[] bookIDs;
    delete[] bookCount;
    delete[] categoryNames;

    return 0;
}

void inputDetails(string **&ids, int *booksCount, string *categoryNames, int categoryCount)
{
    for (int i = 0; i < categoryCount; i++)
    {
        cout << "\nEnter the name of category " << (i + 1) << ": ";
        getline(cin, categoryNames[i]);

        while (true)
        {
            cout << "Enter the number of books in \'" << categoryNames[i] << "\': ";
            cin >> booksCount[i];

            if (booksCount[i] > 0)
                break;
            cout << "Invalid number of books in \'" << categoryNames[i] << "\'!" << endl;
        }
        cin.ignore();

        ids[i] = new string[booksCount[i]];

        cout << "Enter book IDs for \'" << categoryNames[i] << "\' below" << endl;
        for (int j = 0; j < booksCount[i]; j++)
        {
            cout << "Book " << (j + 1) << ": ";
            getline(cin, ids[i][j]);
        }
    }
}

void searchBookID(string **ids, int *bookCount, string *categoryNames, int categoryCount, string searchID)
{
    bool flag = false;
    for (int i = 0; i < categoryCount; i++)
    {
        for (int j = 0; j < bookCount[i]; j++)
        {
            if (searchID == ids[i][j])
            {
                cout << "Book with ID " << searchID << " is available under the category \'" << categoryNames[i] << "\'" << endl;
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    if (!flag)
        cout << "Book with ID " << searchID << " not found!" << endl;
}
