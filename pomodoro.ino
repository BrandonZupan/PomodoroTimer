
#define RST 6
#define CS  7
#define DC  5
#define DIN 11
#define CLK 13

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(RST, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(RST, HIGH);
  digitalWrite(CS, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DIN, HIGH);
  digitalWrite(CLK, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

}
