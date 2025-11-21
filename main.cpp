#include <iostream>

#include "functions.h"
using namespace std;

int main()
{
    
    int choice;

    do{
    
    clearScreen();
    printHeader("TRAVEL MANAGEMENT SYSTEM");

    cout << "1. View Travel Packages" << endl;
    cout << "2. Book a Travel Package" << endl;
    cout << "3. View Bookings" << endl;
    cout << "4. Edit a Booking" << endl;
    cout << "5. Delete a Booking" << endl;
    cout << "6. Exit" << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice < 1 || choice > 6){
        cout << "Invalid Choice! Enter choice between 1-6." << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;
        
        waitForEnter();
    }
    else{
        switch (choice){
            case 1: 
                viewPackages();
                waitForEnter();
                break;
                
            case 2: 
                cout << "two" << endl;
                waitForEnter();
                break;
                
            case 3:
                cout << "three" << endl;
                waitForEnter();
                break;
                
            case 4:
                cout << "four" << endl;
                waitForEnter();
                break;
                
            case 5:
                cout << "five" << endl;
                waitForEnter();
                break;
            case 6:
                cout << "Exiting the Program..." << endl;
                cout << "----------------------------------------" << endl;
                cout << endl;
                break;
            }               
    }
    
    } while (choice != 6);      
        
    return 0;
}