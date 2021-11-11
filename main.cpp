//
//  main.cpp
//  P1 - Reservations
//
//  Created by Justin Cella on 2/12/20.
//  Copyright © 2020 Justin Cella. All rights reserved.
//

#include <iostream>
#include <string>
#include "Car.hpp"
#include "Reservation.hpp"
#define MAX 100
using namespace std;

int menu();
void listCars(Car car[], int lenC);
void addCar(Car car[], int &lenC);
int searchCar(Car car[], int lenC, string plateNumber);
void removeCar(Car car[], int &lenC);
void listAvailableRentals(Car car[], int lenC);
void listReservation(Reservation res[], int lenR);
int addReservation(Reservation res[], int &lenR, Car car[], int lenC);
int searchReservation(Reservation res[], int lenR, string plateNumber);
void cancelReservation(Reservation res[], int &lenR, Car car[], int lenC);

//----------------------------------- Main -----------------------------------/
int main(){
    int lenC = 0;
    int lenR = 0;
    
    // Array of car objects with size of MAX
    Car car[MAX];
    // Array of reservation objects with size of MAX
    Reservation res[MAX];

    while(1){
        switch(menu()){
            case 1: listCars(car, lenC);
                break;
            case 2: addCar(car, lenC);
                break;
            case 3: removeCar(car, lenC);
                break;
            case 4: listReservation(res, lenR);
                break;
            case 5: addReservation(res, lenR, car, lenC);
                break;
            case 6: cancelReservation(res, lenR, car, lenC);
                break;
            case 7: exit(0);
            default: cout << "\n Invalid choice!!";
        }
    }
    return 0;
}

//------------------------------- Display Menu ---------------------------------
int menu(){
    int choice;
    cout << "****************************" << endl;
    cout << "****** XYZ Car Rental ******" << endl;
    cout << "****************************" << endl;
    cout << "1. List all cars" << endl;
    cout << "2. Add car to inventory" << endl;
    cout << "3. Remove car from inventory" << endl;
    cout << "4. List all reservations" << endl;
    cout << "5. Add a reservations" << endl;
    cout << "6. Cancel reservation" << endl;
    cout << "7. Exit" << endl;

    cout << "\n\t What is your choice? ";
    cin >> choice;
    return choice;
}

//------------------------------- List all cars --------------------------------
void listCars(Car car[], int lenC){
    // Guard if statement
    if(lenC == 0){ cout << "\nCar list is empty.\n" << endl; }
    
    // If there's any cars in the array, then display
    cout << "\n-------------- Car Information --------------" << endl;
    for(int c = 0; c < lenC; c++){
        cout << car[c] << endl;
    }
}

//------------------------------ Add Car to List -------------------------------
void addCar(Car car[], int &lenC){
    string plateNumber;
    string make;
    string model;
    string vehicleT;
    
    cout << "Please Enter" << endl;
    cout << "Plate Number: ";
    cin >> plateNumber;
    car[lenC].setPlateNumber(plateNumber);
    
    cout << "Make: ";
    cin >> make;
    car[lenC].setMake(make);
    
    cout << "Model: ";
    cin >> model;
    car[lenC].setModel(model);
    
    while(1){
        cout << "Enter Vehicle Type of sedan, suv, or exotic (case sensitive): ";
        cin >> vehicleT;
        
        // Compare input and set Vehicle Type and Price Per Day
        if(vehicleT.compare("sedan") == 0){
            car[lenC].setVehicleType((vehicleType)sedan);
            car[lenC].setPricePerDay((vehicleType)sedan);
            break;
        }else if(vehicleT.compare("suv") == 0){
            car[lenC].setVehicleType((vehicleType)suv);
            car[lenC].setPricePerDay((vehicleType)suv);
            break;
        }else if(vehicleT.compare("exotic") == 0){
            car[lenC].setVehicleType((vehicleType)exotic);
            car[lenC].setPricePerDay((vehicleType)exotic);
            break;
        }else{
            continue;
        }
    };
    
    lenC++;
}

