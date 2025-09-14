/* 4. Josephus Problem using Circular Linked List
Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion. */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    void push_back(int value){
        Node *newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void push_front(int value){
        Node *newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while(temp->next != head)
            temp = temp->next;

        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    int solveJosephus(int k){
        if(head == nullptr) return -1;
        if(head->next == head) return head->data;

        Node *prev = nullptr;
        Node *current = head;

        while(current->next != current){
            for(int i = 1; i < k; i++){
                prev = current;
                current = current->next;
            }

            cout << "Eliminating " << current->data << endl;
            prev->next = current->next;

            if(current == head)
                head = current->next;

            delete current;
            current = prev->next;
        }

        return current->data;
    }

    void print_list(){
        Node *temp = head;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);

        cout << endl;
    }

    ~CircularLinkedList(){
        if(head == nullptr) return;

        Node* temp = head->next;
        while(temp != head){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }

        delete head;
        head = nullptr;
    }
};

int main(){
    int N = 7, k = 3;

    CircularLinkedList list;
    for(int i = 0; i < N; i++)
        list.push_back(i + 1);

    cout << "\n-------- Printing the list --------\n";
    list.print_list();

    cout << "\n-------- Solving the Josephus Problem --------\n";
    cout << "Total people: " << N << " | Eliminating every " << k << "th person" << endl;
    int survivor = list.solveJosephus(k);
    cout << "The survivor is " << survivor << endl;

    return 0;
}