/* Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses. */

#include <iostream>
#include <iomanip>
using namespace std;

void initializeExpenses(double *arr, int n);
double *resizeArray(double *arr, int n, int moreMonths);
void totalAndAvg(double *arr, int n);

int main()
{
    int months;
    while (true)
    {
        cout << "Enter the number of months you'd like to track your expenses for: ";
        cin >> months;

        if (months > 0)
            break;
        cout << "Invalid number of months!" << endl;
    }

    cout << endl;
    double *arr = new double[months];
    initializeExpenses(arr, months);

    while (true)
    {
        char choice;
        int moreMonths;
        cout << "Would you like to add more monthly expenses (Y/N)? ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;

        while (true)
        {
            cout << "Enter the number of months you'd like to further add: ";
            cin >> moreMonths;

            if (moreMonths > 0)
                break;
            cout << "Invalid input!" << endl;
        }

        arr = resizeArray(arr, months, moreMonths);
        months += moreMonths;
    }

    totalAndAvg(arr, months);
    delete[] arr;

    return 0;
}

void initializeExpenses(double *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter your expenses for month " << (i + 1) << " in $: ";
            cin >> arr[i];

            if (arr[i] >= 0.0)
                break;
            cout << "Invalid monthly expense!" << endl;
        }
        cout << endl;
    }
}

double *resizeArray(double *arr, int n, int moreMonths)
{
    double *newArr = new double[n + moreMonths];
    for (int i = 0; i < n; i++)
        newArr[i] = arr[i];

    for (int i = n; i < (n + moreMonths); i++)
    {
        while (true)
        {
            cout << "Enter your expenses for month " << (i + 1) << " in $: ";
            cin >> newArr[i];

            if (newArr[i] >= 0.0)
                break;
            cout << "Invalid monthly expense!" << endl;
        }
        cout << endl;
    }

    delete[] arr;
    return newArr;
}

void totalAndAvg(double *arr, int n)
{
    double total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    cout << "Total Expenses: $" << fixed << setprecision(2) << total << endl;
    cout << "Average Expense: $" << fixed << setprecision(2) << (total / n) << endl;
}
