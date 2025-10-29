/* Linear Search is used to find whether a given target is present in an array or not.
   Time Complexity for Linear Search: O(n)

   Limitations:
   --> Slower than other searching algorithms
*/
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (key == arr[i]) return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 9, 10, 20, 25, 50};
    int size = 8;

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int index = linearSearch(arr, size, target);

    if (index != -1){
        cout << "Target \"" << target << "\" found at index " << index << "!" << endl;
    }
    else {
        cout << "Target \"" << target << "\" not found!" << endl;
    }

    return 0;
}