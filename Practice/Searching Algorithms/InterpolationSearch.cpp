/* Interpolation Search is used to find whether a given target is present in an array or not. Improved version of Binary Search
   Time Complexity for Interpolation Search: O(log log n), Time Complexity for Binary Search: O(log n)

   Limitations:
   --> Array must be sorted in ascending/descending order
   --> Works better if the elements are equally spaced/distributed. Otherwise, time complexity can reach O(n)
*/
#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r && key >= arr[l] && key <= arr[r]) {
        if (l == r || arr[l] == arr[r]) {
            if (arr[l] == key) return l;
            return -1;
        }

        int pos = l + ((double)(r - l)/(arr[r] - arr[l]) * (key - arr[l]));
        if (arr[pos] == key) {
            return pos;
        }
        else if (arr[pos] < key) {
            l = pos + 1;
        }
        else {
            r = pos - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;

    int target;
    cout << "Enter the target: ";
    cin >> target;

    int index = interpolationSearch(arr, size, target);

    if (index != -1){
        cout << "Target \"" << target << "\" found at index " << index << "!" << endl;
    }
    else {
        cout << "Target \"" << target << "\" not found!" << endl;
    }

    return 0;
}