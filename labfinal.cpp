#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//================ Abstract Class =================
class Vehicle
{
protected:
    string customerName;

public:
    Vehicle(string name)
    {
        customerName = name;
    }

    virtual double rental_cost_calculation(int duration) = 0;

    // Function Overloading
    virtual void booking(int days) = 0;
    virtual void booking(double hours) = 0;

    virtual string getVehicleName() = 0;

    virtual ~Vehicle() {}
};

//================ Car Class =================
class Car : public Vehicle
{
public:
    Car(string name) : Vehicle(name) {}

    double rental_cost_calculation(int days)
    {
        return days * 50;
    }

    void booking(int days)
    {
        double cost = rental_cost_calculation(days);

        cout << "\nVehicle: Car\n";
        cout << "Rental Duration: " << days << " day(s)\n";
        cout << "Rate: $50/day\n";
        cout << "Total Rental Cost = $" << cost << endl;
        cout << "Vehicle booked successfully!\n";

        ofstream file("rental_records.txt", ios::app);
        file << customerName << " - Car - " << days
             << " Days - $" << cost << endl;
        file.close();
    }

    void booking(double hours)
    {
        double cost = hours * 15;

        cout << "\nVehicle: Car\n";
        cout << "Rental Duration: " << hours << " hour(s)\n";
        cout << "Rate: $15/hour\n";
        cout << "Total Rental Cost = $" << cost << endl;
        cout << "Vehicle booked successfully!\n";

        ofstream file("rental_records.txt", ios::app);
        file << customerName << " - Car - " << hours
             << " Hours - $" << cost << endl;
        file.close();
    }

    string getVehicleName()
    {
        return "Car";
    }
};

//================ Motorcycle =================
class Motorcycle : public Vehicle
{
public:
    Motorcycle(string name) : Vehicle(name) {}

    double rental_cost_calculation(int days)
    {
        return days * 30;
    }

    void booking(int days)
    {
        double cost = rental_cost_calculation(days);

        cout << "\nVehicle: Motorcycle\n";
        cout << "Rental Duration: " << days << " day(s)\n";
        cout << "Rate: $30/day\n";
        cout << "Total Rental Cost = $" << cost << endl;
        cout << "Vehicle booked successfully!\n";

        ofstream file("rental_records.txt", ios::app);
        file << customerName << " - Motorcycle - " << days
             << " Days - $" << cost << endl;
        file.close();
    }

    void booking(double hours)
    {
        double cost = hours * 10;

        cout << "\nVehicle: Motorcycle\n";
        cout << "Rental Duration: " << hours << " hour(s)\n";
        cout << "Rate: $10/hour\n";
        cout << "Total Rental Cost = $" << cost << endl;
        cout << "Vehicle booked successfully!\n";

        ofstream file("rental_records.txt", ios::app);
        file << customerName << " - Motorcycle - " << hours
             << " Hours - $" << cost << endl;
        file.close();
    }

    string getVehicleName()
    {
        return "Motorcycle";
    }
};

//================ Truck =================
class Truck : public Vehicle
{
public:
    Truck(string name) : Vehicle(name) {}

    double rental_cost_calculation(int days)
    {
        return days * 100;
    }

    void booking(int days)
    {
        double cost = rental_cost_calculation(days);

        cout << "\nVehicle: Truck\n";
        cout << "Rental Duration: " << days << " day(s)\n";
        cout << "Rate: $100/day\n";
        cout << "Total Rental Cost = $" << cost << endl;
        cout << "Vehicle booked successfully!\n";

        ofstream file("rental_records.txt", ios::app);
        file << customerName << " - Truck - " << days
             << " Days - $" << cost << endl;
        file.close();
    }

    void booking(double hours)
    {
        double cost = hours * 25;

        cout << "\nVehicle: Truck\n";
        cout << "Rental Duration: " << hours << " hour(s)\n";
        cout << "Rate: $25/hour\n";
        cout << "Total Rental Cost = $" << cost << endl;
        cout << "Vehicle booked successfully!\n";

        ofstream file("rental_records.txt", ios::app);
        file << customerName << " - Truck - " << hours
             << " Hours - $" << cost << endl;
        file.close();
    }

    string getVehicleName()
    {
        return "Truck";
    }
};

//================ Main =================
int main()
{
    vector<Vehicle *> rentedVehicles;

    int totalBookings;
    cout << "========== VEHICLE RENTAL SYSTEM ==========\n";
    cout << "How many bookings? ";
    cin >> totalBookings;

    while (totalBookings--)
    {
        int choice;
        cout << "\nSelect Vehicle Type:\n";
        cout << "1. Car\n";
        cout << "2. Motorcycle\n";
        cout << "3. Truck\n";
        cout << "Choice: ";
        cin >> choice;

        string name;
        cout << "Enter customer name: ";
        cin >> name;

        Vehicle *v = NULL;

        if (choice == 1)
            v = new Car(name);
        else if (choice == 2)
            v = new Motorcycle(name);
        else if (choice == 3)
            v = new Truck(name);
        else
        {
            cout << "Invalid Choice!\n";
            continue;
        }

        int bookingType;
        cout << "Booking Type:\n";
        cout << "1. Hourly\n";
        cout << "2. Daily\n";
        cout << "Choice: ";
        cin >> bookingType;

        if (bookingType == 1)
        {
            double hours;
            cout << "Enter rental duration (hours): ";
            cin >> hours;
            v->booking(hours);
        }
        else
        {
            int days;
            cout << "Enter rental duration (days): ";
            cin >> days;
            v->booking(days);
        }

        rentedVehicles.push_back(v);

        cout << "------------------------------------------\n";
    }

    cout << "\nReturning all rented vehicles...\n";

    for (int i = 0; i < rentedVehicles.size(); i++)
    {
        cout << rentedVehicles[i]->getVehicleName()
             << " returned successfully.\n";

        delete rentedVehicles[i];
    }

    rentedVehicles.clear();

    cout << "Memory released successfully.\n";
    cout << "Rental fees have been saved to rental_records.txt\n";
    cout << "Thank you for using the Vehicle Rental System.\n";

    return 0;
}
