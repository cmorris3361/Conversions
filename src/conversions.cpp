/*--------------------------------------------------------------------------*
 * Arduino Conversion and Lookup Library                                    *
 * Charlie Morris 2024                                                      *
 *                                                                          *
 * Arduino Conversion and Lookup  Library Copyright (C) 2024 Charlie Morris *
 * and licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html   *
 *--------------------------------------------------------------------------*/


#include "conversions.h"

/* **** Speed Conventions **** */

/*----------------------------------------------------------------------*
 * Convert Mile per Hour (MPH) to Kilometers per Hour (KPH)             *
 *----------------------------------------------------------------------*/
double convert::MPHtoKPH(double mph){
    return mph * 1.609344;
}


/*----------------------------------------------------------------------*
 * Convert Mile per Hour (MPH) to Meters per Second (MPS)               *
 *----------------------------------------------------------------------*/
double convert::MPHtoMS(double mph){
    return mph * 0.44704;
}

/*----------------------------------------------------------------------*
 * Convert Kilometers per Hour (KPH) to  Mile per Hour (MPH) to         *
 *----------------------------------------------------------------------*/
double convert::KPHtoMPH(double kph){
    return kph * 0.62137119;
}


/*----------------------------------------------------------------------*
 * Convert Meters per Second (MPS) to Mile per Hour (MPH)               *
 *----------------------------------------------------------------------*/
double convert::MStoMPH(double mps){
    return mps * 2.2369363;
}

/*----------------------------------------------------------------------*
 * Convert Knots to Mile Per Hour
 *----------------------------------------------------------------------*/
double cvtKtoMPH(double k){
    return k * 1.150779448;
}

/*----------------------------------------------------------------------*
 * Convert Knots to Kilometer Per Hour
 *----------------------------------------------------------------------*/
double convert::KtoKPH(double k){
    return k * 1.852;
}

/*----------------------------------------------------------------------*
 * Convert Mile Per Hour to Knots
 *----------------------------------------------------------------------*/
double convert::MPHtoK(double mph){
    return mph * 0.86897624191;
}

/*----------------------------------------------------------------------*
 * Convert Kilometer Per Hour to Knots
 *----------------------------------------------------------------------*/
double convert::KPHtoK(double kmh){
    return kmh *  0.53995680346;
}


/* **** Temperatures Conventions **** */

/*----------------------------------------------------------------------*
// Convert Kevin to Celsius                                             *
*----------------------------------------------------------------------*/
double convert::KtoC(double k){
  return k - 272.15;
}

/*----------------------------------------------------------------------*
// Convert Kevin to Fahrenheit
*----------------------------------------------------------------------*/
double convert::KtoF(double k){
  return k - 272.15;
}

/*----------------------------------------------------------------------*
// Convert Fahrenheit to Celsius (Celsius = (Fahrenheit - 32) / 1.8)
*----------------------------------------------------------------------*/
double convert::FtoC(double f){
  return (f - 32) / 1.8;
}

/*----------------------------------------------------------------------*
// Convert Celsius to Fahrenheit (Fahrenheit = (Celsius * 1.8) + 32)
*----------------------------------------------------------------------*/
double convert::CtoF(double c){
  return (c * 1.8) + 32;
}


// **** Distance Conventions ****

/*----------------------------------------------------------------------*
// Convert Centimeters to Feet
*-----------------------------------------------------------------------*/
double convert::CMtoFeet(double cm){
    return cm * 0.03280839895;
}

/*----------------------------------------------------------------------*
// Convert Centimeters to Inch
*-----------------------------------------------------------------------*/
double convert::CMtoInch(double cm){
    return cm * 0.3937007874;
}

/*----------------------------------------------------------------------*
// Convert Feet to Centimeter
*-----------------------------------------------------------------------*/
double convert::FeettoCM(double feet){
    return feet * 30.48;
}

/*----------------------------------------------------------------------*
// Convert Inch to Centimeter
*-----------------------------------------------------------------------*/
double convert::InchtoCM(double inch){
    return inch * 2.54;
}

