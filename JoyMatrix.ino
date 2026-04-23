#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);
const int PIN_X = A0, PIN_Y = A1, PIN_SW = 2;
int lastX = -1, lastY = -1, lastZ = -1;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_SW, INPUT_PULLUP);
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
}

void loop() {
  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);
  bool zMode = (digitalRead(PIN_SW) == LOW);

  int valY = map(y, 0, 1023, 0, 127);
  int mX = map(x, 0, 1023, 0, 7);
  int mY = map(y, 0, 1023, 0, 7);

  if (zMode) {
    if (abs(valY - lastZ) > 1) {
      sendMIDI(176, 22, valY);
      lastZ = valY;
    }
  } else {
    int valX = map(x, 0, 1023, 0, 127);
    if (abs(valX - lastX) > 1 || abs(valY - lastY) > 1) {
      sendMIDI(176, 20, valX);
      sendMIDI(176, 21, valY);
      lastX = valX; lastY = valY;
    }
  }
  lc.clearDisplay(0);
  lc.setLed(0, mY, mX, true);
  delay(10);
}

void sendMIDI(byte s, byte c, byte v) {
  Serial.write(s); Serial.write(c); Serial.write(v);
}