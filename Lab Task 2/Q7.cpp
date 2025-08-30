/* Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary. */

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

void updateSalaries(double **arr, int *numEmployees, int d);
void highestSalaryAndAverage(double **arr, int *numEmployees, int d);

int main()
{
    int departments;
    while (true)
    {
        cout << "Enter the number of departments: ";
        cin >> departments;

        if (departments > 0)
            break;
        cout << "Invalid number of departments!" << endl;
    }
    cout << endl;

    double **salaries = new double *[departments];
    int *numEmployees = new int[departments];

    for (int i = 0; i < departments; i++)
    {
        while (true)
        {
            cout << "Enter the number of employees for department " << (i + 1) << ": ";
            cin >> numEmployees[i];

            if (numEmployees[i] > 0)
            {
                break;
            }
            cout << "Invalid number of employees!" << endl;
        }

        salaries[i] = new double[numEmployees[i]];
        cout << endl;
    }

    updateSalaries(salaries, numEmployees, departments);
    highestSalaryAndAverage(salaries, numEmployees, departments);

    for (int i = 0; i < departments; i++)
        delete[] salaries[i];
    delete[] salaries;
    delete[] numEmployees;

    return 0;
}

void updateSalaries(double **arr, int *numEmployees, int d)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < numEmployees[i]; j++)
        {
            while (true)
            {
                cout << "Enter the salary of employee " << (j + 1) << " from department " << (i + 1) << " in $: ";
                cin >> arr[i][j];

                if (arr[i][j] > 0)
                    break;
                cout << "Invalid salary!" << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

void highestSalaryAndAverage(double **arr, int *numEmployees, int d)
{
    double highestAvg = INT_MIN;
    int highestDep = -1;
    for (int i = 0; i < d; i++)
    {
        double highestSalaryPerDepart = INT_MIN, total = 0.0;

        for (int j = 0; j < numEmployees[i]; j++)
        {
            highestSalaryPerDepart = max(highestSalaryPerDepart, arr[i][j]);
            total += arr[i][j];
        }

        cout << "The highest salary in Department " << (i + 1) << " is $" << fixed << setprecision(2) << highestSalaryPerDepart << endl;
        double avg = total / numEmployees[i];
        if (avg > highestAvg)
        {
            highestAvg = avg;
            highestDep = (i + 1);
        }
    }

    cout << "The department with the overall maximum average salary is Department " << highestDep << " with an average of $" << fixed << setprecision(2) << highestAvg << endl;
}
