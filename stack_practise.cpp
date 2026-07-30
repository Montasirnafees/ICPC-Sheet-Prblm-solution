#include<bits/stdc++.h>
using namespace std;
int q[100];
int top=-1;

void push(int x)
{
    if(top==99)
    {
        cout<<"overflow"<<endl;
        return ;
    }
    top++;
    q[top]=x;
}

void pop()
{
    if(top==-1)
    {
        cout<<"Underflow";
        return ;
    }
    top--;
}
void display()
{
    if(top==-1)
    {
        cout<<"No elements.";
    }
    else
        {
        for(int i=0;i<=top;i++)
        {
         cout<<q[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    push(10);
    display();
    push(20);
    display();
    push(30);
    display();
    push(40);
    display();
    push(50);
    display();

}
/*
push(10);
    display();
