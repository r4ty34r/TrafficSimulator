// Driver program to create dynamic objects, store them in a list, and update their speed. 

#include "Vehicle.h"
#include "Simoutput.h"
#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout << "Starting program" << endl;
    
    // init & set 
    cout << "Initializing Vehicles" << endl;
    Car* car = new Car; 
    car->setDesiredSpeed(65.0);
    Truck* truck1 = new Truck(4); 
    truck1->setDesiredSpeed(55.0);
    Truck* truck2 = new Truck(8); 
    truck2->setDesiredSpeed(50.0);

    // initializing vector of vehicles 
    vector<Vehicle*> vehicleslist; 

    cout << "Adding vehicles to list" << endl;
    // adding each pointer to list
    vehicleslist.push_back(car);
    vehicleslist.push_back(truck1);
    vehicleslist.push_back(truck2);

    // added for HW4
    ISimOutput * simOutPut = new MetricOutput();
    ISimOutput * simOutput2 = new ImperialOutput();
    
    // running program loop 11x

    cout << "Beginning loop: " << endl;
    for (int i = 0; i < 11; i++)
    {
        // loop through vector and call method on each vehicle
        for(int j = 0; j < vehicleslist.size(); j++)
        {
            //cout << "Vehicle " << j+1 << " updating the " << i+1 << " time\n";
            vehicleslist.at(j)->updateSpeed(1);
            //string s = vehicleslist.at(j)->getType();
            //cout << s << " speed: " << vehicleslist.at(j)->getCurrentSpeed() << endl;
            //vehicleslist.at(j)->print();
            //cout << "\nVehicle type: " << vehicleslist.at(j)->getType()<< " Speed: "<< vehicleslist.at(j)->getCurrentSpeed();
            
            // added for hw4
            // note simOutPut = MetricOutput type and simOutPut2 = ImperialOutPut type
            cout << "\n METRIC: " << "Vehicle type: " << vehicleslist.at(j)->getType()<< " Speed: "<< simOutPut->getSpeed(*(vehicleslist.at(j)))<< std::endl; // dereferencing pointer
            cout << "\n IMPERIAL: " << "Vehicle type: " << vehicleslist.at(j)->getType()<< " Speed: "<< simOutput2->getSpeed(*(vehicleslist.at(j)))<< std::endl; // dereferencing pointer 

        }
    }

    // Clearing memory 
    for (int i = 0; i < vehicleslist.size(); i++)
    {
        cout << "\nDeleting memory ..." << i+1<< endl;
        delete vehicleslist.at(i);
    }

    return 0;
}
