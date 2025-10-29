/* Binary Search is used to find whether a given target is present in an array or not. More efficient than the Linear Search
   Time Complexity for Binary Search: O(log n), Time Complexity for Linear Search: O(n)

   Limitations:
   --> Array must be sorted in ascending/descending order
   --> Only works for arrays, vectors and strings. Does not work for other data structures
*/
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 9, 10, 20, 25, 50};
    int size = 8;

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int index = binarySearch(arr, size, target);

    if (index != -1){
        cout << "Target \"" << target << "\" found at index " << index << "!" << endl;
    }
    else {
        cout << "Target \"" << target << "\" not found!" << endl;
    }

    return 0;
}