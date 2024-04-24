#pragma once 
#include "Road.h"
#include<iostream>

// map class is used to contain all other items 

class Road;
class ISimulator;
class Object;

class Map {

private:
	std::vector<Road> roads; // A vector is used here as the closest approximation to a C# List.

public:
	Map();
	void AddRoad(Road road);
	void Print(ISimulator* pd, Object* o);

};
