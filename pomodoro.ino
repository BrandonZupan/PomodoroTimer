#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//Define display object
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
  Serial.begin(9600);

  //Init display
  display.begin();
  display.clearDisplay();

  //Set contrast
  display.setContrast(30);

  //Initialize text display
  display.setTextSize(2);
  display.setTextColor(BLACK);
}

void loop() {
  uint32_t i;
  String out = "**:**";
  while(1){
    for(i = 65; i > 0; i--){
      out = secondToMinute(i);
      display.setCursor(20, 14);
      display.print(out);
      display.display();
      delay(1000);
      display.clearDisplay();
    }
  }
}

//Convert a time in seconds into minutes and seconds
String secondToMinute(uint32_t seconds){
  String outString = "**:**";
  uint8_t minutes;
  String minString = "**";
  uint8_t remSecs;
  String secString = "**";

  static uint8_t secFlag = 0x01;
  //divide by 60 to get minutes
  minutes = seconds / 60;
  remSecs = seconds % 60;

  //Put this into the string
  minString = String(minutes);
  secString = String(remSecs);

  if(secFlag == 0x01){
    outString = minString + ':' + secString;
    secFlag = 0x00;
  }
  else{
    outString = minString + ' ' + secString;
    secFlag = 0x01;
  }
  return (outString);
}
