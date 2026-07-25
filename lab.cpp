#include <iostream>
#include <fstream>
using namespace std;

// Abstract Class
class Vehicle
{
protected:
    string customerName;
    int duration;

public:
    Vehicle(string c, int d)
    {
        customerName = c;
        duration = d;
    }

    // Function Overloading
    void booking(int hour)
    {
        cout << "Rental Duration: " << hour << " hour(s)" << endl;
    }

    void booking(double day)
    {
        cout << "Rental Duration: " << (int)day << " day(s)" << endl;
    }

    virtual double rental_cost_calculation() = 0;

    virtual ~Vehicle() {}
};

// Car
class Car : public Vehicle
{
public:
    Car(string c, int d) : Vehicle(c, d) {}

    double rental_cost_calculation() override
    {
        return duration * 50;
    }
};

// Motorcycle
class Motorcycle : public Vehicle
{
public:
    Motorcycle(string c, int d) : Vehicle(c, d) {}

    double rental_cost_calculation() override
    {
        return duration * 10;
    }
};

// Truck
class Truck : public Vehicle
{
public:
    Truck(string c, int d) : Vehicle(c, d) {}

    double rental_cost_calculation() override
    {
        return duration * 100;
    }
};

int main()
{
    Vehicle *vehicles[100];
    int count = 0;

    ofstream file("rental_records.txt", ios::app);

    int vehicleType, bookingType;
    string name;
    int duration;

    cout << "========== VEHICLE RENTAL SYSTEM ==========\n";

    cout << "Select Vehicle Type:\n";
    cout << "1. Car\n";
    cout << "2. Motorcycle\n";
    cout << "3. Truck\n";
    cout << "Choice: ";
    cin >> vehicleType;

    cout << "Enter customer name: ";
    cin >> name;

    cout << "Enter rental duration: ";
    cin >> duration;

    cout << "Booking Type:\n";
    cout << "1. Hourly\n";
    cout << "2. Daily\n";
    cout << "Choice: ";
    cin >> bookingType;

    if(vehicleType == 1)
    {
        vehicles[count] = new Car(name, duration);
        cout << "\nVehicle: Car\n";
        cout << "Rate: $50/day\n";
    }
    else if(vehicleType == 2)
    {
        vehicles[count] = new Motorcycle(name, duration);
        cout << "\nVehicle: Motorcycle\n";
        cout << "Rate: $10/hour\n";
    }
    else if(vehicleType == 3)
    {
        vehicles[count] = new Truck(name, duration);
        cout << "\nVehicle: Truck\n";
        cout << "Rate: $100/day\n";
    }
    else
    {
        cout << "Invalid Choice!" << endl;
        return 0;
    }

    if(bookingType == 1)
    {
        vehicles[count]->booking(duration);
    }
    else
    {
        vehicles[count]->booking((double)duration);
    }

    double cost = vehicles[count]->rental_cost_calculation();

    cout << "Total Rental Cost = $" << cost << endl;
    cout << "Vehicle booked successfully!" << endl;

    file << name << " " << cost << endl;

    count++;

    // Return vehicles and free memory
    for(int i = 0; i < count; i++)
    {
        delete vehicles[i];
    }

    file.close();

    cout << "\nRental fee saved in rental_records.txt" << endl;
    cout << "Memory released successfully." << endl;

    return 0;
}
