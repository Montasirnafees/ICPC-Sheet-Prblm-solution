#include<iostream>
using namespace std;
class Swapping
{
public:
    int a,b;
    void Swap(int a,int b){
    int t;
    t=a;
    a=b;
    b=t;
    cout<<a<<" "<<b;
    }
};
int main()
{
    Swapping one;
    cout<<"Enter two number: ";
    cin>>one.a>>one.b;
    one.Swap(one.a,one.b);
}
