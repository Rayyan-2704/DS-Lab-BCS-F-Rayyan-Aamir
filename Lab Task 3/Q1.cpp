/* 1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise. */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
    Node *head;

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

    bool isPalindrome(){
        if(head == nullptr || head->next == nullptr)
            return true;

        vector<int> arr;
        Node *temp = head;

        while(temp != nullptr){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int left = 0, right = arr.size() - 1;
        while(left <= right){
            if(arr[left] != arr[right])
                return false;

            left++; right--;
        }

        return true;
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
    List l1, l2, l3, l4;
    l1.push_back(5);
    l1.push_back(5);
    l1.push_back(7);
    l1.push_front(7);

    cout << "\n---------------- Printing List 1 ----------------\n";
    l1.print_list();
    cout << "Is List 1 a palindrome: " << (l1.isPalindrome() ? "Yes" : "No") << endl;

    cout << "\n---------------- Printing List 2 ----------------\n";
    l2.print_list();
    cout << "Is List 2 a palindrome: " << (l2.isPalindrome() ? "Yes" : "No") << endl;

    l3.push_front(50);
    cout << "\n---------------- Printing List 3 ----------------\n";
    l3.print_list();
    cout << "Is List 3 a palindrome: " << (l3.isPalindrome() ? "Yes" : "No") << endl;

    l4.push_front(9);
    l4.push_back(8);
    cout << "\n---------------- Printing List 4 ----------------\n";
    l4.print_list();
    cout << "Is List 4 a palindrome: " << (l4.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}