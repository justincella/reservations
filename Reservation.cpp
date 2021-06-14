//
//  Reservation.cpp
//  P1 - Reservations
//
//  Created by Justin Cella on 2/12/20.
//  Copyright © 2020 Justin Cella. All rights reserved.
//

#include "Reservation.hpp"

Reservation::Reservation(){
    name = vehicleRented = "";
}

string Reservation::getName(){
    return name;
}

string Reservation::getVehicleRented(){
    return vehicleRented;
}

void Reservation::setName(string name_){
    name = name_;
}

void Reservation::setVehicleRented(string vehicle_){
    vehicleRented = vehicle_;
}
