#include <Joystick.h>

Joystick_ Joystick;

int RzAxis = 512;
int RxAxis = 512;
int RyAxis = 512;
int Slider = 0;
int Throttle = 0;
int Button1 = 0;
int Button2 = 0;

void setup() {
  Joystick.begin();
  pinMode(2, INPUT_PULLUP); // Set pin 2 as an input with a pullup resistor
  pinMode(3, INPUT_PULLUP); // Set pin 3 as an input with a pullup resistor
}

void loop() {
  // Read the analog values from the joystick axes
  RzAxis = analogRead(A0);
  RxAxis = analogRead(A1);
  RyAxis = analogRead(A2);
  Slider = analogRead(A3);
  Throttle = analogRead(A4);
  
  // Read the state of the buttons
  Button1 = digitalRead(2);
  Button2 = digitalRead(3);
  
  // Send the joystick data to the computer
  Joystick.setRzAxis(RzAxis);
  Joystick.setRxAxis(RxAxis);
  Joystick.setRyAxis(RyAxis);
  Joystick.setRudder(Slider);
  Joystick.setThrottle(Throttle);
  Joystick.setButton(0, Button1);
  Joystick.setButton(1, Button2);
  
  delay(10); // Short delay to prevent data overflow
}
