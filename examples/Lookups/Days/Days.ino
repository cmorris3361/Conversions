#include  <lookup.h>

lookup lk;

void setup() {
  Serial.begin(115200);  // Start the Serial Monitor
  while (!Serial) { delay(100); }
  Serial.println("Lookup Started.");

  for (int day = -1 ; day < 8; day++)
  {
    String shortDOW = lk.DOW(day, false);   // Lookup the Short day of the Week
    String longDOW = lk.DOW(day, true);     // Lookup the Long day of the Week
       
    Serial.printf("Day of the week %i is %s (%s).\n", day, shortDOW, longDOW);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
