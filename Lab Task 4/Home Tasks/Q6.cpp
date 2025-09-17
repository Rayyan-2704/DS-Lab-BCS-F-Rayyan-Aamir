/* 6. Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void combSort(int arr[], int n, long long &comparisonsCount, long long &swapsCount);

int main(){
    int size;
    while(1){
        cout << "Enter the size of the array: ";
        cin >> size;

        if(size > 0) break;
        cout << "Invalid size!" << endl;
    }

    int *arr = new int[size];
    long long comparisonsCount = 0, swapsCount = 0;  // using long long here because the size of comparisons and swaps might be huge for larger arrays
    cout << "\n------------- Enter the elements of the array below -------------\n";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\n------------- Printing the original array -------------\n";
    printArray(arr, size);

    combSort(arr, size, comparisonsCount, swapsCount);

    cout << "\n------------- Printing the sorted array -------------\n";
    printArray(arr, size);
    cout << "\nTotal comparisons: " << comparisonsCount << endl;
    cout << "Total swaps: " << swapsCount << endl;

    delete[] arr;
    return 0;

    return 0;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void combSort(int arr[], int n, long long &comparisonsCount, long long &swapsCount){
    const double shrink = 1.33;
    int gap = n;
    bool isSwapped = true;

    while(gap > 1 || isSwapped){
        gap = (int)(gap / shrink);
        if(gap < 1)
            gap = 1;
        
        isSwapped = false;
        for(int i = 0; i + gap < n; i++){
            comparisonsCount++;
            if(arr[i] > arr[i + gap]){
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapsCount++;
                isSwapped = true;
            }
        }
    }
}
