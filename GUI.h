#pragma once 
#include "Simoutput.h"
#include "SimInput.h"
#include "CONSTRAINTS.h"

// each class interfaces with ISimOutput

// abstract gui class

class IGUI : public ISimInput, public ISimOutput {
    public:
        ~IGUI(){std::cout<<"IGUI destructor called";}
        virtual double getSpeed(Vehicle v) = 0;
        // virtual setSpeedLimit && virtual getSpeed are declared in parents
}; // end GUI interface 

class MetricGUI : public IGUI {
    public:
        ~MetricGUI(){std::cout <<"MetricGUI destructor called";}
        double getSpeed(Vehicle v){return v.getCurrentSpeed() * Constants->MpsToKph;}
        void SetSpeedLimit(Vehicle v, double s){v.setDesiredSpeed(s / Constants->MpsToKph);}
        // add code to accel decel based on car/truck 
}; // end MetricGUI def `

class ImperialGUI : public IGUI {
    public:
        ~ImperialGUI(){std::cout <<"ImperialGUI destructor called";}
        double getSpeed(Vehicle v){return v.getCurrentSpeed() * Constants->MpsToMph;}
        void SetSpeedLimit(Vehicle v, double s){v.setDesiredSpeed(s/Constants->MpsToMph);}

        // add code to accel decel based on car/truck 
}; // end MetricGUI def 