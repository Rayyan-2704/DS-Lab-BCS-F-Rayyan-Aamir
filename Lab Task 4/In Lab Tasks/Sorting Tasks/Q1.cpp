/* Implement the bubble sort algorithm to sort the array in descending order (starting from the initial pass). 
Take array [10]= {5,1,3,6,2,9,7,4,8,10). You can also take your array as user input. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void bubbleSortDescending(int arr[], int n);

int main(){
    const int size = 10;
    int arr[size] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};

    cout << "\n------------- Original Array -------------\n";
    printArray(arr, size);

    bubbleSortDescending(arr, size);

    cout << "\n------------- Sorted Array (Descending Order) -------------\n";
    printArray(arr, size);

    return 0;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSortDescending(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool isSwapped = false;

        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }
        if(!isSwapped)
            break;
    }
}
