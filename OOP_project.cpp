#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Abstract Class
class Vehicle
{
protected:
    string customerName;
    int duration;

public:
    Vehicle(string name, int d)
    {
        customerName = name;
        duration = d;
    }

    virtual double rental_cost_calculation() = 0;
    virtual string getVehicleName() = 0;
    virtual string getDurationType() = 0;
    virtual double getRate() = 0;

    // Function Overloading
    void booking(int hours)
    {
        cout << "Rental Duration: " << hours << " hour(s)" << endl;
    }

    void booking(double days)
    {
        cout << "Rental Duration: " << (int)days << " day(s)" << endl;
    }

    virtual ~Vehicle() {}
};

// Car
class Car : public Vehicle
{
public:
    Car(string name, int d) : Vehicle(name, d) {

    }

    double rental_cost_calculation() override
    {
        return duration * 50;
    }

    string getVehicleName() override
    {
        return "Car";
    }

    string getDurationType() override
    {
        return "Days";
    }

    double getRate() override
    {
        return 50;
    }
};

// Motorcycle
class Motorcycle : public Vehicle
{
public:
    Motorcycle(string name, int d) : Vehicle(name, d) {}

    double rental_cost_calculation() override
    {
        return duration * 10;
    }

    string getVehicleName() override
    {
        return "Motorcycle";
    }

    string getDurationType() override
    {
        return "Hours";
    }

    double getRate() override
    {
        return 10;
    }
};

// Truck
class Truck : public Vehicle
{
public:
    Truck(string name, int d) : Vehicle(name, d) {}

    double rental_cost_calculation() override
    {
        return duration * 100;
    }

    string getVehicleName() override
    {
        return "Truck";
    }

    string getDurationType() override
    {
        return "Days";
    }

    double getRate() override
    {
        return 100;
    }
};

int main()
{
    vector<Vehicle *> rentedVehicles;
    ofstream file("rental_records.txt");

    int choice;

    while (true)
    {
        cout << "\n========== VEHICLE RENTAL SYSTEM ==========\n";
        cout << "1. Car\n";
        cout << "2. Motorcycle\n";
        cout << "3. Truck\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        string name;
        int bookingType;
        int duration;

        cout << "Enter customer name: ";
        cin >> name;

        if (choice == 2)
        {
            cout << "Enter rental duration (hours): ";
        }
        else
        {
            cout << "Enter rental duration (days): ";
        }

        cin >> duration;

        cout << "\nBooking Type:\n";
        cout << "1. Hourly\n";
        cout << "2. Daily\n";
        cout << "Choice: ";
        cin >> bookingType;

        Vehicle *v = nullptr;

        if (choice == 1)
            v = new Car(name, duration);

        else if (choice == 2)
            v = new Motorcycle(name, duration);

        else if (choice == 3)
            v = new Truck(name, duration);

        rentedVehicles.push_back(v);

        cout << "\nVehicle: " << v->getVehicleName() << endl;

        if (bookingType == 1)
            v->booking(duration);
        else
            v->booking((double)duration);

        cout << "Rate: $" << v->getRate();

        if (bookingType == 1)
            cout << "/hour\n";
        else
            cout << "/day\n";

        double total = v->rental_cost_calculation();

        cout << "Total Rental Cost = $" << total << endl;
        cout << "Vehicle booked successfully!\n";

        file << name << " - "
             << v->getVehicleName() << " - "
             << duration << " "
             << v->getDurationType()
             << " - $" << total << endl;

        cout << "------------------------------------------\n";
    }

    cout << "\nReturning all rented vehicles...\n";

    for (Vehicle *v : rentedVehicles)
    {
        cout << v->getVehicleName() << " returned successfully.\n";
        delete v;
    }

    rentedVehicles.clear();

    cout << "Memory released successfully.\n";

    file.close();

    cout << "Rental fees have been saved to rental_records.txt\n";
    cout << "Thank you for using the Vehicle Rental System.\n";

    return 0;
}
