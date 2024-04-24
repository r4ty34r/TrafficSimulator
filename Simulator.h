#pragma once 
#include <iostream> 
#include <vector>
#include "Conversions.h"
#include "RoadItem.h"
class Road;
class Car;
class DynamicRoadItem;
class Object {

public:
	virtual ~Object() = default;

};

class CharMatrix : public Object {

public:
	std::vector<std::vector<char>> map;
	CharMatrix();
};

class ISimulator {

public:
	virtual void PrintRoad(Road* road, Object* o) = 0;
	virtual void PrintRoadItem(DynamicRoadItem* roadItem, Object* o) = 0;

};

class Simulator : public ISimulator {

public:
	void PrintRoad(Road* road, Object* o);
	void PrintRoadItem(DynamicRoadItem* roadItem, Object* o);

};
