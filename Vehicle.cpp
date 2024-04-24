#include "Vehicle.h"
#include "CONSTRAINTS.h"
#include <typeinfo>
#include <iostream>
using namespace std;

// default constructor
Vehicle::Vehicle()
{
        std::cout << "default car constructor called" << std::endl;
        currentSpeed = 0.0;
        currentDirection = "x";
        currentLocation = "y";
        desiredSpeed = 0.0;
}

void Vehicle::setCurrentSpeed(double speed)
{
        if (currentSpeed <= speed) // accelerating
        {
                if (speed > desiredSpeed)
                {
                        currentSpeed = desiredSpeed;
                }
                else
                {
                        currentSpeed = speed;
                }
        }
        else // braking
        {
                if (speed < desiredSpeed)
                {
                        currentSpeed = desiredSpeed;
                }
                else
                {
                        currentSpeed = speed;
                }
        }
} // end setCurrentSpeed

void Vehicle::updateSpeed(int seconds)
{
        if (currentSpeed > desiredSpeed)
        {
                this->decelerate(seconds);
        }
        else if (currentSpeed < desiredSpeed)
        {
                this->accelerate(seconds);
        }
} // end updateSpeed

void Car::accelerate(int secondsDelta)
{

        this->setCurrentSpeed(this->getCurrentSpeed() + (Constants->AccRate * secondsDelta /** Constants->MpsToMph*/)); // removed conversion for HW5
} // end car::accelerate

void Car::decelerate(int secondsDelta)
{

        this->setCurrentSpeed(this->getCurrentSpeed() - (Constants->DecRate * secondsDelta /** Constants->MpsToMph*/)); // removed conversion for HW5
} // end car::decelrate

void Truck::accelerate(int secondsDelta)
{
        if (loadWeight <= 5)
        {
                this->setCurrentSpeed(this->getCurrentSpeed() + (Constants->AccRateEmpty * secondsDelta /** Constants->MpsToMph*/)); // removed conversion for HW5
        }
        else
        {
                this->setCurrentSpeed(this->getCurrentSpeed() + (Constants->AccRateFull * secondsDelta /** Constants->MpsToMph*/)); // removed conversion for HW5
        }
} // end truck::accelerate

void Truck::decelerate(int secondsDelta)
{
        if (loadWeight <= 5)
        {
                this->setCurrentSpeed(this->getCurrentSpeed() - (Constants->DecRateEmpty * secondsDelta /** Constants->MpsToMph*/)); // removed conversion for HW5
        }
        else
        {
                this->setCurrentSpeed(this->getCurrentSpeed() - (Constants->DecRateFull * secondsDelta /** Constants->MpsToMph*/)); // removed conversion for HW5
        }
} // end truck::decelerate

// returns a dereferenced type specifier for an object created
std::string Vehicle::getType()
{
        std::string s = typeid(*this).name();
        return s;
}
