const int trigPin = 9;
const int echoPin = 10;
const int alertPin = 13;

const int socialDistanceThreshold = 100; 

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertPin, OUTPUT);

  digitalWrite(alertPin, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  long distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < socialDistanceThreshold) {
    digitalWrite(alertPin, HIGH);
    Serial.println("Warning: Maintain social distance!");
  } else {
    digitalWrite(alertPin, LOW);
  }

  delay(500);
}
