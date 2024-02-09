#pragma once 
#include<iostream>
#include "Vehicle.h"

// Simulator interface 
class ISimOutput {
    public:
        virtual ~ISimOutput(){}; // destructor
        virtual double getSpeed(Vehicle v){};
}; // end interface definition

class ImperialOutput : public ISimOutput {
    public: 
        ~ImperialOutput(){};
        double getSpeed(Vehicle v){ return v.getCurrentSpeed(); } 
};// end Imperial def 


class MetricOutput : public ISimOutput {
    public:
        ~MetricOutput(){};
        double getSpeed(Vehicle v){ return v.getCurrentSpeed() * 1.6; }
}; // end metric def 

