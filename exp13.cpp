#include <iostream>
#include <stdexcept>  // for standard exception classes
#include <string>
using namespace std;

// -------------------------
// Custom Exception Class
// -------------------------
class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Age! Age must be greater than 0.";
    }
};

// -------------------------
// Person Class
// -------------------------
class Person {
    string name;
    int age;

public:
    Person(string n, int a) {
        if (a <= 0) {
            // Throw custom exception if age is invalid
            throw InvalidAgeException();
        }
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// -------------------------
// Function to demonstrate division with exception handling
// -------------------------
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero error!");
    }
    return numerator / denominator;
}

// -------------------------
// Main Function
// -------------------------
int main() {
    cout << "=== Division Example ===" << endl;

    try {
        double a, b;
        cout << "Enter two numbers (numerator and denominator): ";
        cin >> a >> b;

        double result = divide(a, b);
        cout << "Result = " << result << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    cout << "\n=== Person Age Validation Example ===" << endl;

    try {
        string name;
        int age;
        cout << "Enter person's name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        Person p(name, age);
        p.display();
    }
    catch (const InvalidAgeException& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    cout << "\nProgram ended successfully." << endl;
    return 0;
}

