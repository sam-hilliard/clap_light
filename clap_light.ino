#include <Servo.h>

Servo lightSwitch;
int mic = 2;

int micVal = 0;
int clap = 0;
long timeFirst;
long timeSecond;
long timeBetween;
boolean lightOn = false;

void setup() {
  pinMode(mic, INPUT);
  lightSwitch.attach(3);
  lightSwitch.write(90);
}

void loop() {
  micVal = digitalRead(mic);

  if (micVal == 1) {
    clap++;

    if (clap == 1) {
      timeFirst = millis();
      delay(100);
    }

    if (clap == 2) {
      timeSecond = millis();
      delay(100);
    }

    timeBetween = abs(timeSecond - timeFirst);
    if (timeBetween > 200 and timeBetween < 1200) {
      if (lightOn) {
        lightSwitch.write(120);
        lightOn = false;
      }
      else {
        lightSwitch.write(60);
        lightOn = true;
      }
    }
  }

  if (clap >= 2) {
    clap = 0;
  }
}
