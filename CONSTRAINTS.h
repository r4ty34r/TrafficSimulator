//CONSTRAINTS CLASS 
#pragma once
// public struct to hold constants
struct Constraints {
        const double AccRate = 3.5;          // Acceleration rate for cars in m/s
        const double AccRateEmpty = 2.5;     // Acceleration rate for light trucks in m/s
        const double AccRateFull = 1.0;      // Acceleration rate for heavy trucks in m/s
        const double DecRate = 7.0;          // Braking rate for cars in m/s
        const double DecRateEmpty = 5.0;     // Braking rate for light trucks in m/s
        const double DecRateFull = 2.0;      // Braking rate for light trucks in m/s
        const double MpsToMph = 2.237;
	const double MpsToKph = 3.6;	     // Conversion rate for Meters p/sec to Kilometers p/hr 

}; // end struct def

//initializing global constraints with dynamic struct
static Constraints* Constants = new Constraints;
