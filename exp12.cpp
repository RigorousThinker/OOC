#include <iostream>
#include <fstream>  // for file handling
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    // Step 1: Get user input
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    // Step 2: Write data to a file
    ofstream outFile("user_data.txt");  // create or open file for writing

    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << name << endl;
    outFile << age << endl;
    outFile.close();

    cout << "\nData written to 'user_data.txt' successfully!\n";

    // Step 3: Read data back from the file
    ifstream inFile("user_data.txt");  // open file for reading

    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    string readName;
    int readAge;

    getline(inFile, readName);
    inFile >> readAge;

    inFile.close();

    // Step 4: Display data read from file
    cout << "\nData read from file:\n";
    cout << "Name: " << readName << endl;
    cout << "Age: " << readAge << endl;

    return 0;
}