/*----------------------------------------------------------------------*
// Convert Yard to Meter
*-----------------------------------------------------------------------*/
double convert::YardtoMeter(double yard){
    return yard * 0.9144;
}

/*----------------------------------------------------------------------*
// Convert Meter to Yard
*-----------------------------------------------------------------------*/
double convert::MetrtoYard(double meter){
    return meter * 1.0936132983;
}

/*----------------------------------------------------------------------*
// Convert Kilometer to Mile
*-----------------------------------------------------------------------*/
double convert::KMtoMile(double km){
    return km * 0.62137119224;
}

/*----------------------------------------------------------------------*
// Convert mile to Kilometer
*-----------------------------------------------------------------------*/
double convert::MiletoKM(double mile){
    return mile * 1.609344;
}

/* **** Areas Conventions **** */

/*----------------------------------------------------------------------*
// Convert Square Yards to Square Meter
 -----------------------------------------------------------------------*/
double convert::qYardtoSqMeter(double sqyard){
    return sqyard * 0.83612736;
}

/*----------------------------------------------------------------------*
// Convert Square Yards to Square Meter
 -----------------------------------------------------------------------*/
double convert::SqMetertoSqYard(double sqmeter){
    return sqmeter * 1.1959900463;
}


/* **** MASS Conventions **** */

/*----------------------------------------------------------------------*
// Convert Kilogram to Pounds
 -----------------------------------------------------------------------*/
double convert::KGtoLbs(double kg){
    return kg * 2.2046226218;
}

/*----------------------------------------------------------------------*
// Convert Kilograms to Stone
 -----------------------------------------------------------------------*/
double convert::KGtoSt(double kg){
    return kg * 2.2046226218 / 14;
}

/*----------------------------------------------------------------------*
// Convert Kilograms to Stone & Pounds
 -----------------------------------------------------------------------*/
double convert::KGtoStLb(double kg){
    double lbs = kg * 2.2046226218;      // Firstly Convert to Pounds
    int st = int(lbs / 14);              // Get Stone portion
    double lb = (int(lbs) % 14) / 100;        // Lbs as .xx
    return (double)st + lb;
}

/*----------------------------------------------------------------------*
// Convert Pounds to Kilograms
 -----------------------------------------------------------------------*/
double convert::LbstoKG(double lbs){
    return lbs * 0.45359237;
}

/*----------------------------------------------------------------------*
// Convert Grams  to Ounce
 -----------------------------------------------------------------------*/
double convert::GtoOZ(double g){
    return g * 0.03527396195;
}

/*----------------------------------------------------------------------*
// Convert Ounce to Grams
 -----------------------------------------------------------------------*/
double convert::OZtoG(double oz){
    return oz * 28.349523125;
}


/*----------------------------------------------------------------------*
// Convert given Seconds to Minutes and Seconds
// Return as mm:ss
 -----------------------------------------------------------------------*/
String S2MS(int seconds){
  unsigned long minutes = seconds / 60;
//  unsigned long hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;
  return (String)leadZero((String)minutes, 2) + ":" + leadZero((String)seconds,2);
  
/*----------------------------------------------------------------------*
// Convert given milli seconds in to Day, Hours, Minutes and Seconds
// return as D HH:MM:SS.ms
 -----------------------------------------------------------------------*/
String MS2DHMS(unsigned long ms){
  unsigned long seconds = ms / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  unsigned long days = hours / 24;
  unsigned long dms = ms % 1000;
  seconds %= 60;
  minutes %= 60;
  hours %= 24;
  return (String)days + "d " + 
         leadZero((String)hours, 2) + ":" + 
         leadZero((String)minutes, 2) + ":" + 
         leadZero((String)seconds,2) + "." +
         (String)(dms);
}

private
// Return string with X leading zeros
String leadZero(String s, int l){
  while (s.length() < l){
    s = "0" + s;
  }
  return s;
}
}
