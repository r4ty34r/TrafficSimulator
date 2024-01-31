#pragma once 
#include "RoadItem.h" 

//base class used to derive all static road items 
class Sign : public RoadItem
{
	public: 
		//default constructor can handle everything needed
		Sign(int x, int y);// require location up front to populate map
		Sign(){currentSignName = "default";}
		std::string getSign(){return currentSignName;}
		void setSign(std::string toSignName){currentSignName = toSignName;} // used to desginate stop, yield, or intersection 
	private: 
		std::string currentSignName; //will hold stop, yield, or speed lim
};// end class definition 

//stop and yield are similar but speed limit requires an extra member for how fast 

class SpeedLimitSign : public Sign {
	public: 
		SpeedLimitSign(int limitSpeed); // speed param to change posted allowance 
		SpeedLimitSign(){speedLimit = 25.0;}
		double getSpeedLimit(){return speedLimit;}
	private: 
		double speedLimit;
};


class Intersection : public Sign {

	public:
		void addTurn(std::string turnToAdd);
		std::vector<std::string> getAvailableTurns(){return turns;}
		std::string GetTurn(int index);
	private: 
		std::vector<std::string> turns;

};
