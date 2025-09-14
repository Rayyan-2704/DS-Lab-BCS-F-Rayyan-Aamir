/* 5. Convert Between Linked List Types
Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
Demonstrate both conversions with sample input lists. */

/* In this question, a seperate class for a List is not implemented to reduce complexity */

#include <iostream>
using namespace std;

/* This node will be used in Singly Linked List and Circular Linked List */
class SLLNode {
public:
    int data;
    SLLNode *next;

    SLLNode(int value) : data(value), next(nullptr) {}
};

/* This node will be used in Doubly Linked List */
class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

void pushBackSingly(SLLNode *&head, int value){
    SLLNode *newNode = new SLLNode(value);

    if(head == nullptr){
        head = newNode;
        return;
    }

    SLLNode *temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void printSinglyList(SLLNode *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printDoublyList(DLLNode *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printCircularList(SLLNode *head){
    if(head == nullptr) return;

    SLLNode *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

DLLNode *convertToDoublyList(SLLNode *sHead){
    if(sHead == nullptr) return nullptr;

    DLLNode *dHead = new DLLNode(sHead->data);
    DLLNode *dTail = dHead;
    sHead = sHead->next;

    while(sHead != nullptr){
        DLLNode *newNode = new DLLNode(sHead->data);
        dTail->next = newNode;
        newNode->prev = dTail;
        dTail = newNode;
        sHead = sHead->next;
    }

    return dHead;
}

SLLNode *convertToCircularList(SLLNode *head){
    if(head == nullptr) return nullptr;

    SLLNode *temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = head;
    return head;
}

void freeSinglyList(SLLNode *&head){
    while(head != nullptr){
        SLLNode *next = head->next;
        delete head;
        head = next;
    }
}

void freeDoublyList(DLLNode *&head){
    while(head != nullptr){
        DLLNode *next = head->next;
        delete head;
        head = next;
    }
}

void freeCircularList(SLLNode *&head){
    if(head == nullptr) return;

    SLLNode* temp = head->next;
    while(temp != head){
        SLLNode* next = temp->next;
        delete temp;
        temp = next;
    }
    delete head;
    head = nullptr;
}

int main(){
    SLLNode *head = nullptr;
    pushBackSingly(head, 5);
    pushBackSingly(head, 10);
    pushBackSingly(head, 15);
    pushBackSingly(head, 30);

    cout << "\n--------- Printing the Singly Linked List ---------\n";
    printSinglyList(head);

    DLLNode *dHead = convertToDoublyList(head);
    cout << "\n--------- Printing the Doubly Linked List ---------\n";
    printDoublyList(dHead);

    SLLNode *cHead = convertToCircularList(head);
    cout << "\n--------- Printing the Circular Linked List ---------\n";
    printCircularList(cHead);

    freeDoublyList(dHead);
    freeCircularList(cHead);
    return 0;
}