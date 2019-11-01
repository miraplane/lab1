#include <Arduino.h>

const int RGB_OUT[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int R_OUT = 10;
const int G_OUT = 11;
const int B_OUT = 12;

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");
    for(int i = 0; i < 8; i++) {
      pinMode(RGB_OUT[i], OUTPUT);
      digitalWrite(RGB_OUT[i], LOW);
    }
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    if (Serial.available() > 0) {
      int dec = Serial.parseInt();
      boolean bin[] = {0, 0, 0, 0, 0, 0, 0, 0};
      
      convertDecToBin(dec, bin);
      set_rgb_led(dec, dec, dec);

      for(int i = 0; i < 8; i++) {
        digitalWrite(RGB_OUT[i], LOW);
      }
      
      for(int i = 0; i < 8; i++) {
        if(bin[i]){
          digitalWrite(RGB_OUT[i], HIGH);
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

void set_rgb_led(int r, int g, int b)
{
    analogWrite(R_OUT, 255 - r);
    analogWrite(G_OUT, 255 - g);
    analogWrite(B_OUT, 255 - b);
}
