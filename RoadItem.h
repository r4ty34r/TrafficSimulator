#pragma once
#include <iostream> 

class RoadItem 
{
	public:
		RoadItem(){currentLocation[0] = 0; currentLocation[1] = 0;} // default constructor
		int getPosition(); // returns an array of an x,y 
		double getMileMarker(){return mileMarker;}
		std::string getName(){return name;} // to allow manipulation of a specific object
		
	private:
		int currentLocation[2]; // private array recording an x,y 
		double mileMarker;
		std::string name; // to distinguish between stop and yield signs 
		RoadItem nextRoadItem;
		RoadItem previousRoadItem;
		RoadItem currentRoadItem;
		
}; // end class definition

// this class will be used for Vehicles and Traffic Lights which have to be updated and checked by the simulation class

class DynamicRoadItem : public RoadItem{
	public:
		void updatePosition(int xCoord, int yCoord); // accesses array elements to change x,y
		void updatePosition(int seconds);
		
}; // end class definition

// static road item for signs (stop, yield, speed, intersection) 
class StaticRoadItem : public RoadItem{
	//empty for now	
};
