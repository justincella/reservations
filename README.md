# Reservations

### Note
This program was assigned and completed for the Data Structures and Algorithms course.
### Prompt
You have been hired by XYZ Car Rental to develop a software system for their business.
Your program will have two unordered lists, one of Cars and one of Reservations. 

The Program class will be composed of the two lists. 
There will also be a method to display a menu that will have the following options, 
Create a method to process the user's input and call appropriate methods to perform the operation requested.
(Use a switch statement and call the appropriate methods based on the number the user puts in)

At the end of each option's method (except Exit) make sure ot list the menu options again.


## Program Details

Car class data:
```
string plateNumber; (Key)
string make;
string model;
enum vehicleType; (Options: sedan, suv, exotic)
double pricePerDay;
bool isAvailable;
```
isAvailable initializes to true on program start. The public setter method, setAvailable(bool available), is used to change availability 

Reservation class data:
```
string name; (key)
string vehicleRented; (plate of the car which is our key for the list)
```


### Program Menu
```
-------------------------------------------
XYZ Car Rental
-------------------------------------------
1. List all cars
2. Add car to inventory
3. Remove car from inventory
4. List all reservations
5. Add a reservations
6. Cancel reservation
7. Exit
```

#### Menu Options
* **Option 1:**
  * List all the cars in the unordered list of cars.

* **Option 2:**
  * Prompts user for all the information of a vehicle. <br>
  * Create the vehicle and add it to the list of available vehicles.

* **Option 3:**
  * Remove a vehicle from the list of available cars. <br>

* **Option 4:**
  * List all the reservations. <br>
  * Use the key in the reservation to retrieve the vehicle details from the list of vehicles

* **Option 5:**
  * Prompt the user for a name. <br>
  * List all the cars that are available (isAvailable = true): 
    ```
      1. Nissan Sentra (sedan) $24/day
      2. ...
      n+1. Cancel
    ```
* **Option 6:**
  * Prompts the user for a name. <br>
  * Remove the reservation object from the list if that user's name is a key. <br>
  * Use the plate number to find the car in the list and set available to true.
    
