#include "Map.h"
#include "Signs.h"
#include <iostream>

using namespace std; 

int main(){
	cout << "Compiled successfully";
	//Car mycar; // inherits from base class
	
	RoadItem item1;
	SpeedLimitSign sign1; 
	cout << "\nClass object successfully created";
	cout << "\n speed limit is: " << sign1.getSpeedLimit();	
	return 0;
}
