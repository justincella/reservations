//
//  Car.hpp
//  P1 - Reservations
//
//  Created by Justin Cella on 2/12/20.
//  Copyright © 2020 Justin Cella. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <iostream>
#include <string>

using namespace std;
enum vehicleType {sedan = 24, suv = 35, exotic = 50};

class Car {
    string plateNumber;
    string make;
    string model;
    vehicleType vehicle;
    double pricePerDay;
    bool isAvailable;
    
    public:
        Car();
        string getPlateNumber();
        string getMake();
        string getModel();
        string getVehicleType();
        bool getIsAvailable();
        double getPricePerDay();
        void setPlateNumber(string plateNumber_);
        void setMake(string make_);
        void setModel(string model_);
        void setVehicleType(vehicleType vt_);
        void setIsAvailable(bool available_);
        void setPricePerDay(double price_);

    friend ostream& operator <<(ostream &out, Car &car) {
        out << " Plate Number: "<<car.plateNumber<<"\n Make: "<<car.make<<"\n Model: "<<car.model << endl;
        out << "\n Vehicle Type: ";

        if(car.getPricePerDay() == 24){
            out <<"Sedan" << endl;
            out << " Price Per Day: " << car.getPricePerDay() << endl;
            out << " Available Status:";
        }else if(car.getPricePerDay() == 35){
            out<<"Suv" << endl;
            out << " Price Per Day: " << car.getPricePerDay() << endl;
            out << " Available Status:";
        }else{
            out << "Exotic" << endl;
            out << " Price Per Day: " << car.getPricePerDay() << endl;
            out << " Available Status:";
        }
        
        if(car.isAvailable){
            out << " Available";
        }else{
            out << " Not Available";
        }

        return out;
    }
};

#endif /* Car_hpp */
