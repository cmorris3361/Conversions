#include  <lookup.h>

lookup lk;

void setup() {
  Serial.begin(115200);  // Start the Serial Monitor
  while (!Serial) { delay(100); }
  Serial.println("Lookup Started.");

  for (double mps = - 1; mps < 34; mps++)
  {
    char * BeafortScale = lk.BeafortScale(mps); // Define a Char Array to out the Beafort Scale in
    Serial.printf("BeafortScale value for %f m/s is %s.\n", mps, BeafortScale );
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
