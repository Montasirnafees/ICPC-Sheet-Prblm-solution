#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


void insertAtBeginning(Node** head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = *head;

    *head = newNode;
}


void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}


int main()
{
    Node* head = NULL;

    int n;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;

        insertAtBeginning(&head,x);
    }


    printList(head);

    return 0;
}
