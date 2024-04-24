#include "Road.h"

Road::Road(std::string streetName, double locX, double locY, double len, Heading hdg) {
	name = streetName;
	length = len;
	heading = hdg;
	xlocation = locX;
	ylocation = locY;
}

Road::Road(std::string streetName, double locX, double locY, double len, Heading hdg, std::vector<DynamicRoadItem*> roadItems) {
	name = streetName;
	length = len;
	heading = hdg;
	xlocation = locX;
	ylocation = locY;
	listOfRoadItems = roadItems;
}

double Road::getLength() {

	return length;

}

double Road::getXLocation() {

	return xlocation;

}

double Road::getYLocation() {

	return ylocation;

}

Heading Road::getHeading() {

	return heading;

}

std::string Road::getRoadName() {

	return name;

}

void Road::Print(ISimulator* print, Object* o) {

	print->PrintRoad(this, o);

}

std::vector<DynamicRoadItem*> Road::getRoadItems()
{
	return listOfRoadItems;
}