#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//Define display object
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
  Serial.begin(9600);

  //Init display
  display.begin();

  //Set contrast
  display.setContrast(30);

  //Initialize text display
  display.setTextSize(2);
  display.setTextColor(BLACK);
}

void loop() {
  uint32_t i;
  //Make it count down from 100
  for(i = 10; i > 0; i--){
      display.clearDisplay();
      display.setCursor(30,17);
      display.print(i);
      display.display();
      delay(1000);
  }
}
