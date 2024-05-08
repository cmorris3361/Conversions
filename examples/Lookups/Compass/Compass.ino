#include  <lookup.h>

lookup LOOKUP;

void setup() {
  Serial.begin(115200);  // Start the Serial Monitor
  while (!Serial) { delay(100); }
  Serial.println("Lookup Started.");

  for (int degs = 0 ; degs < 360; degs += 10)
  {
    String sHeading = LOOKUP.CompassHeading(degs, 16, true);
    String lHeading = LOOKUP.CompassHeading(degs, 16, false);
    
    Serial.printf("The heading for Degree %i is %s (%s)\n", degs, lHeading, sHeading);
    
  }
} 

void loop() {
  // put your main code here, to run repeatedly:

}
