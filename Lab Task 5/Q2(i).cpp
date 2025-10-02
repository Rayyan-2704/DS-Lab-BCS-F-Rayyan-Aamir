/* Task 2: 1. Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly. */

#include <iostream>
using namespace std;

void printNumbers(int n){
    cout << n << " ";

    if(n == 1) return;

    printNumbers(n - 1);
}

int main(){
    int num;
    do {
        cout << "Enter number: ";
        cin >> num;

        if(num >= 1) break;
        cout << "Invalid number!" << endl;
    } while(num < 1);

    cout << "\n------------- Printing numbers from (" << num << " to 1) -------------\n";
    printNumbers(num);
    return 0;
}
