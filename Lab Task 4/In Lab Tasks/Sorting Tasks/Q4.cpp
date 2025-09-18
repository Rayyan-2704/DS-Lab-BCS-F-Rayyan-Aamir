#include <iostream>
using namespace std;

int getPriority(const string &word);
void insertionSort(string arr[], int n);
void printArray(string arr[], int n);

int main(){
    const int size = 8;
    string arr[8] = {"EMP", "CFO", "MGR", "EMP", "VP", "CTO", "MGR", "CEO"};

    insertionSort(arr, size);

    cout << "\n------------- Printing the sorted team in order of highest priority -------------\n";
    printArray(arr, size);

    return 0;
}

int getPriority(const string &word){
    if(word == "CEO") return 1;
    if(word == "CTO") return 2;
    if(word == "CFO") return 3;
    if(word == "VP") return 4;
    if(word == "MGR") return 5;
    return 6;
}

void insertionSort(string arr[], int n){
    for(int i = 1; i < n; i++){
        string key = arr[i];
        int j = i - 1;
        while(j >= 0 && getPriority(arr[j]) > getPriority(key)){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(string arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;
}