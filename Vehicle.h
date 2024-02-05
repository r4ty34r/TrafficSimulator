#pragma once // guardrail
#include "RoadItem.h"
#include <iostream>
//#include "RoadItem.h" //commented out for HW3

// base class interface
// 	private: currentSpeed, currentDirection, currentLocation desiredSpeed
// 	public: accel(toSpeed), decel(toSpeed), turn(direction, degrees) 
//
// 	car: inherits from base class no modification
// 	truck: inherites from car
// 		private: loadWeight, public: additional method to SetLoadWeight(weight) 


// base class

class Vehicle : public  DynamicRoadItem{
	public: 
		Vehicle(); // default consturctor
		~Vehicle(){std::cout<< "Vehicle destructor executed" << std::endl;} // destructor
		void updateSpeed(int seconds); // actually modifies the current speed
		virtual void print(){std::cout << "Vehicle speed: " << currentSpeed << std::endl;}
		// getters/setters
		double getCurrentSpeed(){return currentSpeed;}
		void setDesiredSpeed(double mph){desiredSpeed = mph;}
		void setCurrentSpeed(double speed); // logic in Vehicle.cpp

		// to be implemented differently based on type of vehicle 
		virtual void accelerate(int secondsDelta){currentSpeed = 0;} 
		virtual void decelerate(int secondsDelta){currentSpeed = 0;}
		virtual std::string getType(){return "Vehicle";}
		//virtual void turn(std::string toDirection, float degrees);	
	private:
		std::string currentDirection;
		// note to remove currentLocation to reflect RoadItem class
		std::string currentLocation;
		double currentSpeed; // added for hw3
		double desiredSpeed; // added for hw3
}; //end base class

class Car : public Vehicle{
	public:
		~Car(){std::cout << "Car destructor executed" << std::endl;}
		void accelerate(int secondsDelta);
		void decelerate(int secondsDelta);
		std::string getType(){return "Car";}
		 void print(){std::cout << "Car speed: " << getCurrentSpeed() << std::endl;}
		 //void turn(int secondsDelta)
};

class Truck : public Car {
	public: 
		Truck(int loadingWeight){loadWeight = loadingWeight; setCurrentSpeed(0.0);}
		~Truck(){std::cout<<"Truck destructor executed" << std::endl;}
		void setLoadWeight(float weightToLoad);
		void accelerate(int secondsDelta);
		void decelerate(int secondsDelta);
		std::string getType(){return "Truck";}
		void print(){std::cout << "Truck speed: " << getCurrentSpeed() << std::endl;}
	
	private:
		float loadWeight; // total weight carried in tons
		std::string trailerColor;
}; 
