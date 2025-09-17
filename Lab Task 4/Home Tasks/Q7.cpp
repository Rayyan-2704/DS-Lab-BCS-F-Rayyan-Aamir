/* 7. Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
algorithms for the same input array size (e.g., 1000 elements). Record and display the time
taken and the number of comparisons/swaps for all three algorithms to demonstrate why
Shell Sort is an improvement over Insertion Sort. */

#include <iostream>
#include <cstdlib>
using namespace std;

void createArrayCopy(int dest[], int src[], int n);
void bubbleSort(int arr[], int n, long long &comparisonsCount, long long &swapsCount);
void insertionSort(int arr[], int n, long long &comparisonsCount, long long &swapsCount);
void shellSort(int arr[], int n, long long &shellComparisons, long long &shellSwaps);

int main(){
    const int size = 1000;
    int *arr = new int[size];

    // Generating random integers (0 - 9999) and storing in the array
    srand(time(0));
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 1000; 

    int *copyArr = new int[size];

    // Bubble Sort Algo Analysis
    createArrayCopy(copyArr, arr, size);
    long long bubbleComparisons = 0, bubbleSwaps = 0;
    bubbleSort(copyArr, size, bubbleComparisons, bubbleSwaps);

    // Insertion Sort Algo Analysis
    createArrayCopy(copyArr, arr, size);
    long long insertionComparisons = 0, insertionSwaps = 0;
    insertionSort(copyArr, size, insertionComparisons, insertionSwaps);

    // Shell Sort Algo Analysis
    createArrayCopy(copyArr, arr, size);
    long long shellComparisons = 0, shellSwaps = 0;
    shellSort(copyArr, size, shellComparisons, shellSwaps);

    cout << "\n----------- Detailed Sorting Algorithms Analysis -----------\n";
    cout << "Bubble Sort: " << bubbleComparisons << " comparisons, " << bubbleSwaps << " swaps" << endl;
    cout << "Insertion Sort: " << insertionComparisons << " comparisons, " << insertionSwaps << " swaps" << endl;
    cout << "Shell Sort: " << shellComparisons << " comparisons, " << shellSwaps << " swaps" << endl;

    delete[] copyArr;
    delete[] arr;
    return 0;
}

void createArrayCopy(int dest[], int src[], int n){
    for(int i = 0; i < n; i++)
        dest[i] = src[i];
}

void bubbleSort(int arr[], int n, long long &comparisonsCount, long long &swapsCount){
    for(int i = 0; i < n - 1; i++){
        bool isSwapped = false;
        
        for(int j = 0; j < n - i - 1; j++){
            comparisonsCount++;
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapsCount++;
                isSwapped = true;
            }
        }

        if(!isSwapped) return;
    }
}

void insertionSort(int arr[], int n, long long &comparisonsCount, long long &swapsCount){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0){
            comparisonsCount++;
            if(arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
                swapsCount++;
            }
            else 
                break;
        }

        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n, long long &shellComparisons, long long &shellSwaps){
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            int j = i;

            while(j >= gap){
                shellComparisons++;
                if(arr[j - gap] > temp){
                    arr[j] = arr[j - gap];
                    shellSwaps++;
                    j -= gap;
                }
                else
                    break;
            }
            arr[j] = temp;
        }
    }
}