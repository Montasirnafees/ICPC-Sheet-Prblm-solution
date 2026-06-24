#include<iostream>
using namespace std;
class person
{
public:
    string name;
    int nid;
    string address;

    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"NID : "<<nid<<endl;
        cout<<"Address : "<<address<<endl;
    }
};
int main()
{
    person one;
    cin>>one.name;
    cin>>one.nid;
    cin>>one.address;
    one.display();
}
