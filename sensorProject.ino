const int trigPin = 9;
const int echoPin = 10;

const int ledGreen = 5;
const int ledYellow = 6;
const int ledRed = 7;
const int buzzerPin = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  long duration = pulseIn(echoPin, HIGH, 30000);
  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn all LEDs off
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);

  int beepDelay = 400; // default slowest beep

  if (duration == 0) {
    Serial.println("No echo.");
    noTone(buzzerPin);
  } else if (distance <= 6) {
    digitalWrite(ledRed, HIGH);
    tone(buzzerPin, 1000, 100); // high pitch
    beepDelay = 175; // fast beep
  } else if (distance <= 12) {
    digitalWrite(ledYellow, HIGH);
    tone(buzzerPin, 800, 100); // medium pitch
    beepDelay = 325; // medium beep
  } else {
    digitalWrite(ledGreen, HIGH);
    tone(buzzerPin, 600, 100); // low pitch
    beepDelay = 500; // slow beep
  }

  delay(beepDelay);
}
