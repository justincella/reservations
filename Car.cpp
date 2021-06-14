//
//  Car.cpp
//  P1 - Reservations
//
//  Created by Justin Cella on 2/12/20.
//  Copyright © 2020 Justin Cella. All rights reserved.
//

#include "Car.hpp"

Car::Car(){
    isAvailable = true;
}
    
string Car::getPlateNumber(){
    return plateNumber;
}

string Car::getMake(){
    return make;
}

string Car::getModel(){
    return model;
}

string Car::getVehicleType() {
    if(vehicle == 24){
        return "Sedan";
    }else if(vehicle == 35){
        return "Suv";
    }else{
        return "Exotic";
    }
}

double Car::getPricePerDay(){
    return pricePerDay;
}

bool Car::getIsAvailable(){
    return isAvailable;
}
    
void Car::setPlateNumber(string plateNumber_){
    plateNumber = plateNumber_;
}
       
void Car::setMake(string make_){
    make = make_;
}
        
void Car::setModel(string model_){
    model = model_;
}

void Car::setVehicleType(vehicleType vt_) {
    vehicle = vt_;
}

void Car::setPricePerDay(double price_){
    pricePerDay = price_;
}
       
void Car::setIsAvailable(bool available_){
    isAvailable = available_;
}
