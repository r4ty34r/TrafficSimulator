#pragma once 
#include<iostream>
#include "Vehicle.h"
#include "CONSTRAINTS.h"

// Simulator interface 
class ISimOutput {
    public:
        virtual ~ISimOutput(){}; // destructor
        virtual double getSpeed(Vehicle v) = 0;
}; // end interface definition

class MetricOutput : public ISimOutput {
    public:
        ~MetricOutput(){};
        double getSpeed(Vehicle v){ return v.getCurrentSpeed() * Constants->MpsToKph; }
}; // end metric def 

class ImperialOutput : public ISimOutput {
    public: 
        ~ImperialOutput(){};
        double getSpeed(Vehicle v){ return v.getCurrentSpeed() * Constants->MpsToMph; } 
};// end Imperial def 


