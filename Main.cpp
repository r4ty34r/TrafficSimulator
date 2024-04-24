#include "Simulator.h"
#include "Map.h"
#include "Constraints.h"
#include "Lights.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <unistd.h>
#include <windows.h>
using namespace std;

int main()
{
    ISimulator* cp = new Simulator();
	CharMatrix* cm = new CharMatrix();

    Map map;

    vector<DynamicRoadItem*> upTownRoadItems;

    TrafficLights r1 = TrafficLights("Traffic Light-1", "red", 10, 5, 20, 0.0, -30.0); 
    upTownRoadItems.push_back(&r1); // Add Light 1
    TrafficLights r2 = TrafficLights("Traffic Light-2", "green", 6, 3, 12, 0.0, 30.0); 
    upTownRoadItems.push_back(&r2); // Add Light 2

	Road Uptown = Road("Uptown Road-1", 0.0, -90.0, 180.00, North, upTownRoadItems); 
	map.AddRoad(Uptown); // Add Road with Lights

    // Road Uptown2 = Road("Uptown2", 50.0, -90.0, 180.00, North); 
	// map.AddRoad(Uptown2); // Add Another Road Without Lights

	// Road Crosstown = Road("Crosstown", -90.0, 0.0, 180.00, East); 
	// map.AddRoad(Crosstown); // Add Crosstown Road
    int timer = 0;
    while (timer < 100) {
        system("cls"); // Clearing Screen
        //usleep(250000); // Sleep for .25 second
        Sleep(250);
        map.Print(cp, cm);
        for (int i = 0; i < Constants->CharMapSize; i++)
        {
            std::string s = "";
            for (int j = 0; j < Constants->CharMapSize; j++)
            {
                s = s + cm->map[i][j];
            }
            cout << s << endl;
        }
        for(int j = 0; j < upTownRoadItems.size(); j++)
        {
            upTownRoadItems.at(j)->updateColor(1);
        }
        //usleep(1000000); // Sleep for 1 second
        Sleep(1000);
        timer++;
    }

	
}
