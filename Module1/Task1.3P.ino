const int led = 13; //LED positive terminal to the digital pin 13
const int sensor = 2; //Signal pin of sensor to digital pin 2
const int trigPin = 8; // HC-SR04 trigger pin to digital pin 8
const int echoPin = 9; //HC-SR04 echo pin to digital pin 9
volatile int state = LOW;

void setup() {
  //Initialise LED and PIR sensor
  pinMode(led, OUTPUT); //LED is the output
  pinMode(sensor, INPUT); //Sensor is the input

  //Initialize HC-SR04
  pinMode(trigPin, OUTPUT); //HC-SR04 trigger pin is an output
  pinMode(echoPin, INPUT); //HC-SR04 echo pin is an input
  
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(sensor), handleInterrupt, CHANGE);
}

void loop() {
  long duration, distance;

  //Clear the trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Send a 10-microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Read the echo pin
  duration = pulseIn(echoPin, HIGH);

  //Calculate distance in cm
  distance = (duration / 2) * 0.0344;

  //Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); //Delay between distance measurements
}

void handleInterrupt() {
    int val = digitalRead(sensor);
    
    if (val == HIGH) {
      digitalWrite(led, HIGH);

      if (state == LOW) {
        Serial.println("Motion detected");
        state = HIGH;
      }
    }
    else {
      digitalWrite(led, LOW);

        if (state == HIGH) {
          Serial.println("Motion has stopped");
          state = LOW;
        }
    }
}
