#pragma once 
#include "Simulator.h"
#include <string>
#include "RoadItem.h" 
#include <iostream> 
#include <vector> // including for now in place of dynamic arrays
// road class is a collection of road items to be handled by the map class

enum Heading { North, South, East, West };

class ISimulator;
class Object;

class Road {

	public:
		std::vector<DynamicRoadItem*> getRoadItems(); // list getter 
		void addItem(RoadItem itemToAdd); // gives map access to private vector

		void removeItem(); // removes last added
		void removeItem(RoadItem itemToRemove); // systematic removal 
		RoadItem getItem(); // overload to allow recovery of assets in code  
		double getLength();
		double getXLocation();
		double getYLocation();
		Heading getHeading();
		std::string getRoadName();
		Road(std::string streetName, double locX, double locY, double len, Heading hdg);
		Road(std::string streetName, double locX, double locY, double len, Heading hdg, std::vector<DynamicRoadItem*> roadItems);
		void Print(ISimulator* print, Object* o);
		
	private:
		std::string name;
		double length;
		double xlocation;
		double ylocation;
		Heading heading;

		std::vector<DynamicRoadItem*> listOfRoadItems; // initially a vector but ideally will be a dynamically allocated array of items

};

