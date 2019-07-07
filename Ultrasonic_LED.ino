
// Ultrasonic definitions:
int trigPin = 8;    // Trigger
int echoPin = 7;    // Echo
long duration, cm, inches;

// LED definition:
int led = 13; // the digital pin that the long LED leg is connected to through 1K resistor
// connect short LED leg directly to GND

void setup() {
  //Serial Port begin
  Serial.begin (9600);

  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inches = (duration / 2) / 74; // Divide by 74 or multiply by 0.0135

  // Send and write data to the serial monitor
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

 // LED conditions. If the distance detected is close, turn on. Otherwise turn off.
  if (cm <= 10) {
    digitalWrite(led, HIGH);
    delay(5000);
  }
  else {
    digitalWrite(led, LOW);
  }

  delay(1000);
}
