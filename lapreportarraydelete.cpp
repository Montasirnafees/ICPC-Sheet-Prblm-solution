#include<iostream>
using namespace std;
#define l endl;
class student
{
   public:
       string name;
       int id;
       double gpa;
       void display()
       {
           cout<<name<<l;
           cout<<id<<l;
           cout<<gpa<<l;
       }
};
int main()
{
    student one;
    one.name="x";
    one.id=1121;
    one.gpa=5.0;
    one.display();
}
