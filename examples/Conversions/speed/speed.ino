
#include <conversions.h>

void setup(){
  double speed = 70;
  Serial.printf("Speed of %fMPH = %fKPH.", speed, cvtMPHtoKPH(speed));
  Serial.printf("Speed of %fMPH = %fMpS.", speed, cvtMPHtoMPS(speed));
  
}

void loop() {
}