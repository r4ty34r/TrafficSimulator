#pragma once 
#include "RoadItem.h"
#include <iostream>

// lights class derives from Dynamic Road Items
// currently has an updatePosition but it wont be used 
class TrafficLights : public DynamicRoadItem {
	public:
		void changeColor(std::string changeTocolor);
		std::string getCurrentLightColor() {return currentColor;} 
		update(int seconds);
	private:
		std::string currentColor;
		int redTime;
		int yellowTime;
		int greenTime;
		int timeOn; 
}; // end class definition

