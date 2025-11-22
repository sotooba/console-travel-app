#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
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

// Maximum number of bookings
const int Maxbookings = 20;

// Function to clear the screen, for formatting purpose.
void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}


// Function to print the heading
void printHeader(string prompt)
{
    cout << "========================================" << endl;
    cout << "\t" << prompt << endl;
    cout << "========================================" << endl;
}


// Function to print the main menu
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


// Function to wait for the user to press enter,
// before clearing screen
void waitForEnter()
{
    cout << "Press Enter key to continue: ";
    cin.ignore();
    cin.get();
}


// Function to print error message.
void printError(string prompt)
{
    cout << prompt << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    waitForEnter();
}


// Function to display all available packages.
void viewPackages()
{
    printHeader("AVAILABLE TRAVEL PACKAGES");

    cout << left << setw(5) << "ID" 
        << setw(15) << "Destination" 
        << setw(15) << "Cost/Person" << endl;
    cout << "----------------------------------------\n";

    for (int i = 0; i < 8; i++){
        cout << left << setw(5) << i + 1 
            << setw(15) << packageDestination[i] << "Rs. " 
            << setw(15) << packagesCost[i] << endl;
    }
    
    cout << "----------------------------------------\n";
}


// Function to validate mobile number.
string normalizePhone(const string &number)
{
    string onlydigits;
    for(char c : number){
        if (isdigit(c))
            onlydigits += c;
    }

    return onlydigits;
}


// Function to validate mobile number.
bool isValidNumber(const string &number)
{
    regex pattern("^03[0-9]{9}$");
    return regex_match(number, pattern);
}


// Function to book a package.
void bookPackage()
{
    clearScreen();
    printHeader("BOOK A PACKAGE");

    Booking b;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, b.name);

    b.name[0] = toupper(b.name[0]);

    cout << "Enter mobile number: ";
    getline(cin, b.phone);
    cout << endl;

    string cleaned = normalizePhone(b.phone);

    while(!isValidNumber(cleaned)){
        cout << endl << "Invalid Phone Number! Enter a valid Pakistani number like 03001234567.";
        cout << endl << "----------------------------------------\n";
        cout << "Enter mobile number again: ";
        getline(cin, b.phone);
        cout << endl;
        cleaned = normalizePhone(b.phone);
    }

    b.phone = cleaned;

    viewPackages();
    cout << endl;

    do
    {
        cout << "Select the package (1-8): ";
        cin >> b.package;

        if (b.package < 1 || b.package > 8)
        {
            printError("Invalid Choice! Enter choice between 1-8");
            cout << endl;
        }

    } while (b.package < 1 || b.package > 8);

    do{
        cout << "Enter number of Travelers: ";
        cin >> b.travelers;
        if (b.travelers < 1){
            printError("Travelers can not be less than 1.");
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
        printError("Error opening file!");
        return;
    }

    outfile << b.id << " " 
            << b.name << " " 
            << b.phone <<  " " 
            << b.package << " " 
            << b.travelers << " " 
            << b.cost << endl;

    outfile.close();
    printReciept(b.id, b.name, b.phone, b.package, b.travelers, b.cost);  
}


// Function to print Successfull booking summary.
void printReciept(int id, string name, string mobile, int package, int travelers, double cost){
    // Print the summary
    clearScreen();
    cout << "Booking Saved successfully!" << endl;
    printHeader("BOOKING CONFIRMATION");

    cout << left << setw(17) << "Booking ID:" << id << endl;
    cout << left << setw(17) << "Name:" << name << endl;
    cout << left << setw(17) << "Mobile Number:" << mobile << endl;
    switch(package){
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
    
    cout << left << setw(17) << "Travelers:" << travelers << endl;
    cout << left << setw(17) << "Total Cost:" << "Rs. " << cost << endl;
    cout << "----------------------------------------\n";
}


// Function to view all bookings.
void viewBookings()
{
    clearScreen();
    printHeader("ALL BOOKINGS");

    ifstream infile("bookings.txt");

    if (!infile){
        printError("Error opening file!");
        return;
    }

    // Array to hold all bookings
    Booking bookings[Maxbookings];
    int counter = 0;
    string line;

    // Read each line untill end of the file

    /* 
        Reading line by line using getline(),
        because name can have space between first & last name.
    */

    while(getline(infile, line) && counter < Maxbookings){
        
        /*
            After reading a line,
            next step is to parse the line into tokens
            e.g. id, name, phone, destination, travelers, cost.

            In order to do so,
            using string stream, so iss can read the line just like cin.
            iss is the string stream, created from a line in a file.
        */

        istringstream iss(line);

        // Variables to parse the tokens from the line
        int id, travelers;
        double cost;
        string word;         // temporary string variable
        string name = "";   // will hold full name
        string phone;       // will hold mobile number
        string destination;

        // Since ID is just a single number, read id.
        iss >> id;

        // Read name
        while(iss >> word){

            /*
                After readin id, the next token to read is name.
                Name can have spaces.
                Loop through the line and read each token until phone number.

                | Iteration | 'word'     | `isdigit(word[0])`? | `name`              | `phone`           | Action                                                   |
                | --------- | ---------- | ------------------- | ------------------- | ----------------- | -------------------------------------------------------- |
                | 1         | John       | false               | "" → "John"         | ""                | Append "John" to `name`                                  |
                | 2         | Doe        | false               | "John" → "John Doe" | ""                | Append "Doe" to `name`                                   |
                | 3         | 123456789  | true                | "John Doe"          | "" → "123456789"  | Detected phone number → assign to `phone` and break loop |

            */

            if(isdigit(word[0])){
                phone = word;
                break;
            }
            else{
                if(!name.empty())
                    name += " ";
                name += word;
            }
        }

        // Read destination, travlers, cost
        iss >> destination >> travelers >> cost;

        // Store data in an array
        bookings[counter].id = id;
        bookings[counter].name = name;
        bookings[counter].phone = phone;
        bookings[counter].destination = destination;
        bookings[counter].travelers = travelers;
        bookings[counter].cost = cost;

        // Increase the counter
        counter++;
    }

    infile.close();

    if (counter == 0){
        cout << "No bookings found!";
        cout << endl << "----------------------------------------" << endl;
        cout << endl;
        return;
    }

    cout << left << setw(5) << "ID" 
         << setw(20) << "Name" 
         << setw(20) <<"Mobile No." 
         << setw(15) << "Destination"
         << setw(15) << "Travelers"
         << setw(10) << "Total Cost";
    
    cout << endl << "---------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < counter; i++){
        cout << left << setw(5) << bookings[i].id
             << setw(20) << bookings[i].name
             << setw(20) << bookings[i].phone
             << setw(15) << bookings[i].destination
             << setw(15) << bookings[i].travelers
             << setw(10) << bookings[i].cost;
        
        cout << endl;
    }
    
    cout << endl;
}