#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head=NULL;

void insertBegin(int x)
{
    Node* newNode=new Node();

    newNode->data=x;
    newNode->next=head;

    head=newNode;
}

void deleteBegin()
{
    if(head==NULL)
        return;

    Node* temp=head;
    head=head->next;

    delete temp;
}

void display()
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    insertBegin(30);
    insertBegin(20);
    insertBegin(10);

    deleteBegin();
    display();
}
