/* Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks. */

void updateMarks(double **arr, int *numCourses, int s);
void avgMarks(double **arr, int *numCourses, int s);

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int students;
    while(true){
        cout << "Enter the number of students: ";
        cin >> students;

        if(students > 0)
            break;
        cout << "Invalid number of students!" << endl;
    }
    cout << endl;

    double **marks = new double*[students];
    int *numCourses = new int[students];

    for(int i = 0; i < students; i++){
        while(true){
            cout << "Enter the number of courses for student " << (i + 1) << ": ";
            cin >> numCourses[i];

            if(numCourses[i] > 0){
                break;
            }
            cout << "Invalid number of courses!" << endl;
        }

        marks[i] = new double[numCourses[i]];
        cout << endl;
    }

    updateMarks(marks, numCourses, students);
    avgMarks(marks, numCourses, students);

    for(int i = 0; i < students; i++)
        delete[] marks[i];
    delete[] marks;
    delete[] numCourses;

    return 0;
}

void updateMarks(double **arr, int *numCourses, int s){
    for(int i = 0; i < s; i++){
        for(int j = 0; j < numCourses[i]; j++){
            while(true){
                cout << "Enter course " << (j + 1) << " marks out of 100 for student " << (i + 1) << ": ";
                cin >> arr[i][j];

                if(arr[i][j] >= 0 && arr[i][j] <= 100) 
                    break;
                cout << "Invalid marks!" << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
}

void avgMarks(double **arr, int *numCourses, int s){
    cout << "\n------------ Displaying average marks of each student ------------\n";
    for(int i = 0; i < s; i++){
        double total = 0.0, avg;
        for(int j = 0; j < numCourses[i]; j++){
            total += arr[i][j];
        }
        avg = total / numCourses[i];
        cout << "Average Marks of student " << (i + 1) << ": " << fixed << setprecision(2) << avg << endl;
    }
}
