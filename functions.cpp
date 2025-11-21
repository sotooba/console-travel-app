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

    cout << left << setw(5) << 1 << setw(15) << "Islamabad" << setw(15) << 6000 << endl;     
    cout << left << setw(5) << 2 << setw(15) << "Peshawar" << setw(15) << 8000 << endl;     
    cout << left << setw(5) << 3 << setw(15) << "Karachi" << setw(15) << 5000 << endl;     
    cout << left << setw(5) << 4 << setw(15) << "Lahore" << setw(15) << 7000 << endl;     
    cout << left << setw(5) << 5 << setw(15) << "Quetta" << setw(15) << 6000 << endl;     
    cout << left << setw(5) << 6 << setw(15) << "Multan" << setw(15) << 7000 << endl;     

    cout << "----------------------------------------\n";
}