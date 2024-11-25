// Ultrasonic sensor pins
const int trigPin = 2;      // Trigger pin of ultrasonic sensor
const int echoPin = 3;      // Echo pin of ultrasonic sensor

void setup() {
  // Initialize serial communication for Bluetooth
  Serial.begin(9600);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Measure distance using the ultrasonic sensor
  long distance = measureDistance();

  // Check if an object is detected
  if (distance <200 && distance > 0) { 
    Serial.println("Object Detected");  // Send "Object Detected" message
    Serial.println(distance);
  } else {
    Serial.println("No Object");        // Send "No Object" message
  }

  delay(200); // Wait for 1 second before the next reading
}

// Function to measure distance using the ultrasonic sensor
long measureDistance() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin to get the pulse duration
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;

  return distance;
}
