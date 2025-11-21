#include <iomanip>
#include <iostream>
#include <string>

#include "functions.h"
using namespace std;


void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}


void printHeader(string prompt)
{
    cout << "========================================" << endl;
    cout << "\t" << prompt << endl;
    cout << "========================================" << endl;
}


void printMenu()
{
    cout << "1. View Travel Packages" << endl;
    cout << "2. Book a Travel Package" << endl;
    cout << "3. View Bookings" << endl;
    cout << "4. Edit a Booking" << endl;
    cout << "5. Delete a Booking" << endl;
    cout << "6. Exit" << endl;
    cout << "----------------------------------------" << endl;
}


void waitForEnter()
{
    cout << "Press Enter key to continue: ";
    cin.ignore();
    cin.get(); 
}


void viewPackages()
{
    clearScreen();
    printHeader("AVAILABLE TRAVEL PACKAGES");

    cout << left << setw(5) << "ID" << setw(15) << "Destination" << setw(15) << "Cost/Person" << endl;
    cout << "----------------------------------------\n";

    cout << left << setw(5) << 1 << setw(15) << "Islamabad" << "Rs. "  << setw(15) << 6000 << endl;     
    cout << left << setw(5) << 2 << setw(15) << "Peshawar" << "Rs. "  << setw(15) << 8000 << endl;     
    cout << left << setw(5) << 3 << setw(15) << "Faislabad" << "Rs. "  << setw(15) << 6500 << endl;     
    cout << left << setw(5) << 4 << setw(15) << "Karachi" << "Rs. "  << setw(15) << 5000 << endl;     
    cout << left << setw(5) << 5 << setw(15) << "Gilgit" << "Rs. "  << setw(15) << 4000 << endl;     
    cout << left << setw(5) << 6 << setw(15) << "Multan" << "Rs. "  << setw(15) << 6500 << endl;     
    cout << left << setw(5) << 7 << setw(15) <<"Quetta"  << "Rs. "  << setw(15) << 7000 << endl;     
    cout << left << setw(5) << 8 << setw(15) << "Lahore" << "Rs. "  << setw(15) << 7500 << endl;     

    cout << "----------------------------------------\n";
}