#include <iostream>
using namespace std;

void updateArr(int **arr, int rows, int cols){
    int r, c;
    while(true){
        cout << "Enter the row you want to select: ";
        cin >> r;
        
        cout << "Enter the seat number you want to select: ";
        cin >> c;
        
        if(!((r >= 1 && r <= rows) && (c >= 1 && c <= cols))){
            cout << "Out of bounds!" << endl;
        }
        else break;
    }
    
    arr[r - 1][c - 1] = 1;
}

void printArr(int **arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int rows, cols;
    while(true){
        cout << "Enter the number of benches: ";
        cin >> rows;
        
        cout << "Enter the number of seats: ";
        cin >> cols;
        
        if(!(rows > 0 && cols > 0)){
            cout << "Invalid input!" << endl;
        }
        else break;
    }
    
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = new int[cols];
        
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = 0;
        }
    }
    
    updateArr(arr, rows, cols);
    printArr(arr, rows, cols);
    
    for(int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    
    return 0;
}
