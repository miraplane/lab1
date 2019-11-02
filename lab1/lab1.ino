#include <Arduino.h>

const int RGB_OUT[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");
    for(int i = 0; i < 8; i++) {
      pinMode(RGB_OUT[i], OUTPUT);
      digitalWrite(RGB_OUT[i], HIGH);
    }
}

void loop() 
{
    if (Serial.available() > 0) {
      int dec = Serial.parseInt();
      boolean bin[] = {0, 0, 0, 0, 0, 0, 0, 0};
      
      convertDecToBin(dec, bin);

      for(int i = 0; i < 8; i++) {
        digitalWrite(RGB_OUT[i], HIGH);
      }
      
      for(int i = 0; i < 8; i++) {
        if(bin[i]){
          digitalWrite(RGB_OUT[i], LOW);
        }
      }
      delay(1000);
    }
}

void convertDecToBin(int dec_number, boolean bin_number[]) {
  for(int i = 7; i >= 0; i--) {
    if (pow(2, i) <= dec_number) {
      dec_number = dec_number - pow(2, i);
      bin_number[8-(i+1)] = 1;
    }
  }
}
