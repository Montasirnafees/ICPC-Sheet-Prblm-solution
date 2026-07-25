#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Create and open the file
    ofstream file("message.txt");

    // Store department and university name
    file << "Department: Computer Science and Engineering (CSE)" << endl;
    file << "University: Bangladesh Army University of Science and Technology (BAUST)" << endl;

    // Close the file
    file.close();

    // Display success message
    cout << "Data has been successfully written to message.txt" << endl;

    return 0;
}
