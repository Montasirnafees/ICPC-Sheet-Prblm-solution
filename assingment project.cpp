#include <bits/stdc++.h>

using namespace std;
class InvalidInputException {
private:
    string msg;
public:
    InvalidInputException(string m) : msg(m) {}
    string getMessage() const { return msg; }
};

class FileErrorException {
private:
    string msg;
public:
    FileErrorException(string m) : msg(m) {}
    string getMessage() const { return msg; }
};

// check if string contains only spaces or is completely empty
bool isValidName(const string &name) {
    if (name.empty()) return false;

    // Check if the name contains at least one non-space character
    bool hasChar = false;
    for (char c : name) {
        if (!isspace(c)) {
            hasChar = true;
            break;
        }
    }
    return hasChar;
}

// Loop wrapper to ensure user enters a valid non-empty product name
string getValidProductName() {
    string nameInput;
    while (true) {
        cout << "Enter Name: ";
        getline(cin, nameInput);

        if (isValidName(nameInput)) {
            break; // Break loop only if name has actual valid characters
        }
        cout << "\n[ERROR] Name cannot be blank or empty! Please enter a valid name.\n";
    }
    return nameInput;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidFutureDate(const string &dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
        return false;
    }

    int year, month, day;
    try {
        year = stoi(dateStr.substr(0, 4));
        month = stoi(dateStr.substr(5, 2));
        day = stoi(dateStr.substr(8, 2));
    } catch (...) {
        return false;
    }

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    if (day > daysInMonth[month - 1]) return false;

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    if (year < currentYear) return false;
    if (year == currentYear) {
        if (month < currentMonth) return false;
        if (month == currentMonth) {
            if (day < currentDay) return false;
        }
    }

    return true;
}

string getValidExpiryDate() {
    string dateInput;
    while (true) {
        cout << "Enter Expiry Date (YYYY-MM-DD): ";
        cin >> dateInput;

        if (isValidFutureDate(dateInput)) {
            break;
        }
        cout << "\n[ERROR] Wrong date entered! Please enter a valid current/future expiry date.\n";
    }
    return dateInput;
}


class Product {
private:
    int id;
    string name;
    double quantity;
    double price;
    string unit;

public:
    Product() {
        id = 0;
        name = "Unknown";
        quantity = 0.0;
        price = 0.0;
        unit = "Pcs";
    }

    Product(int id, string name, double quantity, double price, string unit) {
        if (quantity < 0) throw InvalidInputException("Error: Quantity cannot be negative!");
        if (price <= 0) throw InvalidInputException("Error: Price must be greater than zero!");

        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
        this->unit = unit;
    }

    virtual ~Product() {}

    int getId() const { return id; }
    string getName() const { return name; }
    double getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getUnit() const { return unit; }

    void setQuantity(double q) {
        if (q < 0) throw InvalidInputException("Error: Quantity cannot be negative!");
        quantity = q;
    }
    void setPrice(double p) {
        if (p <= 0) throw InvalidInputException("Error: Price must be greater than zero!");
        price = p;
    }

    void addStock(double q) {
        quantity += q;
    }

    virtual void display() const = 0;
    virtual string getType() const = 0;
    virtual string serialize() const = 0;

    friend void applyDiscount(Product &p, double percent);
};

void applyDiscount(Product &p, double percent) {
    if (percent < 0 || percent > 100) {
        throw InvalidInputException("Error: Invalid discount percentage (0-100 required)!");
    }
    p.price = p.price - (p.price * percent / 100.0);
}

// ================================================================
// DERIVED CLASS 1: PerishableProduct
// ================================================================
class PerishableProduct : public Product {
private:
    string expiryDate;

public:
    PerishableProduct() : Product(), expiryDate("N/A") {}

    PerishableProduct(int id, string name, double quantity, double price, string unit, string expiry)
        : Product(id, name, quantity, price, unit), expiryDate(expiry) {}

    void display() const override {
        cout << left << setw(8) << getId() << setw(20) << getName()
             << fixed << setprecision(2) << setw(6) << getQuantity() << " " << setw(5) << getUnit()
             << "Tk " << setw(10) << getPrice()
             << "Type: Perishable [Exp: " << expiryDate << "]\n";
    }

    string getType() const override { return "PERISHABLE"; }

    string serialize() const override {
        return "PERISHABLE|" + to_string(getId()) + "|" + getName() + "|" +
               to_string(getQuantity()) + "|" + to_string(getPrice()) + "|" + getUnit() + "|" + expiryDate;
    }
};

