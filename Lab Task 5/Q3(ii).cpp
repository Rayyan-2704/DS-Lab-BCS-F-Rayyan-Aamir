/* Task 3: 2. Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks. */

/*
In tail recursion sumTail(int n, int total = 0), the recursive call is the last step and there is no pending operation left after the recursive call.
Hence the compiler can optimize the recursive function into an iterative loop which reduces memory usage.

In non-tail recursion sumNonTail(int n), the recursive call takes place before the addition. So each call must wait for the result of the recursive call
before adding n to the result. Hence, a deeper call stack is formed which consumes more memory.
*/

#include <iostream>
using namespace std;

int sumNonTail(int n){
    if(n == 0) return 0;

    return n + sumNonTail(n - 1);
}

int main(){
    int n;
    do {
        cout << "Enter number: ";
        cin >> n;

        if(n >= 0) break;
        cout << "Please enter a non-negative number!" << endl;
    } while(n < 0);

    cout << "The sum of numbers from 1 to " << n << " is " << sumNonTail(n) << endl;
    return 0;
}
