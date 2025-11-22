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
            menuControl(choice);
        }

    } while (choice != 6);

    return 0;
}