#include "map.h"
#include "Simulator.h"
#include "road.h"

Map::Map() { }

void Map::AddRoad(Road road) {
	roads.push_back(road);
}

void Map::Print(ISimulator* pd, Object* o) {
	for (std::vector<Road>::iterator it = roads.begin(); it != roads.end(); ++it) {
		std::cout << it->getRoadName() << std::endl;
		
		it->Print(pd, o);

		std::vector<DynamicRoadItem*> roadItems = it->getRoadItems();

		for(int i = 0; i < roadItems.size(); i++)
		{
			roadItems.at(i)->Print(pd, o);
		}
	}
}
