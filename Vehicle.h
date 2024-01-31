#pragma once // guardrail
#include <iostream>
#include "RoadItem.h"

// base class interface
// 	private: currentSpeed, currentDirection, currentLocation
// 	public: accel(toSpeed), decel(toSpeed), turn(direction, degrees) 
//
// 	car: inherits from base class no modification
// 	truck: inherites from car
// 		private: loadWeight, public: additional method to SetLoadWeight(weight) 


// base class
class Vehicle : public DynamicRoadItem {
	public: 
		Vehicle(); // default consturctor
		void accelerate(float toSpeed);
		void decelerate(float toSpeed);
		void turn(std::string toDirection, float degrees);	
	private:
		float currentSpeed;
		std::string currentDirection;
		// note to remove currentLocation to reflect RoadItem class
		std::string currentLocation;
}; //end base class

class Car : public Vehicle{};

class Truck : public Car {
	public: 
		void setLoadWeight(float weightToLoad);
	private:
		float loadWeight; // total weight carried by truck
		std::string trailerColor;
}; 
