#include "Lights.h"


TrafficLights::TrafficLights(std::string name, std::string color, int rT, int yT, int gT, int xCoord, int yCoord)
{
    setName(name);
	currentColor = color;
	redTime = rT;
	yellowTime = yT;
	greenTime = gT;
	updatePosition(yCoord, xCoord);
}

void TrafficLights::updateColor(int seconds)
{
    
	timeOn += seconds;

    //std::string currentColor = getCurrentColor();

    std::cout << getName() << " Time On " << timeOn << " Color " << currentColor << std::endl;

	if (currentColor == "red") {
            if (timeOn >= redTime)
            {
                currentColor = "green";
                timeOn = 0;
            }
                //setCurrentColor( "green");
        } else if (currentColor == "green") {
            if (timeOn >= greenTime)
            {
                currentColor = "yellow";
                timeOn = 0;
            }
               //setCurrentColor( "yellow");
        } else {
            if (timeOn >= yellowTime)
            {
                currentColor = "red";
                timeOn = 0;
            }
               // setCurrentColor( "red");
	}

}

std::string TrafficLights::getCurrentColor()
{
    return currentColor;
}

