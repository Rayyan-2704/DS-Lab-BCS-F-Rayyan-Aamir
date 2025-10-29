/* Singly Linked List Implementation (without tail) */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class SinglyList
{
    Node<T> *head;

public:
    SinglyList() : head(nullptr) {}

    SinglyList(Node<T> *h) : head(h) {}

    void push_front(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void push_back(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void insertNodeBeforeValue(T el, T val)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert by value." << endl;
            return;
        }

        if (head->data == el)
        {
            push_front(val);
            return;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next->data == el)
            {
                Node<T> *newNode = new Node<T>(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }

            temp = temp->next;
        }

        /* The below commented loop is also valid for this function */
        // Node<T> *temp = head->next;   // start from the 2nd node
        // Node<T> *prev = head;         // keep track of the node before temp
        // while (temp != nullptr)
        // {
        //     if (temp->data == el)
        //     {
        //         Node<T> *newNode = new Node<T>(val);
        //         newNode->next = temp;
        //         prev->next = newNode;
        //         return;
        //     }

        //     prev = temp;
        //     temp = temp->next;
        // }

        cout << "Element with value " << el << " not found." << endl;
    }

    void insertKthNode(int k, T val)
    {
        if (k <= 0 || (head == nullptr && k != 1))
        {
            cout << "Invalid position entered." << endl;
            return;
        }

        if (k == 1)
        {
            push_front(val);
            return;
        }

        int count = 1;
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (count == (k - 1))
            {
                Node<T> *newNode = new Node<T>(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }

            temp = temp->next;
            count++;
        }

        cout << "Position " << k << " is out of range." << endl;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is already empty." << endl;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        temp->next = nullptr; // redundant, but harmless
        delete temp;
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is already empty." << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T> *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNodeByValue(T val)
    {
        if (head == nullptr)
        {
            cout << "List is already empty." << endl;
            return;
        }

        if (head->data == val)
        {
            pop_front();
            return;
        }

        Node<T> *temp = head->next;
        Node<T> *prev = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Element with value " << val << " not found." << endl;
    }

    void deleteKthNode(int k)
    {
        if (k <= 0)
        {
            cout << "Invalid position entered." << endl;
            return;
        }

        if (head == nullptr)
        {
            cout << "List is already empty." << endl;
            return;
        }

        if (k == 1)
        {
            pop_front();
            return;
        }

        int count = 2;
        Node<T> *temp = head->next;
        Node<T> *prev = head;
        while (temp != nullptr)
        {
            if (count == k)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
            count++;
        }

        cout << "Position " << k << " is out of range." << endl;
    }

    bool isPresent(T key)
    {
        Node<T> *temp = head;
        while(temp != nullptr)
        {
            if(temp->data == key)
                return true;
            
            temp = temp->next;
        }

        return false;
    }

    void print_list()
    {
        Node<T> *temp = head;
        cout << "\n----------- Printing the list -----------\n";
        while (temp != nullptr)
        {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL\n\n";
    }

    int length()
    {
        Node<T> *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ~SinglyList()
    {
        while (head != nullptr)
            pop_front();

        /* can also use the below commented lines of code to manually delete the list */
        // Node<T> *currentNode = head;
        // while (currentNode != nullptr)
        // {
        //     Node<T> *nextNode = currentNode->next;
        //     delete currentNode;
        //     currentNode = nextNode;
        // }
    }
};

template <typename T>
Node<T> *convertArrayToList(const vector<T> &arr)
{
    if (arr.empty())
        return nullptr;

    Node<T> *head = new Node<T>(arr[0]);
    Node<T> *parser = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node<T> *newNode = new Node<T>(arr[i]);
        parser->next = newNode;
        parser = parser->next;
    }

    return head;
}

int main()
{
    SinglyList<int> l1;
    l1.push_front(5);
    l1.push_front(10);
    l1.push_front(8);
    l1.push_front(9);
    l1.push_back(7);

    l1.print_list();

    l1.push_back(20);
    l1.print_list();

    // l1.pop_back();
    // l1.pop_front();
    // l1.push_front(1);
    // l1.push_back(69);
    // l1.print_list();

    l1.deleteKthNode(3);
    l1.print_list();
    l1.deleteNodeByValue(5);
    l1.print_list();

    l1.insertKthNode(3, 69);
    l1.print_list();
    l1.insertNodeBeforeValue(69, 17);
    l1.print_list();

    cout << "Final size of list 1: " << l1.length() << endl;

    vector<int> arr = {1, 2, 3, 4, 5};
    Node<int> *head = convertArrayToList<int>(arr);
    SinglyList l2(head);
    l2.print_list();
    cout << "Is a node with value 5 present: " << (l2.isPresent(5) ? "Yes" : "No") << endl;
    cout << "Is a node with value 100 present: " << (l2.isPresent(100) ? "Yes" : "No") << endl;
    cout << "Final size of list 2: " << l2.length() << endl;

    return 0;
}