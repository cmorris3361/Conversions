# Arduino Conversions and Lookup Library
https://github.com/cmorris3361/Conversions

Charlie Morris - May 2024  

## License
Arduino Conversion and Lookup Library Copyright (C) 2024 Charlie Morris GNU GPL v3.0

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License v3.0 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/gpl.html>

## Version Control
V0.0.1 | 07/04/24 | First Version of Arduino Conversion and Lookup Library

## Know Issues
08/05/24 | v0.0.1 | Not all Heading are return when selcting 16 or 32 Heading Points 

## Things to do

## Introduction
The following is the list of Conversion and Lookup Functions

### Speed Conversion Functions
double MPHtoKPH(double mph)
double MPHtoMS(double mph)
double KPHtoMPH(double kph)
double MStoMPH(double mps)
double KtoMPH(double k)
double KtoKPH(double k)
double MPHtoK(double mph)
double KPHtoK(double kmh)

### Temperature Conversion Functions
double KtoC(double k)
double KtoF(double k)
double FtoC(double f)
double CtoF(double c)

### Distance Conversion Functions
double CMtoFeet(double cm)
double CMtoInch(double cm)
double FeettoCM(double feet)
double InchtoCM(double inch)
double YardtoMeters(double yard)
double MetertoYards(double meter)
double KMtoMile(double km)
double MilestoKM(double mile)

### Area Conversion Functions
double SqYardtoSqMeter(double sqyard)
double SqMetertoYard(double sqMeter)

### Mass Conversion Functions
double KGtoLbs(double kg)
double KGtoSt(double kg)
double KGtoSTLbs(double kg)
double LbstoKG(double lbs)
double GtoOZ(double g)
double OZtoG(double oz)

### Time Conversions

## Lookups
### Compass 
beaufortScale
compassDirection
