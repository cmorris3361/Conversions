/*
  Lookup  Library .
  Created by: Charlie Morris 
  Last update: 07/05/24
  Released into the public domain.
*/

#ifndef lookup_h
#define lookup_h

#include "Arduino.h"

class lookup
{
  public:

  char* BeafortScale(double mps);
  char* DOW(int dow, bool shortName);
  char* MonthName(int monthNumber, bool shortName);
  char* CompassHeading(double heading, int CompassPoints, bool shortName);


};

#endif
