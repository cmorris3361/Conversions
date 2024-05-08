/*--------------------------------------------------------------------------*
 * Arduino Conversion and Lookup Library                                    *
 * Charlie Morris 2024                                                      *
 *                                                                          *
 * Arduino Conversion and Lookup  Library Copyright (C) 2024 Charlie Morris *
 * and licensed under GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html   *
 *--------------------------------------------------------------------------*/

#ifndef conversions_h
#define conversions_h

#include "Arduino.h"

class convert
{
    public:

    // Speed Conventions
    double MPHtoKPH(double mph);
    double MPHtoMS(double mph);
    double KPHtoMPH(double kph);
    double MStoMPH(double mps);

    double KtoMPH(double k);
    double KtoKPH(double k);
    double MPHtoK(double mph);
    double KPHtoK(double kmh);


    // Temperature Conventions
    double KtoC(double k);
    double KtoF(double k);
    double FtoC(double f);
    double CtoF(double c);

    // Distance Conventions
    double CMtoFeet(double cm);
    double CMtoInch(double cm);
    double FeettoCM(double feet);
    double InchtoCM(double inch);
    double YardtoMeter(double yard);
    double MetertoYard(double meter);
    double KMtoMile(double km);
    double MiletoKM(double mile);


    // Area Conventions
    double SqYardtoSqMeter(double sqyard);
    double SqMetertoYard(double sqMeter);

    // Mass Conventions
    double KGtoLbs(double kg);
    double KGtoSt(double kg);
    double KGtoSTLbs(double kg);
    double LbstoKG(double lbs);
    double GtoOZ(double g);
    double OZtoG(double oz);

    // Time
    String S2MS(unsigned long ms);
    String MS2DHMS(unsigned long ms);



}

#endif