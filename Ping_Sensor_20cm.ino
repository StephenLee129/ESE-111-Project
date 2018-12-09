#define trigPin 13 // trig pin 13 on Arduino
#define echoPin 12 // echo pin 12 on Arduino
#define ledPin 2   // LED pin 2 on Arduino
#define buzzerPin 7   // buzzer pin 7 on Arduino

void setup() {
  //Serial.begin (9600); // serial monitor for testing purposes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); // trigPin starts low
  delayMicroseconds(10); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // duration that trigPin is set to HIGH
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;   // calculate distance in centimeters

  //Serial.println(distance); // prints distance (for testing)

  if (distance > 0 && distance < 20) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
