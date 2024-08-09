const int led = 13; //LED positive terminal to the digital pin 13
const int sensor = 5; //Signal pin of sensor to digital pin 5
int state = LOW;
int val = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); //LED is the output
  pinMode(sensor, INPUT); //Sensor is the input
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  if (val == HIGH) {
    digitalWrite(led, HIGH);
    delay(500);

    if (state == LOW) {
      Serial.println("Motion detected");
      state = HIGH;
    }
  }
  else {
    digitalWrite(led, LOW);
    delay(500);

    if (state == HIGH) {
      Serial.println("Motion has stopped");
      state = LOW;
    }
  }
}
