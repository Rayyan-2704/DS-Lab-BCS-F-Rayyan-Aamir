/* 3. Reverse in Groups of K
Reverse nodes of a singly linked list in groups of size k.
• Example:
o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
    Node *head;

    // a helper recursive function to effectively reverse k groups
    Node *reverseK(Node *start, int k){
        Node *prev = nullptr;
        Node *current = start;
        Node *nextNode = nullptr;
        int count = 0;

        while(current != nullptr && count < k){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }

        // recursive call
        if(nextNode != nullptr)
            start->next = reverseK(nextNode, k);
            
        return prev; // prev will now be the new head
    }

public:
    List() : head(nullptr) {}

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

    void reverseInGroups(int k){
        head = reverseK(head, k);
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

int main(){
    int k = 3;
    List list;
    for(int i = 0; i < 8; i++)
        list.push_back(i + 1);

    cout << "\n--------------- Printing the original list ---------------\n";
    list.print_list();

    list.reverseInGroups(k);
    cout << "\n--------------- Printingt the list after the reversal of " << k << " groups ---------------\n";
    list.print_list();

    return 0;
}