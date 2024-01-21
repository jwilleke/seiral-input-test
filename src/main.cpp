#include <Arduino.h>

// zoomkat 7-30-11 serial I/O string test
// type a string in serial monitor. then send or enter
// for IDE 0019 and later

String readString;

void setup() {
  Serial.begin(115200);
  Serial.println("serial test 0021"); // so I can keep track of what is loaded
}

void loop() {
  
  readString="";
  while (Serial.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    char c = Serial.read();
    readString += c;
  }
  
  if (readString.length() >0) {
    Serial.println(readString);
    Serial.println("Move to Uppercase: ");
    readString.toUpperCase();
    Serial.println(readString);

    readString="";
  } 
}