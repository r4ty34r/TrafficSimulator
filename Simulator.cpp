#include "Simulator.h"
#include "CONSTRAINTS.h"
#include "Road.h"
#include <iostream>

CharMatrix::CharMatrix() {

	// A nested for loop constructs the vector of the appropriate size.
	// The vector must be in the correct dimensions in order to call its elements by index with the [] operator.
	for (int i = 0; i < Constants->CharMapSize; i++) {
		std::vector<char> tempVec;
		for (int j = 0; j < Constants->CharMapSize; j++) {
			tempVec.push_back(' ');
		}
		map.push_back(tempVec);
	}

}

void Simulator::PrintRoad(Road* road, Object* o) {

	CharMatrix* cm = dynamic_cast<CharMatrix*>(o);
	int x;
	int y;
	int CCx = Conversions::WCpointToCCpoint(road->getXLocation());
	int CCy = Conversions::WCpointToCCpoint(-road->getYLocation());

	int distance = 0;
	int CCRoadLength = Conversions::WClengthToCClength(road->getLength());
	switch (road->getHeading()) {
	case North:
		//std::cout <<"IT COMES HERE";
		x = (int)CCx;
		if (x >= 0 && x < Constants->CharMapSize) {
			while (distance < CCRoadLength) {
				y = (int)(CCy - distance);
				if (y >= 0 && y < Constants->CharMapSize) {
					cm->map[y][x] = '|';
					cm->map[y][x + 2] = '|';
					cm->map[y][x + 4] = '|';
				}
				distance += 1;
			}
		}
		break;
	case South:
		break;
	case East:
		//std::cout <<"IT COMES EAST";
		y = (int)CCy;
		if (y >= 0 && y < Constants->CharMapSize) {
			while (distance < CCRoadLength) {
				x = (int)(CCx + distance);
				if (x >= 0 && x < Constants->CharMapSize) {
					cm->map[y][x] = '-';
					cm->map[y + 2][x] = '-';
					cm->map[y + 4][x] = '-';
				}
				distance += 1;
			}
		}
		break;
	case West:
		break;
	default:
		break;
	}

}

void Simulator::PrintRoadItem(DynamicRoadItem* roadItem, Object* o) {

	CharMatrix* cm = dynamic_cast<CharMatrix*>(o);
	int x = Conversions::WCpointToCCpoint(roadItem->getPosition()[0]);
	int y = Conversions::WCpointToCCpoint(roadItem->getPosition()[1]);

	std::string color = roadItem->getCurrentColor();

	//std::cout<< "Print Color is " << color << std::endl;
	if( color == "red")
	{
		cm->map[x][y] = 'X';
		cm->map[x][y+2] = 'X';
		cm->map[x][y+4] = 'X';
	}
	else if(color== "yellow")
	{
		cm->map[x][y] = '-';
		cm->map[x][y+2] = '-';
		cm->map[x][y+4] = '-';
	}
	else
	{
		cm->map[x][y] = 'O';
		cm->map[x][y+2] = 'O';
		cm->map[x][y+4] = 'O';
	}

}