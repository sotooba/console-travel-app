#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "functions.h"
using namespace std;

string packageDestination[] = {"Islamabad", 
                                "Peshawar", 
                                "Faislabad", 
                                "Karachi", 
                                "Gilgit", 
                                "Multan", 
                                "Quetta", 
                                "Lahore"
                            };

                            
int packagesCost[] = {6000, 8000, 6500, 5000, 4000, 6500, 7000, 7500};

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


void errorMessage(string prompt)
{
    cout << prompt << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    waitForEnter();
}


void viewPackages()
{
    printHeader("AVAILABLE TRAVEL PACKAGES");

    cout << left << setw(5) << "ID" << setw(15) << "Destination" << setw(15) << "Cost/Person" << endl;
    cout << "----------------------------------------\n";

    for (int i = 0; i < 8; i++){
        cout << left << setw(5) << i + 1 << setw(15) << packageDestination[i] << "Rs. " << setw(15) << packagesCost[i] << endl;
    }
    
    cout << "----------------------------------------\n";
}

void bookPackage()
{
    clearScreen();
    printHeader("BOOK A PACKAGE");

    Booking b;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, b.name);

    cout << "Enter mobile number: ";
    getline(cin, b.phone);
    cout << endl;

    viewPackages();
    cout << endl;

    do
    {
        cout << "Select the package (1-8): ";
        cin >> b.package;

        if (b.package < 1 || b.package > 8)
        {
            errorMessage("Invalid Choice! Enter choice between 1-8");
            cout << endl;
        }

    } while (b.package < 1 || b.package > 8);

    do{
        cout << "Enter number of Travelers: ";
        cin >> b.travelers;
        if (b.travelers < 1){
            errorMessage("Travelers can not be less than 1.");
            cout << endl;
        }

    } while (b.travelers < 1);

    b.cost = b.travelers * packagesCost[b.package - 1];

    int last_id = 0;

    // Open the file in read mode
    ifstream infile("bookings.txt");

    if (!infile){
        last_id = 0;
    }
    else{
       int id;
       string temp_discard;
       while(infile >> id){
            last_id = id;
            getline(infile, temp_discard);
       }
        infile.close();
    }

    b.id = last_id + 1;

    // Open the file in append mode
    // Save Bookings
    ofstream outfile("bookings.txt", ios::app);

    if (!outfile){
        errorMessage("Error opening file!");
        return;
    }

    outfile << b.id << " " << b.name << " " << b.phone <<  " " << b.package << " " << b.travelers << " " << b.cost << endl;

    outfile.close();    

    // Print the summary
    clearScreen();
    cout << "Booking Saved successfully!" << endl;
    printHeader("BOOKING CONFIRMATION");

    cout << left << setw(17) << "Booking ID:" << b.id << endl;
    cout << left << setw(17) << "Name:" << b.name << endl;
    cout << left << setw(17) << "Mobile Number:" << b.phone << endl;
    switch(b.package){
        case 1:
            cout << left << setw(17) << "Destination:" << packageDestination[0] << endl;
            break;
        case 2:
            cout << left << setw(17) << "Destination:" << packageDestination[1] << endl;
            break;
        case 3:
            cout << left << setw(17) << "Destination:" << packageDestination[2] << endl;
            break;
        case 4:
            cout << left << setw(17) << "Destination:" << packageDestination[3] << endl;
            break;
        case 5:
            cout << left << setw(17) << "Destination:" << packageDestination[4] << endl;
            break;
        case 6:
            cout << left << setw(17) << "Destination:" << packageDestination[5] << endl;
            break;
        case 7:
            cout << left << setw(17) << "Destination:" << packageDestination[6] << endl;
            break;
        case 8:
            cout << left << setw(17) << "Destination:" << packageDestination[7] << endl;
            break;
        
    }
    
    cout << left << setw(17) << "Travelers:" << b.travelers << endl;
    cout << left << setw(17) << "Total Cost:" << b.cost << endl;
    cout << "----------------------------------------\n";
}

    