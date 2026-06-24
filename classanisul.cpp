#include<iostream>
using namespace std;

class student
{
public:
    string name;
    int id;
    double gpa;

    void display()
    {
    cout<<name<<"\n";
    cout<<id;
    cout<<gpa<<"\n";
    }
};
int main()
{
    student one,two;
    one.name="Nafees";
    one.id=111111;
    one.gpa=5.0;
    one.display();

    two.name="Suporna";
    two.id=22222;
    two.gpa=4;
    two.display();
}
