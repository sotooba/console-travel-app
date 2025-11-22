# Travel Management System (Procedural C++)

A menu-driven console application written in **procedural C++** that allows users to manage travel packages and customer bookings using **functions, structs, arrays, and file handling**.

---

## Project Objective
This project aims to create a **Travel Management System** that enables users to:

- View travel packages  
- Book a travel package  
- View all bookings  
- Edit an existing booking  
- Delete a booking  
- Save and load data from text files  
- Use a fully procedural (non-OOP) C++ approach  

---

## Project Structure
/console-travel-app
│ <br>
├── main.cpp <br>
├── functions.cpp <br>
├── functions.h <br>
└── bookings.txt <br>

`bookings.txt` is automatically created if it does not exist.

---

## Core Features

### View Travel Packages
Shows available travel destinations and prices per person.

### Book a Package
- Enter customer name  
- Enter phone number  
- Choose a destination  
- Specify number of travelers  
- Total cost is automatically calculated  
- Booking ID is auto-generated  
- Record is saved to file  

### View All Bookings
Displays all stored bookings from file.

### Edit a Booking
Allows editing of: 
- Phone  
- Destination  
- Number of travelers  

Cost is recalculated when needed.

### Delete a Booking
Deletes a booking by Name and updates the file.

### Exit Program
Safely terminates the system.

---

## File Format (bookings.txt)

Each booking record is stored on one line seperated by space. <br>
ID | Name | Phone | Destination | Travelers | TotalCost

---

## How to Compile & Run

### Using g++:
g++ main.cpp functions.cpp -o app.exe <br>
./app.exe

### Using CodeBlocks / Dev-C++:
1. Create new project  
2. Add all `.cpp` files  
3. Build and run  

---

## Future Enhancements
- Add searching or sorting options  
- Add discount or promo system  
- Migrate from text file to database (SQLite/MySQL) 
- Add admin authentication  

---
Any type of valuebale contributions or modifications are welcomed.