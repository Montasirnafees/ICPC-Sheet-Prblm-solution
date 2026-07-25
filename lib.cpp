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
    if(top==-1)
    {
        cout<<"Underflow\n";
        return;
    }

    top--;
}


int main()
{
    push(10);
    push(20);
    push(30);

    pop();
    for(int i=0;i<=top;i++)
        cout<<st[i]<<" ";
}
