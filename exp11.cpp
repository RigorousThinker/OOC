#include <iostream>
#include <string>
using namespace std;

// -------- Base class --------
class Employee {
protected:
    string name;

public:
    Employee(string n) : name(n) {}

    // Virtual function - allows polymorphism
    virtual double calculateSalary() const {
        return 0.0;
    }

    // Virtual destructor (important for proper cleanup)
    virtual ~Employee() {}

    // Display function to show name and salary
    virtual void display() const {
        cout << "Employee: " << name
             << ", Salary: $" << calculateSalary() << endl;
    }
};

// -------- Derived class 1: SalariedEmployee --------
class SalariedEmployee : public Employee {
    double monthlySalary;

public:
    SalariedEmployee(string n, double salary)
        : Employee(n), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }
};

// -------- Derived class 2: HourlyEmployee --------
class HourlyEmployee : public Employee {
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee(string n, double hours, double rate)
        : Employee(n), hoursWorked(hours), hourlyRate(rate) {}

    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }
};

// -------- Derived class 3: CommissionedEmployee --------
class CommissionedEmployee : public Employee {
    double baseSalary;
    double sales;
    double commissionRate;

public:
    CommissionedEmployee(string n, double base, double sale, double rate)
        : Employee(n), baseSalary(base), sales(sale), commissionRate(rate) {}

    double calculateSalary() const override {
        return baseSalary + (sales * commissionRate);
    }
};

// -------- Main Function --------
int main() {
    // Create different employee types using pointers to base class
    Employee* e1 = new SalariedEmployee("Alice", 3000.0);
    Employee* e2 = new HourlyEmployee("Bob", 120, 15.0); // 120 hours @ $15/hr
    Employee* e3 = new CommissionedEmployee("Charlie", 2000.0, 5000.0, 0.10); // 10% commission

    // Demonstrate polymorphism
    cout << "Employee Salaries:\n";
    e1->display();
    e2->display();
    e3->display();

    // Clean up
    delete e1;
    delete e2;
    delete e3;

    return 0;
}

