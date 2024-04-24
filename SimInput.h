#pragma once 
#include "Vehicle.h"
#include "CONSTRAINTS.h"

// interface for input class

class ISimInput {
    public:
        ~ISimInput(){std::cout<< "Base SimInput destructor called";}
        virtual void SetSpeedLimit(Vehicle v, double speed) = 0;
};// end ISimInput def

class MetricInput : public ISimInput{
    public:
        ~MetricInput(){std::cout << "MetricInput destructor called";}
        void SetSpeedLimit(Vehicle v, double speed){
            v.setDesiredSpeed(speed/Constants->MpsToKph);
        }
}; // end Metric input def 

class ImperialInput : public ISimInput{
    public:
        ~ImperialInput(){std::cout << "ImperialInput destructor called";}
        void SetSpeedLimit(Vehicle v, double speed){
            v.setDesiredSpeed(speed/Constants->MpsToMph);

        }

}; // end Imperial input def 