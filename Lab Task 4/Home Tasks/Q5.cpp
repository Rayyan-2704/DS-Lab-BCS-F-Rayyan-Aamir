/* 5. Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void insertionSort(int arr[], int n);
int interpolationSearch(int arr[], int n, int target);

int main(){
    int size;
    while(1){
        cout << "Enter the size of the array: ";
        cin >> size;

        if(size > 0) break;
        cout << "Invalid size!" << endl;
    }

    int *arr = new int[size];
    cout << "\n------------- Enter the elements of the array below -------------\n";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    // sorting the data incase the user does not enter the elements in the ascending order
    insertionSort(arr, size);

    int target;
    cout << "\nEnter the target element to be searched: ";
    cin >> target;

    int idx = interpolationSearch(arr, size, target);
    if(idx != -1)
        cout << "\nThe target element " << target << " has been found at index " << idx << " of the sorted array." << endl;
    else
        cout << "\nThe target element " << target << " is not present in the array!" << endl;

    cout << "\n------------- Printing the sorted array -------------\n";
    printArray(arr, size);

    delete[] arr;
    return 0;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int interpolationSearch(int arr[], int n, int target){
    int left = 0, right = n - 1;
    while(left <= right && target >= arr[left] && target <= arr[right]){
        if(left == right || arr[left] == arr[right]){
            if(arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if(arr[pos] == target)
            return pos;
        else if(arr[pos] > target)
            right = pos - 1;
        else
            left = pos + 1;
    }

    return -1;
}