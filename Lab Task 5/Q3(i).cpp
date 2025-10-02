/* Task 3: 1. Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function. */

#include <iostream>
using namespace std;

int sumTail(int n, int total = 0){
    if(n == 0) return total;

    return sumTail(n - 1, total + n);
}

int main(){
    int n;
    do {
        cout << "Enter number: ";
        cin >> n;

        if(n >= 0) break;
        cout << "Please enter a non-negative number!" << endl;
    } while(n < 0);

    cout << "The sum of numbers from 1 to " << n << " is " << sumTail(n) << endl;
    return 0;
}
