#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        clearScreen();
        printHeader("TRAVEL MANAGEMENT SYSTEM");
        printMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 6)
        {
            printError("Invalid Choice! Enter choice (1-6)");
        }
        
        else
        {
            switch (choice)
            {
            case 1:
                clearScreen();
                viewPackages();
                waitForEnter();
                break;

            case 2:
                bookPackage();
                waitForEnter();
                break;

            case 3:
                viewBookings();
                waitForEnter();
                break;

            case 4:
                editBookings();
                waitForEnter();
                break;

            case 5:
                deleteBooking();
                waitForEnter();
                break;
            case 6:
                cout << "Exiting the Program..." << endl;
                cout << "Thank You!" << endl;
                cout << "----------------------------------------" << endl;
                cout << endl;
                break;
            }
        }

    } while (choice != 6);

    return 0;
}