class NonPerishableProduct : public Product {
private:
    int warrantyMonths;

public:
    NonPerishableProduct() : Product(), warrantyMonths(0) {}

    NonPerishableProduct(int id, string name, double quantity, double price, string unit, int warranty)
        : Product(id, name, quantity, price, unit), warrantyMonths(warranty) {}

    void display() const override {
        if (getUnit() == "Pcs" || getUnit() == "Pkt") {
            cout << left << setw(8) << getId() << setw(20) << getName()
                 << setw(6) << static_cast<int>(getQuantity()) << " " << setw(5) << getUnit()
                 << "Tk " << setw(10) << fixed << setprecision(2) << getPrice()
                 << "Type: Non-Perishable [Warranty: " << warrantyMonths << " Months]\n";
        } else {
            cout << left << setw(8) << getId() << setw(20) << getName()
                 << fixed << setprecision(2) << setw(6) << getQuantity() << " " << setw(5) << getUnit()
                 << "Tk " << setw(10) << getPrice()
                 << "Type: Non-Perishable [Warranty: " << warrantyMonths << " Months]\n";
        }
    }

    string getType() const override { return "NON_PERISHABLE"; }

    string serialize() const override {
        return "NON_PERISHABLE|" + to_string(getId()) + "|" + getName() + "|" +
               to_string(getQuantity()) + "|" + to_string(getPrice()) + "|" + getUnit() + "|" + to_string(warrantyMonths);
    }
};


class Inventory {
private:
    Product* products[100];
    int count;

public:
    Inventory() {
        count = 0;
    }

    ~Inventory() {
        for (int i = 0; i < count; i++) {
            delete products[i];
        }
    }

    int search(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i]->getId() == id) {
                return i;
            }
        }
        return -1;
    }

    Product* getProduct(int index) {
        if (index >= 0 && index < count) {
            return products[index];
        }
        return nullptr;
    }

    void mergeStock(int index, double addQty, double newPrice) {
        products[index]->addStock(addQty);
        products[index]->setPrice(newPrice);
        cout << "Stock successfully added to the existing product \"" << products[index]->getName() << "\".\n";
    }

    void addProduct(Product* p) {
        if (count >= 100) {
            delete p;
            throw InvalidInputException("Error: Inventory is full!");
        }

        int existingIndex = search(p->getId());
        if (existingIndex != -1) {
            delete p;
            throw InvalidInputException("Error: Product ID already exists!");
        }

        products[count] = p;
        count++;
        cout << "Product added successfully!\n";
    }

    void displayAll() const {
        if (count == 0) {
            cout << "\nNo records found in inventory.\n";
            return;
        }
        cout << "\n----------------------------------------------------------------------------------------------------\n";
        cout << left << setw(8) << "ID" << setw(20) << "Name" << setw(12) << "Quantity" << setw(15) << "Price" << "Details\n";
        cout << "----------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < count; i++) {
            products[i]->display();
        }
        cout << "----------------------------------------------------------------------------------------------------\n";
    }

    void deleteProduct(int id) {
        int index = search(id);
        if (index == -1) throw InvalidInputException("Error: Product not found!");

        delete products[index];

        for (int i = index; i < count - 1; i++) {
            products[i] = products[i + 1];
        }
        count--;
        cout << "Product with ID " << id << " deleted successfully.\n";
    }

    void discountProduct(int id, double percent) {
        int index = search(id);
        if (index == -1) throw InvalidInputException("Error: Product not found!");
        applyDiscount(*products[index], percent);
        cout << "Discount applied! New Price: Tk " << products[index]->getPrice() << "\n";
    }

    void saveToFile(string filename) {
        ofstream outFile(filename);
        if (!outFile) throw FileErrorException("Error: Could not open file for writing!");

        for (int i = 0; i < count; i++) {
            outFile << products[i]->serialize() << "\n";
        }
        outFile.close();
    }

    void loadFromFile(string filename) {
        ifstream inFile(filename);
        if (!inFile) return;

        for (int i = 0; i < count; i++) {
            delete products[i];
        }
        count = 0;

        string line;
        while (getline(inFile, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string type, idStr, name, qtyStr, priceStr, unit, extra;

            getline(ss, type, '|');
            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, qtyStr, '|');
            getline(ss, priceStr, '|');
            getline(ss, unit, '|');
            getline(ss, extra, '|');

            int id = stoi(idStr);
            double qty = stod(qtyStr);
            double price = stod(priceStr);

            if (type == "PERISHABLE") {
                products[count++] = new PerishableProduct(id, name, qty, price, unit, extra);
            } else if (type == "NON_PERISHABLE") {
                products[count++] = new NonPerishableProduct(id, name, qty, price, unit, stoi(extra));
            }
        }
        inFile.close();
    }
};


