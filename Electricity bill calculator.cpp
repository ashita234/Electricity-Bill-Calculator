/*
    Project Title : Electricity Bill Calculator
    Student Name  : Ashita
    Student ID    : 25BCA20027
    Language      : C++
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to calculate energy charge based on slab rates
// 0-100: 1.50 | 101-200: 2.50 | 201-400: 4.00 | 400+: 6.00
double calculateEnergyCharge(int units) {
    double charge = 0.0;

    if (units > 400) {
        charge += (units - 400) * 6.00;
        charge += 200 * 4.00;
        charge += 100 * 2.50;
        charge += 100 * 1.50;
    } else if (units > 200) {
        charge += (units - 200) * 4.00;
        charge += 100 * 2.50;
        charge += 100 * 1.50;
    } else if (units > 100) {
        charge += (units - 100) * 2.50;
        charge += 100 * 1.50;
    } else {
        charge += units * 1.50;
    }
    return charge;
}

int main() {
    string name;
    int previousReading, currentReading;

    // Input section
    cout << "Enter consumer name: ";
    getline(cin, name);

    cout << "Enter previous meter reading: ";
    if (!(cin >> previousReading) || previousReading < 0) {
        cout << "Error: Invalid previous reading." << endl;
        return 1;
    }

    cout << "Enter current meter reading: ";
    if (!(cin >> currentReading) || currentReading < 0) {
        cout << "Error: Invalid current reading." << endl;
        return 1;
    }

    // Validate readings
    if (currentReading < previousReading) {
        cout << "Error: Current reading must be greater than or equal to previous reading." << endl;
        return 1;
    }

    // Calculate units consumed
    int unitsConsumed = currentReading - previousReading;

    // Calculate charges
    double energyCharge = calculateEnergyCharge(unitsConsumed);
    double fixedCharge = 50.00;
    double surcharge = 0.05 * energyCharge;
    double totalBill = energyCharge + fixedCharge + surcharge;

    // Output section
    cout << fixed << setprecision(2);
    cout << "\n--- ELECTRICITY BILL ---" << endl;
    cout << "Consumer Name: " << name << endl;
    cout << "Units Consumed: " << unitsConsumed << " units" << endl;
    cout << "Energy Charge: Rs. " << energyCharge << endl;
    cout << "Fixed Charge: Rs. " << fixedCharge << endl;
    cout << "Surcharge (5%): Rs. " << surcharge << endl;
    cout << "Total Bill: Rs. " << totalBill << endl;
    cout << "-------------------------------" << endl;

    return 0;
}
