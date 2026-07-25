#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Menu.
void printMenu()
{
    cout << "\n========== Inventory Management System ==========\n";
    cout << "1. Add Product\n";
    cout << "2. Display All Products\n";
    cout << "3. Search Product\n";
    cout << "4. Update Product\n";
    cout << "5. Delete Product\n";
    cout << "6. Save Data to File\n";
    cout << "7. Load Data from File\n";
    cout << "8. Increase Inventory Capacity\n";
    cout << "9. Exit\n";
    cout << "===================================================\n";
}

// Show update options.
void updateMenu()
{
    cout << "\nUpdate Options:\n";
    cout << "1. Update ID\n";
    cout << "2. Update Name\n";
    cout << "3. Update Category\n";
    cout << "4. Update Quantity\n";
    cout << "5. Update Price\n";
}

// Pause display for better use.
void pauseSystem()
{
    cout << "\nPress Enter to go back to the menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool isNumber(string &s)
{
    for (char c : s)
    {
        if (!isdigit(c))
            return false;
    }
    return !s.empty();
}

void emptyState()
{
    cout << "\n=== Inventory List ===\n";
    cout << left << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(12) << "Quantity"
         << setw(15) << "Price"
         << "\n";
    cout << string(70, '-') << "\n";
    cout << string(15, ' ');
    cout << "[Warning] Your Inventory is empty!\n";
    cout << string(70, '-') << "\n";
}
void loadData();

class inventory_management;
// Pure Virtual class.
class Inventory
{
public:
    virtual void add_product(int &x, int y) = 0;
    virtual void update_product(inventory_management manager[], int currentProduct) = 0;
    virtual ~Inventory() {}
};

// Inherited class.
class Item : public Inventory
{
protected:
    int *id, *quantity;
    string *productName, *category;
    double *price;

public:
    // Create a new item with default values.
    Item()
    {
        id = new int(0);
        quantity = new int(0);
        price = new double(0.0);
        productName = new string;
        category = new string;
    }

    // Copy constructor
    Item(const Item &other)
    {
        id = new int(*other.id);
        quantity = new int(*other.quantity);
        price = new double(*other.price);
        productName = new string(*other.productName);
        category = new string(*other.category);
    }

    // Overloaded Assignment Operator
    Item &operator=(const Item &other)
    {
        *id = *other.id;
        *quantity = *other.quantity;
        *price = *other.price;
        *productName = *other.productName;
        *category = *other.category;
        return *this;
    }

    void inputPrice()
    {
        try
        {
            cin >> *price;

            if (*price == 0.0)
                throw string("Are you sure the product price is 0 tk? y or n : ");

            if (*price < 0.0)
                throw *price;

            cout << "  [SUCCESS] Price Accepted.\n";
        }

        catch (string &st)
        {
            cout << "  [ERROR] " << st;
            char x;
            cin >> x;
            if (x == 'n')
            {
                cout << "Please re-enter the price : ";
                inputPrice();
            }
            else
                cout << "  [SUCCESS] Price Accepted.\n";
        }

        catch (double p)
        {
            cout << "  [ERROR] Price cannot be negative. Please re-enter the price: ";
            inputPrice();
        }
    }

    // Set product values.
    void setId(int i) { *id = i; }
    void setName(string n) { *productName = n; }
    void setCategory(string c) { *category = c; }
    void setQuantity(int q) { *quantity = q; }

    // Get product values.
    int getId() { return *id; }
    string getName() { return *productName; }
    string getCategory() { return *category; }
    int getQuantity() { return *quantity; }
    double getPrice() { return *price; }

    ~Item()
    {
        delete id;
        delete quantity;
        delete price;
        delete productName;
        delete category;
    }
};

// All functionality for inventory management.
class inventory_management : public Item
{
public:
    void add_product(int &x, int y);
    void update_product(inventory_management manager[], int currentProduct);

    friend void search_product(inventory_management manager[], int currentProduct);
    friend void delete_product(inventory_management manager[], int &currentProduct);
    friend void displayAll(inventory_management manager[], int currentProduct);
    friend bool checkId(inventory_management manager[], int currentProduct, int id);
    friend void saveData(inventory_management manager[], int currentProduct);

    ~inventory_management() {}
};

int findProduct(inventory_management manager[], int currentProduct, int id)
{
    for (int i = 0; i < currentProduct; i++)
    {
        if (manager[i].getId() == id)
            return i;
    }
    return -1;
}

int findProduct(inventory_management manager[], int currentProduct, const string &name)
{
    for (int i = 0; i < currentProduct; i++)
    {
        if (manager[i].getName() == name)
            return i;
    }
    return -1;
}

int main()
{
    cout << "Welcome to the Inventory Management System!\n";
    int maxnumber;
    cout << "Maximum how many product your inventory can store? ";
    cin >> maxnumber;

    inventory_management *manager = new inventory_management[maxnumber];

    int currentProduct = 0, check = 1;

    while (check)
    {
        printMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (currentProduct == maxnumber)
            {
                cout << "\n  [ERROR] Cannot add new product, Inventory is full!\n";
                break;
            }
            int tempId;
            cout << "\nEnter Product ID: ";
            cin >> tempId;

            if (checkId(manager, currentProduct, tempId))
            {
                cout << "\n  [ERROR] Product with ID " << tempId << " already exists.\n";
            }
            else
            {
                manager[currentProduct].setId(tempId);
                manager[currentProduct].add_product(currentProduct, maxnumber);
                currentProduct++;
            }
            pauseSystem();
            break;
        case 2:
            if (currentProduct == 0)
            {
                emptyState();
                pauseSystem();
                continue;
            }
            displayAll(manager, currentProduct);
            pauseSystem();
            break;
        case 3:
            search_product(manager, currentProduct);
            pauseSystem();
            break;
        case 4:
            manager->update_product(manager, currentProduct);
            pauseSystem();
            break;
        case 5:
            delete_product(manager, currentProduct);
            pauseSystem();
            break;
        case 6:
            saveData(manager, currentProduct);
            pauseSystem();
            break;
        case 7:
            loadData();
            pauseSystem();
            break;
        case 8:
        {
            int newMax;
            cout << "\nCurrent maximum capacity is: " << maxnumber << "\n";
            cout << "Enter the new maximum capacity: ";
            cin >> newMax;

            if (newMax <= maxnumber)
            {
                cout << "\n  [ERROR] New capacity must be greater than the current capacity (" << maxnumber << ").\n";
            }
            else
            {
                inventory_management *tempManager = new inventory_management[newMax];

                for (int i = 0; i < currentProduct; i++)
                {
                    tempManager[i] = manager[i];
                }

                delete[] manager;

                manager = tempManager;
                maxnumber = newMax;

                cout << "\n  [SUCCESS] Inventory capacity successfully increased to " << maxnumber << "!\n";
            }
            pauseSystem();
            break;
        }
        case 9:
            cout << "\nExiting Inventory Management System. Goodbye!\n";
            check = false;
            break;
        default:
            cout << "\n  [ERROR] Invalid choice. Please select 1-9.\n";
        }
    }

    delete[] manager;
    return 0;
}

