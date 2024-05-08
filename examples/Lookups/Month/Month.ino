#include  <lookup.h>

lookup LOOKUP;

void setup() {
  Serial.begin(115200);  // Start the Serial Monitor
  while (!Serial) { delay(100); }
  Serial.println("Lookup Started.");

  for (int mon = -1 ; mon < 14; mon++)
  {
    String shortMonth = LOOKUP.MonthName(mon, true);     // Lookup the Short Month from month number
    String longMonth =  LOOKUP.MonthName(mon, false);     // Lookup the Long Month from month number

    Serial.printf("Month Name for %i is %s (%s).\n", mon, longMonth, shortMonth);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
