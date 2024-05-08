/*
  _lookup - Library .
  Created by: Charlie Morris 
  Last update: 07/05/24
  Released into the public domain.
*/

#include "Arduino.h"

#include "lookup.h"

char shortDay[7][5] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
char longDay[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

char shortMonth[12][5] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char longMonth[12][12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

char shortHeadingName[32][6] =  { "N", "NbE", "NNE", "NEbN", "NE", "NEbE","ENE","EbN", 
                                  "E", "EbS", "ESE", "SEbE", "SE", "EbS", "SSE", "SbE",
                                  "S", "SbW", "SSW", "SWbS", "SW", "SWbW", "WSW","WbS",
                                  "W", "WbN", "WNW", "NWbW", "NW", "NWbN", "NNW", "NbW" };
char longHeadingName[32][22] =  { "North",    "North by east",      "North-northeast",  "Northeast by north",
                                 "Northeast", "Northeast by east",  "East-northeast",   "East by north",
                                 "East",      "East by south",      "East-southeast",   "Southeast by east",
                                 "Southeast", "Southeast by south", "South-southeast",  "South by east",
                                 "South",     "South by west",      "South-southwest",  "Southwest by south",
                                 "Southwest", "Southwest by west",  "West-southwest",   "West by south",
                                 "West",      "West by north",      "West-northwest",   "Northwest by west",
                                 "Northwest", "Northwest by north", "North-northwest",  "North by west" };


// As Defined by https://www.metoffice.gov.uk/weather/guides/coast-and-sea/beaufort-scale
// MPS : Mean Wind Speed

char* lookup::BeafortScale(double mps)
{
  static char buf[16];    // Define an array to put the Beafort Scale description in 
  if (mps < 0 ) { strcpy(buf,  "err"); }        // Check for Valid input return error is not valid
  else if (mps == 0) { strcpy(buf, "Calm"); }
  else if (mps < 1) { strcpy(buf,  "Light Air"); }
  else if (mps < 3) { strcpy(buf,  "Light Breeze"); }
  else if (mps < 5) { strcpy(buf,  "Gentle Breeze"); }
  else if (mps < 7) { strcpy(buf,  "Moderate Breeze"); }
  else if (mps < 10) { strcpy(buf,  "Fresh Breeze"); }
  else if (mps < 12) { strcpy(buf,  "Strong Breeze"); }
  else if (mps < 15) { strcpy(buf,  "Near Gale"); }
  else if (mps < 19) { strcpy(buf,  "Gale"); }
  else if (mps < 23) { strcpy(buf,  "Strong Gale"); }
  else if (mps < 27) { strcpy(buf,  "Storm"); }
  else if (mps < 31) { strcpy(buf,  "Violent Storm"); }
  else { strcpy(buf, "Hurricane"); }
  return buf;
}

char* lookup::DOW(int dow, bool shortName){
  static char buf[12];    // Define an array to put the Day in
  if ((dow < 0 ) || (dow > 6)) { strcpy(buf, "err"); }   // Check for Valid input return error is not valid
  else { 
    if (shortName == true) { strcpy(buf, shortDay[dow]); } else { strcpy(buf, longDay[dow]); }
  }
  return buf;
}

char* lookup::MonthName(int monthNumber, bool shortName){
  static char buf[12];    // Define an array to put the Month in
  if ((monthNumber < 1 ) || (monthNumber > 12)) { strcpy(buf, "err"); }   // Check for Valid input return error is not valid
  else { 
    monthNumber--; // minus1 as Array starts from 0 not 1;
    if (shortName == true) { strcpy(buf, shortMonth[monthNumber]); } else { strcpy(buf, longMonth[monthNumber]); }
  }
  return buf;
}

char* lookup::CompassHeading(double heading, int CompassPoints = 8, bool shortName = true){
    static char buf[22];    // Define an array to put return Value (Compass Direction)in

    // Check for Valid Compass Points, return error
    if ((CompassPoints != 4) && (CompassPoints != 8) && (CompassPoints != 16) && (CompassPoints != 32)) { 
      strcpy(buf, "err"); 
    } else {
   
      // Ensure Heading is positive degrees and 0 - 360 (Note -90 = 270)
      if (heading < 0) {
        while (heading < -360) {heading = heading + 360;}
        heading = 360 + heading;         // e.g. degree -90 = 270
      } else {
        while (heading >= 360 ) { heading = heading - 360; }  // Ensure 0 - 360
      }
  
      double dpch = 360 / CompassPoints;     // Degrees per Compass Heading
      double offset = dpch / 2;       // Degrees before North
      heading = heading + offset; // Adjust heading 
      
      // Get the Index for the Array
      int idx = int(heading / dpch);
      if (idx > (CompassPoints - 1) ){ idx = 0; }
      idx = idx * int(32 / CompassPoints);
      // Get the Compass Direction
      if (shortName) { strcpy(buf,shortHeadingName[idx]); } else { strcpy(buf,longHeadingName[idx]); }
    }
    
    return buf;   // Return the Heading or Error
  
}
