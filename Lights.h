#pragma once 
#include "RoadItem.h"
#include <iostream>

// lights class derives from Dynamic Road Items
// currently has an updatePosition but it wont be used 
class TrafficLights : public DynamicRoadItem {
	public:
		TrafficLights(std::string name, std::string color, int redTime, int yellowTime, int greenTime, int xCord, int yCord);
		//void changeColor(std::string changeTocolor);
		std::string getCurrentColor() override;
		void updateColor(int seconds) override;
	private:
		std::string currentColor;
		int redTime = 0;
		int yellowTime = 0;
		int greenTime = 0;
		int timeOn = 0; 
}; // end class definition