int main() {
    Inventory inv;
    inv.loadFromFile("inventory.txt"); //Notepad file theke purono
                //shob product instantly memory-te load kora holo.

    cout << "Welcome to the Inventory Management System!\n";

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Delete Product\n";
        cout << "4. Apply Discount\n";
        cout << "5. Save and Exit\n";
        cout << "================\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            string discard;
            cin >> discard;
            cout << "Invalid input! Please select numbers 1-5.\n";
            continue;
        }

        try {
            if (choice == 1) {
                int id;
                cout << "Enter Product ID: "; cin >> id;

                int existingIdx = inv.search(id);

                if (existingIdx != -1) {
                    Product* existingProd = inv.getProduct(existingIdx);
                    cout << "\n[ALERT] ID " << id << " is registered to \"" << existingProd->getName() << "\".\n";
                    cout << "1. Add stock to \"" << existingProd->getName() << "\"\n";
                    cout << "2. Return to Main Menu\n";
                    cout << "Enter choice: ";

                    int subChoice;
                    cin >> subChoice;

                    if (subChoice == 1) {
                        double addQty;
                        double latestPrice;
                        cout << "Enter Quantity to add (" << existingProd->getUnit() << "): "; cin >> addQty;
                        cout << "Enter current Price per " << existingProd->getUnit() << ": "; cin >> latestPrice;

                        inv.mergeStock(existingIdx, addQty, latestPrice);
                    } else {
                        cout << "Returning to Main Menu...\n";
                    }
                    continue;
                }
                double qty;
                int type, unitChoice;
                string name, extra, unit = "Pcs";
                double price;

                // Clears newline buffer left by previous inputs before getline
                cin.ignore();

                // FIXED: Now uses safe Name Input validation
                name = getValidProductName();

                cout << "Type (1 for Perishable, 2 for Non-Perishable): "; cin >> type;

                cout << "\nSelect Unit of Measurement:\n";
                cout << "1. KG (Weight)\n";
                cout << "2. Ltr (Volume)\n";
                cout << "3. Pcs (Pieces)\n";
                cout << "4. Pkt (Packet)\n";
                cout << "Enter choice: ";
                cin >> unitChoice;

                if (unitChoice == 1) unit = "KG";
                else if (unitChoice == 2) unit = "Ltr";
                else if (unitChoice == 3) unit = "Pcs";
                else if (unitChoice == 4) unit = "Pkt";
                else throw InvalidInputException("Error: Invalid Unit Selection!");

                if (type == 1) {
                    cout << "Enter Quantity in " << unit << ": "; cin >> qty;
                    cout << "Enter Price per " << unit << ": "; cin >> price;
                    extra = getValidExpiryDate();
                    inv.addProduct(new PerishableProduct(id, name, qty, price, unit, extra));
                } else if (type == 2) {
                    cout << "Enter Quantity in " << unit << ": "; cin >> qty;
                    cout << "Enter Price per " << unit << ": "; cin >> price;
                    int warranty;
                    cout << "Enter Warranty (Months): "; cin >> warranty;
                    inv.addProduct(new NonPerishableProduct(id, name, qty, price, unit, warranty));
                } else {
                    throw InvalidInputException("Error: Invalid Product Type selected!");
                }

            } else if (choice == 2) {
                inv.displayAll();

            } else if (choice == 3) {
                int id;
                cout << "Enter Product ID to delete: "; cin >> id;
                inv.deleteProduct(id);

            } else if (choice == 4) {
                int id;
                double percent;
                cout << "Enter Product ID: "; cin >> id;
                cout << "Enter Discount Percentage: "; cin >> percent;
                inv.discountProduct(id, percent);

            } else if (choice == 5) {
                inv.saveToFile("inventory.txt");
                cout << "Data saved. Thank you!\n";
                break;
            } else {
                cout << "Invalid choice! Please select between 1 and 5.\n";
            }
        }
        catch (const InvalidInputException &e) {
            cout << e.getMessage() << "\n";
        } catch (const FileErrorException &e) {
            cout << e.getMessage() << "\n";
        }
    }

    return 0;
}
