#include<iostream>
using namespace std;

class student
{
private:
    string name;
    int class1;int roll;
    float marks;
public:
    void setdata(string n,int c,int r,float m);
    void display();
};
void student::setdata(string n,int c,int r,float m)
{
    name=n;
    class1 =c;
    roll=r;
    marks=m;
}
void student::display()
{
    cout<<"Name = "<<name<<endl;
    cout<<"Class = "<<class1<<endl;
    cout<<"Roll = "<<roll<<endl;
    cout<<"Marks = "<<marks<<endl;
}
int main()
{
    student s1;
    cin>>s1.setdata(string n,int c,int r,float m);
    s1.display();

}
