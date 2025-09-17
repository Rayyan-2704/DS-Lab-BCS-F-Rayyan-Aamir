/* Your team has been given a large dataset (input by user) of sorted, uniformly distributed account balances. 
If the data is not sorted, you have to sort it first. If the data is not uniformly distributed after you apply sorting (if necessary) 
you can prompt an error. Your manager has asked you to implement Interpolation Search because it estimates the position 
of the target value based on the data distribution. This will allow the search to "jump" closer to the target in fewer iterations. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void insertionSort(int arr[], int n);
bool isUniformlyDistributed(int arr[], int n);
int interpolationSearch(int arr[], int n, int target);

int main(){
    int size;
    while(1){
        cout << "Enter the number of account balances: ";
        cin >> size;

        if(size > 0) break;
        cout << "Invalid size!" << endl;
    }

    int *arr = new int[size];
    cout << "\n------------- Enter the account balances below -------------\n";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    // Sort the data if not sorted
    insertionSort(arr, size);

    if(!isUniformlyDistributed(arr, size)){
        cout << "\nError: The dataset is not uniformly distributed. Interpolation Search cannot be applied!" << endl;
        delete[] arr;
        return 0;
    }

    int target;
    cout << "\nEnter the target account balance to be searched: ";
    cin >> target;

    int idx = interpolationSearch(arr, size, target);
    if(idx != -1)
        cout << "\nThe target balance " << target << " has been found at index " << idx << " of the sorted array." << endl;
    else
        cout << "\nThe target balance " << target << " is not present in the dataset!" << endl;

    cout << "\n------------- Printing the sorted dataset -------------\n";
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

bool isUniformlyDistributed(int arr[], int n){
    if(n < 2)
        return true; // trivially uniform

    int diff = arr[1] - arr[0];
    for(int i = 2; i < n; i++){
        if(arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
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