//------------------------------ Search Car List -------------------------------
int searchCar(Car car[], int lenC, string plateNumber){
    // Guard if statment
    if(lenC <= 0){ cout << "\n Car list empty. Unable to Search." << endl; }
        
    for(int c = 0; c < lenC; c++){
        if(plateNumber.compare(car[c].getPlateNumber()) == 0){
            return c;
        }
    }
        
    return -1;
}

//---------------------------- Remove Car from List ----------------------------
void removeCar(Car car[], int &lenC){
    // Guard if statement
    if(lenC <= 0){ cout << "\nCar list empty" << endl; }
    
    string plateNumber;
    
    cout << "\nEnter Plate Number to remove the car: ";
    cin >> plateNumber;
        
    int found = searchCar(car, lenC, plateNumber);

    if(found == -1){
        cout << "\nNo car found with plate number: " << plateNumber << endl;
    }else{
        for(int c = found; c < lenC; c++){
            car[c] = car[c + 1];
        }
            
        lenC--;
        cout << "\n" << plateNumber << " removed" << endl;
    }
}

//-------------------------- List Available Rentals ----------------------------
void listAvailableRentals(Car car[], int lenC){
    // Guard if statement
    if(lenC <= 0){ cout << "\n Car list is empty" << endl; }
    
    int counter = 0;
    cout <<"\n-------------- Available Car Information --------------" << endl;
        
    for(int c = 0; c < lenC; c++){
        if(car[c].getIsAvailable() == true){
            cout << ++counter << ". " << car[c].getMake() << " " +
                car[c].getModel() << " (" << car[c].getVehicleType() +
                ") $" << car[c].getPricePerDay() << "/day" << endl;
        }
    }
}

//------------------------- List Current Reservations --------------------------
void listReservation(Reservation res[], int lenR){
    // Guard if statement
    if(lenR <= 0){ cout << "\n Reservation list is empty" << endl; }
    
    cout << "\n\n -------------- Reservation Information --------------" << endl;
    for(int c = 0; c < lenR; c++){
        cout << res[c] << endl;
    }
}

//------------------------------ Add Reservation -------------------------------
int addReservation(Reservation res[], int &lenR, Car car[], int lenC){
    // Guard if statement
    if(lenC <= 0) { cout << "\nCar list empty and cannot make a reservation" << endl; }
    
    string name;
    string plateNumber;
    int choice;

    cout << "\nEnter customer's name: ";
    cin >> name;
               
    listAvailableRentals(car, lenC);
    cout << lenC+1 << ". Cancel" << endl;
        
    cout <<"\nEnter your choice: ";
    cin >> choice;
               
    if(choice == lenC+1){
        return 0;
    }else{
        res[lenR].setName(name);
        res[lenR].setVehicleRented(car[choice-1].getPlateNumber());
        car[choice-1].setIsAvailable(false);
        lenR++;
    }
    
    return 0;
}

//---------------------------- Search Reservations -----------------------------
int searchReservation(Reservation res[], int lenR, string plateNumber){
    // Guard if statement
    if(lenR <= 0){ cout << "\nReservation list is empty" << endl; }
    
    for(int c = 0; c < lenR; c++){
        if(plateNumber.compare(res[c].getVehicleRented()) == 0){
            return c;
        }
    }
    return -1;
}

//--------------------------- Cancel a Reservation -----------------------------
void cancelReservation(Reservation res[], int &lenR, Car car[], int lenC){
    // Guard if statement
    if(lenR <= 0){ cout << "\nReservation list empty" << endl; }
    
    string plateNumber;
    
    cout <<"\nEnter the plate number: ";
    cin >> plateNumber;

    int found = searchReservation(res, lenR, plateNumber);
    
    if(found == -1){
        cout << "\nNo reservation for plate number: " << plateNumber << endl;
    }else{
        for(int c = found; c < lenR; c++){
            res[c] = res[c + 1];
        }
        
        car[found].setIsAvailable(true);
        lenR--;
        cout << "\nReservation for " << plateNumber << " canceled" << endl;
    }
}
