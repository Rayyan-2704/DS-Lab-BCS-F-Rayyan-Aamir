/* Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day. */

#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

void inputTemp(double **arr, int d, int t);
void calculateAverages(double **arr, int d, int t);

int main()
{
    int days, times;
    while (true)
    {
        cout << "Enter the number of days: ";
        cin >> days;

        if (days > 0)
            break;
        cout << "Invalid number of days!" << endl;
    }
    cout << endl;

    while (true)
    {
        cout << "Enter the times in a single day: ";
        cin >> times;

        if (times > 0)
            break;
        cout << "Invalid times!" << endl;
    }
    cout << endl;

    double **temp = new double *[days];
    for (int i = 0; i < days; i++)
        temp[i] = new double[times];

    inputTemp(temp, days, times);
    calculateAverages(temp, days, times);

    for (int i = 0; i < days; i++)
        delete[] temp[i];
    delete[] temp;

    return 0;
}

void inputTemp(double **arr, int d, int t)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cout << "Enter the temperature at time " << (j + 1) << " on day " << (i + 1) << " in \xF8 C: ";
            cin >> arr[i][j];
            cout << endl;
        }
        cout << endl;
    }
}

void calculateAverages(double **arr, int d, int t)
{
    double lowestAvg = INT_MAX, highestAvg = INT_MIN;
    int coldestDay = -1, hottestDay = -1;
    for (int i = 0; i < d; i++)
    {
        double total = 0.0;

        for (int j = 0; j < t; j++)
            total += arr[i][j];

        double avg = total / t;
        cout << "The average temperature of day " << (i + 1) << " is " << fixed << setprecision(2) << avg << " \xF8 C" << endl;

        if (avg < lowestAvg)
        {
            lowestAvg = avg;
            coldestDay = i + 1;
        }
        
        if (avg > highestAvg)
        {
            highestAvg = avg;
            hottestDay = i + 1;
        }
    }

    cout << "\nThe hottest day is day " << hottestDay << " with an average temperature of " << fixed << setprecision(2) << highestAvg << " \xF8 C" << endl;
    cout << "The coldest day is day " << coldestDay << " with an average temperature of " << fixed << setprecision(2) << lowestAvg << " \xF8 C" << endl;
}
