/* 6. Flatten a Multilevel Linked List
Each node has:
• next pointer (normal linked list connection).
• child pointer (points to another linked list).
Write a function to flatten the structure so that all nodes appear in a single-level list.
• Example:
• 1 → 2 → 3
•     |
•     4 → 5
Output: 1 → 2 → 4 → 5 → 3 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node(int value) : data(value), next(nullptr), child(nullptr) {}
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
            Node *childNode = parser->child;

            while(childNode != nullptr){
                Node *nextChild = childNode->next;
                delete childNode;
                childNode = nextChild;
            }

            delete parser;
            parser = nextNode;
        }
    }
};

Node *flattenList(Node *head){
    if(head == nullptr)
        return nullptr;

    Node *current = head;
    while(current != nullptr){
        if(current->child != nullptr){
            Node *nextNode = current->next;
            Node *childHead = flattenList(current->child);

            current->next = childHead;
            current->child = nullptr;

            Node *childTemp = childHead;
            while(childTemp->next != nullptr)
                childTemp = childTemp->next;

            childTemp->next = nextNode;
        }

        current = current->next;
    }

    return head;
}

int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    l1.head->next->child = new Node(4);
    l1.head->next->child->next = new Node(5);

    l1.head = flattenList(l1.head);
    cout << "\n--------------- Printing out the flattened list ---------------\n";
    l1.print_list();

    return 0;
}