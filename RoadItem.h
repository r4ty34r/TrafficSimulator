#pragma once
#include "Simulator.h"
#include <iostream> 


class ISimulator;
class Object;


class RoadItem 
{
	public:
		RoadItem(){currentLocation[0] = 0; currentLocation[1] = 0;} // default constructor
		int* getPosition(){return currentLocation;} // returns an array of an x,y 
		void setPostition(int xCoord, int yCoord)
		{
			currentLocation[0] = xCoord;
			currentLocation[1] = yCoord;
		}

		void setName(std::string nametoSet)
		{
			name = nametoSet;
		}

		double getMileMarker(){return mileMarker;}
		std::string getName(){return name;} // to allow manipulation of a specific object
		void setCurrentRoad(RoadItem* currentItem){currentRoadItem = currentItem;}
		RoadItem* getCurrentRoad(){return currentRoadItem;}
		RoadItem* getPreviousRoadItem(){return previousRoadItem;}
		RoadItem* getNextRoadItem(){return nextRoadItem;}
		void setPreviousRoadItem(RoadItem* previousItem){previousRoadItem = previousItem;}
	private:
		int currentLocation[2]; // private array recording an x,y 
		double mileMarker;
		std::string name; // to distinguish between stop and yield signs 
		RoadItem *nextRoadItem;
		RoadItem *previousRoadItem;
		RoadItem *currentRoadItem;
		
}; // end class definition

// this class will be used for Vehicles and Traffic Lights which have to be updated and checked by the simulation class
class DynamicRoadItem : public RoadItem
{
	// private:
	// 	std::string currentColor;

	public:
		virtual std::string getCurrentColor() = 0;	

		// void setCurrentColor(std::string color)
		// {	
		// 	std::cout<< "Setting Color "<< color <<" for " << currentColor << std::endl;
		// 	currentColor = color;
		// }

		void updatePosition(int xCoord, int yCoord) // accesses array elements to change x,y
		{
			setPostition(xCoord, yCoord);
		}
		void updatePosition(int seconds);

		void Print(ISimulator* print, Object* o);

		virtual void updateColor(int seconds) = 0;
}; // end class definition

// static road item for signs (stop, yield, speed, intersection) 
class StaticRoadItem : public RoadItem
{
	//empty for now	
};
