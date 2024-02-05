#include"Vehicle.h"
#include<iostream>


// class to hold constants
class Constraints {
    public:
        const double AccRate = 3.5;          // Acceleration rate for cars in m/s
        const double AccRateEmpty = 2.5;     // Acceleration rate for light trucks in m/s
        const double AccRateFull = 1.0;      // Acceleration rate for heavy trucks in m/s
        const double DecRate = 7.0;          // Braking rate for cars in m/s
        const double DecRateEmpty = 5.0;     // Braking rate for light trucks in m/s
        const double DecRateFull = 2.0;      // Braking rate for light trucks in m/s
        const double MpsToMph = 2.237;

}; // end class def 

//initializing global constraints 
Constraints* Constants = new Constraints;

//default constructor 
Vehicle::Vehicle(){
    currentSpeed = 0.0;
    currentDirection = "x";
    currentLocation ="y";
    desiredSpeed = 0.0;
}

void Vehicle::setCurrentSpeed(double speed)
    {
        if(currentSpeed <= speed) // accelerating
        {
            if (speed > desiredSpeed) 
            {
                currentSpeed = desiredSpeed;
            }
            else {
                currentSpeed = speed;
                }
        } else // braking
            {
                if (speed < desiredSpeed) 
                {
                    currentSpeed = desiredSpeed;
                } else{ 
                    currentSpeed = speed;
                }
            }
    }

void Vehicle::updateSpeed(int seconds){

     if (currentSpeed > desiredSpeed) {this->decelerate(seconds);}
            else if (currentSpeed < desiredSpeed) {this->accelerate(seconds);}
}




void Car::accelerate(int secondsDelta){
    
    this->setCurrentSpeed(this->getCurrentSpeed() + Constants->AccRate * secondsDelta * Constants->MpsToMph);
}


void Car::decelerate(int secondsDelta){

        this->setCurrentSpeed(this->getCurrentSpeed() - Constants->DecRate * secondsDelta * Constants->MpsToMph);
}

void Truck::accelerate(int secondsDelta){

            if (loadWeight <= 5)
                    this->setCurrentSpeed(this->getCurrentSpeed() + Constants->AccRateEmpty * secondsDelta * Constants->MpsToMph);
            else
                    this->setCurrentSpeed(this->getCurrentSpeed() + Constants->AccRateFull * secondsDelta * Constants->MpsToMph); 
}

void Truck::decelerate(int secondsDelta)
{
    if (loadWeight <= 5)
            this->setCurrentSpeed(    this->getCurrentSpeed() - Constants->DecRateEmpty * secondsDelta * Constants->MpsToMph);
    
    else
            this->setCurrentSpeed(    this->getCurrentSpeed() - Constants->DecRateFull * secondsDelta * Constants->MpsToMph);
}