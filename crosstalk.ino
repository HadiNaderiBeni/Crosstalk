/*
  Arduino Crosstalk Measurement - Frequency Sweep

  Description:
  This code generates a square-wave signal on digital pin D9.
  The signal frequency is swept through different values so that
  crosstalk can be measured on a nearby wire, PCB trace, or signal line
  using an oscilloscope.

  Connections:
    D9  -> Aggressor signal line
    GND -> Oscilloscope ground
    CH1 -> D9 signal
    CH2 -> Nearby victim line

  Author:
  Hadi Naderi Beni
*/

const int outputPin = 9;

// Frequencies used for the sweep, in Hz
const unsigned int sweepFrequencies[] = {
  10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000
};

const int numberOfFrequencies =
  sizeof(sweepFrequencies) / sizeof(sweepFrequencies[0]);

// Duration of each frequency step in milliseconds
const unsigned long durationPerFrequency_ms = 5000;

// Pause between two frequency steps
const unsigned long pauseBetweenFrequencies_ms = 1000;

void setup() {
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);

  Serial.begin(9600);
  delay(1000);

  Serial.println("======================================");
  Serial.println("Arduino Crosstalk Measurement");
  Serial.println("Frequency Sweep Started");
  Serial.println("Output pin: D9");
  Serial.println("======================================");
}

void loop() {
  for (int i = 0; i < numberOfFrequencies; i++) {
    unsigned int frequency = sweepFrequencies[i];

    Serial.print("Generating frequency: ");
    Serial.print(frequency);
    Serial.println(" Hz");

    generateSquareWave(frequency, durationPerFrequency_ms);

    digitalWrite(outputPin, LOW);
    delay(pauseBetweenFrequencies_ms);
  }

  Serial.println("Sweep completed. Restarting...");
  delay(2000);
}

void generateSquareWave(unsigned int frequency, unsigned long duration_ms) {
  unsigned long halfPeriod_us = 500000UL / frequency;
  unsigned long startTime_ms = millis();

  while (millis() - startTime_ms < duration_ms) {
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(halfPeriod_us);

    digitalWrite(outputPin, LOW);
    delayMicroseconds(halfPeriod_us);
  }
}