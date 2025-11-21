#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;


struct Booking{
    int id;
    string name;
    string phone;
    int package;
    int travelers;
    int cost;
};

// string packageDestination[] = {"Islamabad", 
//                                 "Peshawar", 
//                                 "Faislabad", 
//                                 "Karachi", 
//                                 "Gilgit", 
//                                 "Multan", 
//                                 "Quetta", 
//                                 "Lahore"
//                             };


// int packagesCost[] = {6000, 8000, 6500, 5000, 4000, 6500, 7000, 7500};

void clearScreen();
void printHeader(string prompt);
void printMenu();
void waitForEnter();
void errorMessage(string prompt);
void viewPackages();
void bookPackage();


#endif
