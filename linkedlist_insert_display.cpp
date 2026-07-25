#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertBegin(int x)
{
    Node* newNode = new Node();

    newNode->data = x;
    newNode->next = head;

    head = newNode;
}

// Insert at End
void insertEnd(int x)
{
    Node* newNode = new Node();

    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Any Index (0-based)
void insertAtIndex(int index, int x)
{
    if(index == 0)
    {
        insertBegin(x);
        return;
    }

    Node* newNode = new Node();
    newNode->data = x;

    Node* temp = head;

    for(int i=0; i<index-1 && temp!=NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Invalid Index\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from Beginning
void deleteBegin()
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    delete temp;
}

// Delete from End
void deleteEnd()
{
    if(head == NULL)
        return;

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete at Any Index (0-based)
void deleteAtIndex(int index)
{
    if(head == NULL)
        return;

    if(index == 0)
    {
        deleteBegin();
        return;
    }

    Node* temp = head;

    for(int i=0; i<index-1 && temp->next!=NULL; i++)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        cout << "Invalid Index\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;

    delete del;
}

// Display
void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    insertBegin(20);
    insertBegin(10);

    insertEnd(30);
    insertEnd(40);

    insertAtIndex(2,100);

    display();

    deleteBegin();
    display();

    deleteEnd();
    display();

    deleteAtIndex(1);
    display();

    return 0;
}
