#include <bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *Prev;
    doublyNode *Next;

    // Creating Constructor
    doublyNode(int val)
    {
        value = val;
        Prev = NULL;
        Next = NULL;
    }
};

// Function Initialization
void insertAtHead(doublyNode *&head, int val);
void insertAtTail(doublyNode *&head, int val);
void display(doublyNode *n);
void displayReverse(doublyNode *&head);
int countLength(doublyNode *&head);

// Made Function
void insertAtHead(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    newNode->Prev = temp;
}

int main()
{
    doublyNode *head = NULL;
    int value, choice;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Reverse Print" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            displayReverse(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << endl
         << "Linked List: ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}