/* Task 2: 2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops. */

#include <iostream>
using namespace std;

void functionA(int n);
void functionB(int n);

int main(){
    functionA(10);
    return 0;
}

void functionA(int n){
    if(n == 0) return;

    cout << "Function A: " << n << endl;
    functionB(n - 1);
}

void functionB(int n){
    if(n == 0) return;

    cout << "Function B: " << n << endl;
    functionA(n - 1);
}
