

#include "TFT9341Touch.h"

int waterSensorPin = A0; 

tft9341touch LcdTouch (10, 9, 7, 2); //cs, dc ,tcs, tirq

void setup() {
  Serial.begin(9600);
  LcdTouch.begin();
  LcdTouch.clearButton();
  LcdTouch.setRotation(0);//0,1,2,3
  LcdTouch.setTextSize (2);
  LcdTouch.setCursor (40, 40);
  LcdTouch.set(3780, 372, 489, 3811); //Calibration

  screenMain();
}

void loop() {
  uint16_t x, y;
  String str;

  int sensorValue = analogRead(waterSensorPin);

  if (sensorValue >500) {
    Serial.print("Slip hazard! sensorValue: ");
    Serial.println(sensorValue);
    LcdTouch.drawButton(2, 170,  10, 140, 220, 10, RED, WHITE, "ALARM!", 3);  
    LcdTouch.drawButton(1, 10, 10 , 150, 220, 10, BLUE, BLACK, "Continue!", 2); 
    
    delay(1000);
   }
  else
  {
    Serial.println("no water");
  }

  
  delay(500);


  
  if (LcdTouch.touched())
  {
    LcdTouch.readTouch();
    x = LcdTouch.xTouch;
    y = LcdTouch.yTouch;

    int ButtonNum = LcdTouch.ButtonTouch(x, y);
  

    if (ButtonNum == 1) 
    {
      screen1();
      screenMain();
    }
    if (ButtonNum == 2) 
    {
      screen1();
      screenMain();
    }
    
  }
}


void screenMain() {
  LcdTouch.fillScreen (CYAN);
  LcdTouch.drawButton(1, 10, 10 , 300, 220, 10,MAGENTA , WHITE, "START YOUR WAY", 3); // NumButton, x, y, width, height, r, Color, textcolor, label, textsize);

}


void screen1() {
  LcdTouch.fillScreen (MAGENTA);
  LcdTouch.drawButton(1, 10, 10 , 150, 220, 10, CYAN, BLACK, "I finished!", 2); 
  LcdTouch.drawButton(2, 170,  10, 140, 220, 10, RED, WHITE, "ALARAM!",3);
 // while (!LcdTouch.touched());
}