// Add a new product to the inventory.
void inventory_management::add_product(int &x, int y)
{
    try
    {
        cout << "\nEnter Product name: ";
        getline(cin >> ws, *productName);
        cout << "Enter Category: ";
        getline(cin >> ws, *category);
        cout << "Enter Quantity: ";
        cin >> *quantity;
        cout << "Enter Unit Price: ";
        inputPrice();

        cout << "\n  [SUCCESS] Product added.\n";
        if (x == y - 1)
        {
            cout << "  [WARNING] Your Inventory is full.\n";
        }
    }

    catch (int i)
    {
        cout << "\n  [ERROR] Product with ID: " << i << " already exists.\n";
    }
}

// Search for a product by name or ID.
void search_product(inventory_management manager[], int currentProduct)
{
    string search;
    cout << "\nEnter the name or ID of the product: ";
    getline(cin, search);

    int i = isNumber(search) ? findProduct(manager, currentProduct, stoi(search))
                             : findProduct(manager, currentProduct, search);

    if (i != -1)
    {
        cout << "\n==============================\n";
        cout << " Product Found\n";
        cout << "------------------------------\n";
        cout << " ID       : " << manager[i].getId() << "\n";
        cout << " Name     : " << manager[i].getName() << "\n";
        cout << " Category : " << manager[i].getCategory() << "\n";
        cout << " Quantity : " << manager[i].getQuantity() << "\n";
        cout << " Price    : " << fixed << setprecision(2) << manager[i].getPrice() << "\n";
        cout << "==============================\n";
        return;
    }

    cin.ignore();
    cout << "\n  [ERROR] Product not found.\n";

}

