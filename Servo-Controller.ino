#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

Servo servo_9;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}
LiquidCrystal_I2C lcd(0x3f,16,2);
void setup() {
  lcd.begin();
  pinMode(A0+0,INPUT);
  servo_9.attach(9);
  while(1) {
      if(analogRead(A0+0) < 981){

          servo_9.write(90);
                  lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("gundogdu");
          lcd.setCursor(0,1);
          lcd.print("pencere acik"); 

      }else{

          servo_9.write(190);
                lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("gunbatti");
          lcd.setCursor(0,1);
          lcd.print("pencere kapali"); 
      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}
