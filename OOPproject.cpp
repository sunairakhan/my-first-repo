#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    int odometer_reading;

public:
    Car(string make, string model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->odometer_reading = 0;
    }

    string get_descriptive_name() {
        return to_string(year) + " " + make + " " + model;
    }

    void read_odometer(ofstream& outFile) {
        outFile << "This car has " << odometer_reading << " miles on it." << endl;
    }

    void update_odometer(int mileage, ofstream& outFile) {
        if (mileage >= odometer_reading) {
            odometer_reading = mileage;
            outFile << "Odometer reading updated successfully." << endl;
        } else {
            outFile << "You can't roll back an odometer!" << endl;
        }
    }

    void increment_odometer(int miles, ofstream& outFile) {
        odometer_reading += miles;
        outFile << "Odometer reading incremented successfully." << endl;
    }
};

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");
    string make, model;
    int year, choice, mileage;

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    getline(inFile, make);
    getline(inFile, model);
    inFile >> year;

    Car my_car(make, model, year);

    while (true) {
        outFile << "\nMenu:\n";
        outFile << "1. View descriptive name\n";
        outFile << "2. Read odometer\n";
        outFile << "3. Update odometer\n";
        outFile << "4. Increment odometer\n";
        outFile << "5. Exit\n";
        outFile << "Enter your choice: ";
        inFile >> choice;

        switch (choice) {
            case 1:
                outFile << "Descriptive Name: " << my_car.get_descriptive_name() << endl;
                break;
            case 2:
                my_car.read_odometer(outFile);
                break;
            case 3:
                outFile << "Enter new odometer reading: ";
                inFile >> mileage;
                my_car.update_odometer(mileage, outFile);
                break;
            case 4:
                outFile << "Enter miles to increment: ";
                inFile >> mileage;
                my_car.increment_odometer(mileage, outFile);
                break;
            case 5:
                outFile << "Exiting program.\n";
                inFile.close();
                outFile.close();
                return 0;
            default:
                outFile << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
