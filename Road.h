#pragma once 
#include "RoadItem.h" 
#include <iostream> 
#include <vector> // including for now in place of dynamic arrays
// road class is a collection of road items to be handled by the map class
class Road {

	public:
		std::vector<RoadItem> getList(); // list getter 
		void addItem(RoadItem itemToAdd); // gives map access to private vector

		void removeItem(); // removes last added
		void removeItem(RoadItem itemToRemove); // systematic removal 
		RoadItem getItem(); // overload to allow recovery of assets in code  
		double getLength(){return length;}
		std::string getRoadName(){return name;}
		
	private:
		std::vector<RoadItem> listOfRoadItems; // initially a vector but ideally will be a dynamically allocated array of items
		std::string name;
		double length;

};

