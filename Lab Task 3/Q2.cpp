/* 2. Merge Two Sorted Singly Linked Lists
Implement a function to merge two sorted singly linked lists into one sorted list.
• Example:
o List A: 1 → 3 → 5
o List B: 2 → 4 → 6
o Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers). */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
public:
    Node *head;

    List() : head(nullptr) {}

    List(Node *h) : head(h) {}

    void push_back(int value){
        Node *newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            return;
        }

        Node *temp = head;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void push_front(int value){
        Node *newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void print_list(){
        Node *parser = head;

        while(parser != nullptr){
            cout << parser->data << " => ";
            parser = parser->next;
        }
        cout << "NULL" << endl;
    }

    ~List(){
        Node *parser = head;
        while(parser != nullptr){
            Node *nextNode = parser->next;
            delete parser;
            parser = nextNode;
        }
    }
};

/* Merging Lists by creating new nodes */
List mergeLists(const List &l1, const List &l2){ 
    Node *temp1 = l1.head;
    Node *temp2 = l2.head;
    List mergedList;

    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->data < temp2->data){
            mergedList.push_back(temp1->data);
            temp1 = temp1->next;
        }
        else{
            mergedList.push_back(temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1 != nullptr){
        mergedList.push_back(temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != nullptr){
        mergedList.push_back(temp2->data);
        temp2 = temp2->next;
    }

    return mergedList;
}

/* Without creating new nodes (rearranging pointers) */
Node *mergeListsBonus(Node *h1, Node *h2){
    if(h1 == nullptr) return h2;
    if(h2 == nullptr) return h1;

    Node *head = nullptr;
    Node *tail = nullptr;
    if(h1->data < h2->data){
        head = h1; 
        tail = h1;
        h1 = h1->next;
    }
    else{
        head = h2;
        tail = h2;
        h2 = h2->next;
    }

    while(h1 != nullptr && h2 != nullptr){
        if(h1->data < h2->data){
            tail->next = h1;
            tail = tail->next;
            h1 = h1->next;
        }
        else{
            tail->next = h2;
            tail = tail->next;
            h2 = h2->next;
        }
    }

    if(h1 != nullptr)
        tail->next = h1;
    else if(h2 != nullptr)
        tail->next = h2;

    return head;
}

int main(){
    List listA, listB;

    listA.push_back(1);
    listA.push_back(3);
    listA.push_back(5);
    cout << "\n---------------- Printing List A ----------------\n";
    listA.print_list();

    listB.push_back(2);
    listB.push_back(4);
    listB.push_back(6);
    cout << "\n---------------- Printing List B ----------------\n";
    listB.print_list();

    List mergedList(mergeListsBonus(listA.head, listB.head));
    cout << "\n---------------- Printing the Merged List ----------------\n";

    listA.head = nullptr;  
    listB.head = nullptr;

    mergedList.print_list();

    return 0;
}