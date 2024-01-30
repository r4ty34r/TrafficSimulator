#pragma once 
#include <iostream> 
#include "RoadItem.h"

//simulator class is used to keep track of, update, and delete items on/in the map

class Simulator
{
	public:
		void update(int seconds);
		void addDynamicRoadItem(DynamicRoadItem itemToAdd);
		void addStaticRoadItem(StaticRoadItem itemToAdd);

	private:
		vector<DynamicRoadItem> roadItems

}; // end class definition
