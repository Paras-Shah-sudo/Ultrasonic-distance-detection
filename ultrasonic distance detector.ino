#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define trigPin 9
#define echoPin 8

Adafruit_SH1106 display(SEEK_SET);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();
}

void loop() {
  float duration;
  float distance_cm;
  float distance_in;
  
  digitalWrite(trigPin, LOW); //PULSE ___|---|___
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance_cm = (duration/2) / 29.15;
  distance_in = (duration/2) / 74.07;

  display.setCursor(25,0); //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Distance Meter");

  display.setCursor(10,20); //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(distance_cm);
  display.setCursor(90,20);
  display.setTextSize(1);
  display.println("cm");

  display.setCursor(10,45); //oled display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(distance_in);
  display.setCursor(90,45);
  display.setTextSize(1);
  display.println("in");

  display.display();

  delay(500);
  display.clearDisplay();

  //for debugging
  Serial.println(distance_cm);
  Serial.println(distance_in);
}