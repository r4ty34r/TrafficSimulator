// Driver program to create dynamic objects, store them in a list, and update their speed. 

// #include "Vehicle.h"
// #include "GUI.h" // added for HW5
// #include <iostream>
// #include <vector>
// #include <typeinfo>
// using namespace std;

// int main()
// {
//     // prompt user for standard
//     cout << "Enter 'M' for metric or 'I' for Imperial: ";   
//     char uInput; cin >> uInput;

//     IGUI* guiObj; // initializing pointer to gui object

//     // instatiates imperial or metric based on uInput variable
//     if(uInput == 'i' || uInput == 'I'){
//         cout << "\n calling imperialGUI allo" << endl;
//         ImperialGUI* gui = new ImperialGUI; // dynamically allocating a new gui object
//         guiObj = gui;
//     } else {
//         cout << "\n calling metricGUI allo " << endl;
//         MetricGUI * gui = new MetricGUI; // dynamically allocating a new gui object
//         guiObj = gui;
//     }

//     //prompt user for speed limit 
//     double limit;
//     cout << "Enter speed limit : "; cin >> limit;        

//     // init & set
//     cout << "Initializing Vehicles" << endl;
//     Vehicle* car = new Car; 
//     car->setDesiredSpeed(limit);
//     Vehicle* truck1 = new Truck(4); 
//     truck1->setDesiredSpeed(limit);
//     Vehicle* truck2 = new Truck(8); 
//     truck2->setDesiredSpeed(limit);

//     if(uInput == 'i' || uInput == 'I')
//     {
//         car->setDesiredSpeed(limit/Constants->MpsToMph);
//         truck1->setDesiredSpeed(limit/Constants->MpsToMph);
//         truck2->setDesiredSpeed(limit/Constants->MpsToMph);
//     }
//     else
//     {
//         car->setDesiredSpeed(limit/Constants->MpsToKph);
//         truck1->setDesiredSpeed(limit/Constants->MpsToKph);
//         truck2->setDesiredSpeed(limit/Constants->MpsToKph);
//     }

//     // initializing vector of vehicles 
//     vector<Vehicle*> vehicleslist; 

//     cout << "Adding vehicles to list" << endl;
//     // adding each pointer to list
//     vehicleslist.push_back(car);
//     vehicleslist.push_back(truck1);
//     vehicleslist.push_back(truck2);

//    // added for HW5
   
//    // setting desired speed for all vehicles
//     for(int i = 0; i < vehicleslist.size(); i++)
//     {
//         guiObj->SetSpeedLimit(*(vehicleslist.at(i)), limit); // gui SetSpeed = Vehicle setDesiredSpeed
//         //vehicleslist.at(i)->setDesiredSpeed(limit);
//     }
        
//     for (int i = 0; i < 11; i++) // main program loop to run 11x
//     {
//         // loop through vector and call method on each vehicle
//         for(int j = 0; j < vehicleslist.size(); j++)
//         {
//             vehicleslist.at(j)->updateSpeed(1);
//             cout << vehicleslist.at(j)->getType() << " speed is: " << guiObj->getSpeed(*vehicleslist.at(j)) << endl;
//         } // end vector loop 
//     } // end main loop


//    //END HW5 CODE 

//     // Clearing memory 
//     for (int i = 0; i < vehicleslist.size(); i++)
//     {
//         //cout << "\nDeleting memory ..." << i+1<< endl;
//         delete vehicleslist.at(i);
//         //delete gui;
//         delete guiObj;
//     }

//     return 0;
// }
