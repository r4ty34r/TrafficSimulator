// Driver program to create dynamic objects, store them in a list, and update their speed. 

#include "Vehicle.h"
#include<iostream>
#include<vector>
using namespace std;

int main(){
    double car1outputspeed = 7.83;
    double truck1speed = 5.59;
    double truck2speed = 2.24;

    cout << "Starting program" << endl;
    
    //init & set 
    cout << "Initializing Vehicles" << endl;
    Car* car = new Car; 
    car->setDesiredSpeed(65.0);
    Truck* truck1 = new Truck(4); 
    truck1->setDesiredSpeed(55.0);
    Truck* truck2 = new Truck(8); 
    truck2->setDesiredSpeed(50.0);

    //initializing vector of vehicles 
    vector<Vehicle*> vehicleslist; 

    cout << "Adding vehicles to list" << endl;
    //adding each pointer to list
    vehicleslist.push_back(car);
    vehicleslist.push_back(truck1);
    vehicleslist.push_back(truck2);

    // running program loop 11x

    cout << "Beginning loop: " << endl;
    for (int i = 0; i < 11; i++)
    {
        //loop through each vehicle 
        for(int j = 0; j < vehicleslist.size(); j++)
        {
            //cout << "Vehicle " << j+1 << " updating the " << i+1 << " time\n";
            vehicleslist.at(j)->updateSpeed(1);
            //string s = vehicleslist.at(j)->getType();
            //cout << s << " speed: " << vehicleslist.at(j)->getCurrentSpeed() << endl;
            vehicleslist.at(j)->print();
        }
        
    }

    // Clearing memory 
    for (int i = 0; i < vehicleslist.size(); i++)
    {
        cout << "\nDeleting memory ..." << i+1<< endl;
        delete vehicleslist.at(i);
    }
    /*
    List<Vehicle> vehicles = new List<Vehicle>();
            vehicles.Add(car); vehicles.Add(truck1); vehicles.Add(truck2);
            for (int i = 0; i < 11; i++)
            {
                foreach (Vehicle v in vehicles)
                {
                    v.UpdateSpeed(1);
                    string s = v.GetType().ToString();
                    Console.WriteLine("{0} speed: {1:F} mph", s, v.GetCurrentSpeed());
                }
            }

            */

    return 0;
}
