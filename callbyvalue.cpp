#include<iostream>
using namespace std;

void swap1(int &a,int &b)
{
   int temp=a;
   a=b;
   b=temp;
}
int main()
{
    int a,b;
    cout<<"Enter two number : ";
    cin>>a>>b;
    cout<<"Before swapping : "<<a<<" "<<b;
    swap1(a,b);
    cout<<"After swapping : "<<a<<" "<<b;
}
