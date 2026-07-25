#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Vehicle
{
protected:
    string customername;
    int duration;
public:
    Vehicle(string c,int d)
    {
        customerName = c;
        duration = d;
    }
    virtual double rental_cost_calculation()=0;
    virtual string Vehicle_type()=0;
    virtual string booking_type()=0;
    virtual double rate()=0;

    //booking kori nai
    virtual ~Vehicle;
};
class Car : public Vehicle
{
    Car(string c,int d):Vehicle(n,d){}

    double rental_cost_calculation() override
    {
        return duration * 50;
    }
    double vehicle_type() override
    {
        return "Car";
    }
    double booking_type() override
    {
        return "Days";
    }
    double rate() override
    {
        return 50;
    }
class Motorcycle : public Vehicle
{
    Motorcycle(string c,int d):Vehicle(n,d){}

    double rental_cost_calculation() override
    {
        return duration * 10;
    }
    double vehicle_type() override
    {
        return "Motorcycle";
    }
    double booking_type() override
    {
        return "Hours";
    }
    double rate() override
    {
        return 10;
    }
};

class Truck : public Vehicle
{
    Truck(string c,int d):Vehicle(n,d){}

    double rental_cost_calculation() override
    {
        return duration * 100;
    }
    double vehicle_type() override
    {
        return "Truck";
    }
    double booking_type() override
    {
        return "Truck";
    }
    double rate() override
    {
        return 100;
    }
};

int main()
vector<Vehicle*> rentvehicle;
ofstream file("Rent.txt");
int choice;
while(true)
{
    cout << "\n========== VEHICLE RENTAL SYSTEM ==========\n";
        cout << "1. Car\n";
        cout << "2. Motorcycle\n";
        cout << "3. Truck\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        if(choice ==0)
            break;
        /*
        Book *b = nullptr;

        if(choice == 1)
            b = new Story_book(name,duration);

        else if(choice == 2)
            b = new Science_book(name,duration);

        else if(choice == 3)
            b = new History_book(name,duration);

        else
        {
            cout << "Invalid Choice\n";
            continue;
        }

        library.push_back(b);

        cout << "\nBook: " << b->borrowtype() << endl;

        if(borrowType == 1)
            b->booking(duration);
        else
            b->booking((double)duration);

        cout << "Rate: $" << b->rate();

        if(borrowType == 1)
            cout << "/day" << endl;
        else
            cout << "/week" << endl;

        double fee = b->book_fee();

        cout << "Total Borrow Fee = $" << fee << endl;
        cout << "Book borrowed successfully!\n";

        file << name << " - "
             << b->borrowtype() << " - "
             << duration << " "
             << b->durationtype()
             << " - $" << fee << endl;
    }

    cout << "\nReturning all borrowed books...\n";

    for(Book *b : library)
    {
        cout << b->borrowtype() << " returned successfully.\n";
        delete b;
    }

    library.clear();

    file.close();

    cout << "Memory released successfully.\n";
    cout << "Borrowing fees have been saved to Library.txt\n";

    return 0;
}
*/
}