// Update an existing product.
void inventory_management::update_product(inventory_management manager[], int currentProduct)
{
    int id;
    cout << "\nEnter the ID of the product you want to update: ";
    cin >> id;

    int index = -1;
    try
    {
        for (int i = 0; i < currentProduct; i++)
        {
            if (manager[i].getId() == id)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            throw string("  [ERROR] No product found with ID: ");
        }
    }
    catch (string &st)
    {
        cout << "\n"
             << st << id << "\n";
        return;
    }

    cout << "\n==============================\n";
    cout << " Current Product details\n";
    cout << "------------------------------\n";
    cout << " ID       : " << manager[index].getId() << "\n";
    cout << " Name     : " << manager[index].getName() << "\n";
    cout << " Category : " << manager[index].getCategory() << "\n";
    cout << " Quantity : " << manager[index].getQuantity() << "\n";
    cout << " Price    : " << fixed << setprecision(2) << manager[index].getPrice() << "\n";
    cout << "==============================\n";

    cout << "\nWhat do you want to update?\n";
    updateMenu();
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    int check = 1;
    string updated;

    switch (choice)
    {
    case 1:
    {
        int a;
        cout << "Enter new ID: ";
        cin >> a;
        manager[index].setId(a);
        updated = "ID";
        break;
    }
    case 2:
    {
        string b;
        cout << "Enter new name: ";
        getline(cin >> ws, b);
        manager[index].setName(b);
        updated = "Name";
        break;
    }
    case 3:
    {
        string c;
        cout << "Enter new category: ";
        getline(cin >> ws, c);
        manager[index].setCategory(c);
        updated = "Category";
        break;
    }
    case 4:
    {
        int d;
        cout << "Enter new quantity: ";
        cin >> d;
        manager[index].setQuantity(d);
        updated = "Quantity";
        break;
    }
    case 5:
        cout << "Enter new price: ";
        manager[index].inputPrice();
        updated = "Price";
        break;
    default:
        cout << "\n  [ERROR] Invalid choice.\n";
        check = 0;
    }

    if (check)
    {
        cout << "  [SUCCESS] Product " << updated << " updated.\n";
    }
}

// Delete a product by ID.
void delete_product(inventory_management manager[], int &currentProduct)
{
    int id;
    cout << "\nEnter the ID of the product you want to delete: ";
    cin >> id;

    int index = -1;
    try
    {
        for (int i = 0; i < currentProduct; i++)
        {
            if (manager[i].getId() == id)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            throw string("  [ERROR] No product found with ID: ");
        }
    }

    catch (string &st)
    {
        cout << "\n"
             << st << id << "\n";
        return;
    }

    for (int i = index; i < currentProduct - 1; i++)
    {
        manager[i] = manager[i + 1];
    }

    currentProduct--;
    cout << "\n  [SUCCESS] Product with ID " << id << " deleted successfully.\n";

    if (currentProduct == 0)
        cout << "   [WARNING] Inventory is now empty.\n";
}

// Display all products in the inventory.
void displayAll(inventory_management manager[], int currentProduct)
{
    cout << "\n=== Inventory List ===\n";
    cout << left << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(12) << "Quantity"
         << setw(15) << "Price"
         << "\n";
    cout << string(70, '-') << "\n";

    for (int i = 0; i < currentProduct; i++)
    {
        cout << left << setw(8) << manager[i].getId()
             << setw(20) << manager[i].getName()
             << setw(15) << manager[i].getCategory()
             << setw(12) << manager[i].getQuantity()
             << setw(15) << fixed << setprecision(2) << manager[i].getPrice()
             << "\n";
    }
}

// Check whether a product ID already exists.
bool checkId(inventory_management manager[], int currentProduct, int id)
{
    for (int i = 0; i < currentProduct; i++)
    {
        if (manager[i].getId() == id)
            return true;
    }
    return false;
}

// Save inventory data to a file.
void saveData(inventory_management manager[], int currentProduct)
{
    ofstream file("Inventory.txt");
    for (int x = 0; x < currentProduct; x++)
    {
        file << "==============================\n";
        file << " Product " << x + 1 << "\n";
        file << "------------------------------\n";
        file << " ID       : " << manager[x].getId() << "\n";
        file << " Name     : " << manager[x].getName() << "\n";
        file << " Category : " << manager[x].getCategory() << "\n";
        file << " Quantity : " << manager[x].getQuantity() << "\n";
        file << " Price    : " << fixed << setprecision(2) << manager[x].getPrice() << "\n";
        file << "==============================\n\n";
    }

    file.close();
    cout << "\n  [SUCCESS] All products saved to \"Inventory.txt\" successfully!\n";
}

// Load and display saved inventory data.
void loadData()
{
    cout << "\nShowing full Inventory from file:\n";
    ifstream outFile("Inventory.txt");
    if (!outFile)
    {
        cout << "\n  [ERROR] Cannot open Inventory.txt for reading.\n";
        return;
    }

    string st;
    while (getline(outFile, st))
    {
        cout << st << endl;
    }

    outFile.close();
    cout << "\n  [SUCCESS] Inventory loaded from file.\n";
}
