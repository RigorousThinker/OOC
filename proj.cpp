// simple_bill_employee_bills.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// File formats:
// customers.txt: id,mobile,name,email
// bills.txt:     id,month,year,prevUnit,curUnit,total,paid(0/1)

struct Customer {
    int id = 0;
    long long mobile = 0;
    string name;
    string email;
};

struct Bill {
    int id = 0;
    string month;
    int year = 0;
    int prevU = 0;
    int curU = 0;
    double total = 0.0;
    bool paid = false;
};

void ensureFiles() {
    ifstream f("customers.txt"); if (!f.is_open()) ofstream("customers.txt").close(); else f.close();
    ifstream g("bills.txt");     if (!g.is_open())     ofstream("bills.txt").close();     else g.close();
}

vector<Customer> loadCustomers() {
    vector<Customer> res;
    ifstream fin("customers.txt");
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Customer c;
        string token;
        if (!getline(ss, token, ',')) continue;
        c.id = stoi(token);
        if (!getline(ss, token, ',')) continue;
        c.mobile = stoll(token);
        if (!getline(ss, c.name, ',')) continue;
        if (!getline(ss, c.email, ',')) c.email = ""; // last field may not end with comma
        res.push_back(c);
    }
    return res;
}

vector<Bill> loadBills() {
    vector<Bill> res;
    ifstream fin("bills.txt");
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Bill b;
        string token;
        if (!getline(ss, token, ',')) continue; b.id = stoi(token);
        if (!getline(ss, b.month, ',')) continue;
        if (!getline(ss, token, ',')) continue; b.year = stoi(token);
        if (!getline(ss, token, ',')) continue; b.prevU = stoi(token);
        if (!getline(ss, token, ',')) continue; b.curU = stoi(token);
        if (!getline(ss, token, ',')) continue; b.total = stod(token);
        if (!getline(ss, token, ',')) { b.paid = false; }
        else b.paid = (stoi(token) != 0);
        res.push_back(b);
    }
    return res;
}

void appendCustomer(const Customer &c) {
    ofstream fout("customers.txt", ios::app);
    fout << c.id << ',' << c.mobile << ',' << c.name << ',' << c.email << '\n';
}

void appendBill(const Bill &b) {
    ofstream fout("bills.txt", ios::app);
    fout << b.id << ',' << b.month << ',' << b.year << ',' << b.prevU << ',' << b.curU << ','
         << fixed << setprecision(2) << b.total << ',' << (b.paid ? 1 : 0) << '\n';
}

double computeCharge(double used) {
    if (used <= 50) return used * 2.0;
    if (used <= 100) return used * 2.5;
    if (used <= 150) return used * 3.0;
    return used * 5.0;
}

void addCustomer() {
    Customer c;
    cout << "Consumer ID: "; cin >> c.id;
    cout << "Mobile: "; cin >> c.mobile;
    cin.ignore(); // clear newline
    cout << "Name: "; getline(cin, c.name);
    cout << "Email: "; cin >> c.email;
    appendCustomer(c);
    cout << "Customer saved.\n";
}

void calculateBill() {
    Bill b;
    cout << "Consumer ID: "; cin >> b.id;
    cout << "Month (e.g. jan): "; cin >> b.month;
    cout << "Year: "; cin >> b.year;
    cout << "Previous unit: "; cin >> b.prevU;
    cout << "Current unit: "; cin >> b.curU;
    double used = fabs(b.curU - b.prevU);
    b.total = computeCharge(used) + 30.0; // fixed charge
    b.paid = false;
    appendBill(b);
    cout << "Bill saved. Total = Rs. " << fixed << setprecision(2) << b.total << '\n';
}

void viewBillsForCustomer(int cid) {
    vector<Bill> bills = loadBills();
    bool found = false;
    cout << "\nBills for customer " << cid << ":\n";
    cout << left << setw(8) << "Month" << setw(6) << "Year" << setw(8) << "Prev" << setw(8) << "Cur"
         << setw(10) << "Total" << setw(8) << "Status" << '\n';
    cout << string(56, '-') << '\n';
    for (const auto &b : bills) {
        if (b.id == cid) {
            found = true;
            cout << left << setw(8) << b.month << setw(6) << b.year << setw(8) << b.prevU << setw(8) << b.curU
                 << setw(10) << fixed << setprecision(2) << b.total << setw(8) << (b.paid ? "PAID" : "UNPAID") << '\n';
        }
    }
    if (!found) cout << "No bills found for this customer.\n";
}

void employeeViewAll() {
    vector<Customer> customers = loadCustomers();
    if (customers.empty()) { cout << "No customers available.\n"; return; }

    cout << left << setw(6) << "ID" << setw(15) << "Mobile" << setw(25) << "Name" << setw(30) << "Email" << '\n';
    cout << string(76, '-') << '\n';
    for (const auto &c : customers) {
        cout << left << setw(6) << c.id << setw(15) << c.mobile << setw(25) << c.name << setw(30) << c.email << '\n';
    }

    // Now allow employee to pick a customer to view bills
    cout << "\nEnter customer ID to view bills (0 to return): ";
    int cid; cin >> cid;
    if (cid == 0) return;
    // check if customer exists
    bool exists = false;
    for (const auto &c : customers) if (c.id == cid) { exists = true; break; }
    if (!exists) { cout << "Customer ID not found.\n"; return; }
    viewBillsForCustomer(cid);
}

int main() {
    ensureFiles();
    while (true) {
        cout << "\n=== SIMPLE BILL SYSTEM ===\n";
        cout << "1. Register Customer\n2. Calculate Bill\n3. View Bills (Customer)\n4. Employee Login\n5. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) break;
        if (ch == 1) addCustomer();
        else if (ch == 2) calculateBill();
        else if (ch == 3) {
            int cid; cout << "Enter consumer ID: "; cin >> cid;
            viewBillsForCustomer(cid);
        }
        else if (ch == 4) {
            cout << "Employee password: "; int pass; cin >> pass;
            if (pass == 1234) employeeViewAll();
            else cout << "Wrong password.\n";
        }
        else break;
    }
    cout << "Goodbye!\n";
    return 0;
}
