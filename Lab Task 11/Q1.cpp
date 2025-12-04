#include <iostream>
using namespace std;

#define SIZE 11
class Node
{
public:
    string key;
    string value;
    Node *next;

    Node(string k, const string &v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable
{
private:
    Node *table[SIZE];
    int hash(string key)
    {
        int sum = 0;
        for (char i : key)
        {
            sum += i;
        }
        return sum % SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = nullptr;
        }
    }
    
    void insert(string key, const string &v)
    {
        int index = hash(key);
        Node *newNode = new Node(key, v);
        Node* curr = table[index];

        while(curr) {
            if(curr->key == key) {
                curr->value = v;
                return;
            }
            curr = curr->next;
        }
        
        Node* newNode = new Node(key, v);
        newNode->next = table[index];
        table[index] = newNode;
    }
    
    Node *search(string key)
    {
        int index = hash(key);
        Node *curr = table[index];

        while (curr != nullptr)
        {
            if (curr->key == key)
                return curr;

            curr = curr->next;
        }

        return nullptr;
    }
};

int main()
{
    HashTable Htable;
    Htable.insert("A", "aaaaaa");
    Htable.insert("B", "bbbbb");
    Htable.insert("C", "ccccc");
    Htable.insert("A", "zzzzz");

    Node *target = Htable.search("A");
    if (target)
    {
        cout << "Found:" << endl << "Key:" << target->key << "\nValue:" << target->value;
    }

    return 0;
}
