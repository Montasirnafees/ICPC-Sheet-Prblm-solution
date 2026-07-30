/* BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int x)
{
    if(root == NULL)
        return new Node(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Inorder
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int q[100];
int front=-1,rear=-1;

void enqueue(int x)
{
    if(rear==99)
    {
        cout<<"Overflow\n";
        return;
    }

    if(front==-1)
        front=0;

    rear++;
    q[rear]=x;
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        cout<<"Underflow\n";
        return;
    }

    front++;
}
void display()
{
    if (rear == -1)
    {
        cout << "Queue is Empty!!" << endl;
    }
    else
    {
        cout << "Queue elements are lolo: ";

        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }

        cout << endl;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    dequeue();
    display();
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int st[100];
int top = -1;

void push(int x)
{
    if(top == 99)
    {
        cout << "Overflow\n";
        return;
    }

    top++;
    st[top] = x;
}

void pop()
{
    if(top == -1)
    {
        cout << "Underflow\n";
        return;
    }

    top--;
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is Empty\n";
        return;
    }

    for(int i = 0; i <= top; i++)
    {
        cout << st[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    pop();

    display();

    return 0;
}
*/
