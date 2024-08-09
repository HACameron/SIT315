const int led = 13; //LED positive terminal to the digital pin 13
const int sensor = 2; //Signal pin of sensor to digital pin 5
volatile int state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); //LED is the output
  pinMode(sensor, INPUT); //Sensor is the input
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(sensor), handleInterrupt, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
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
