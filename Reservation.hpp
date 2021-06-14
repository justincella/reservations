//
//  Reservation.hpp
//  P1 - Reservations
//
//  Created by Justin Cella on 2/12/20.
//  Copyright © 2020 Justin Cella. All rights reserved.
//

#ifndef Reservation_hpp
#define Reservation_hpp

#include <string>
#include <iostream>
using namespace std;

class Reservation {
    string name;
    string vehicleRented;
    
    public:
        Reservation();
        
        string getName();
        string getVehicleRented();
        void setName(string name_);
        void setVehicleRented(string vehicle_);

    // Function to overload << operator to return reservation information
    friend ostream& operator <<(ostream &out, Reservation &rev){
        out << "\nName: " << rev.name << "\nVehicle Rented: " << rev.vehicleRented << endl;
        return out;
    }
};

#endif /* Reservation_hpp */
