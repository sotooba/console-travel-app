#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;


struct Booking{
    int id;
    string name;
    string phone;
    string destination;
    int package;
    int travelers;
    double cost;
};


void clearScreen();
void printHeader(string prompt);
void printMenu();
void waitForEnter();
void printError(string prompt);
void viewPackages();
void bookPackage();
string normalizePhone(const string &number);
bool isValidNumber(const string &number);
void printReciept(int id, string name, string mobile, int package, int travelers, double cost);
void printTableHeader();
void loadBookings(Booking bookings[], int &counter);
void viewBookings();
void editBookings();


#endif
