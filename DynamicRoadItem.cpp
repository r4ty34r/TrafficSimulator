#include "RoadItem.h"

class ISimulator;
class Object;

void DynamicRoadItem::Print(ISimulator* print, Object* o)
{
	print->PrintRoadItem(this, o);
}
