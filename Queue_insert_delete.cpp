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
        cout << "Queue elements are: ";

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
