
//set pin numbers ; constants wont change

const int bluePin = 13;  //led pin
//const int ldrPin = A0;  //LDR pin
int hallPin = 5;
int buzzerPin = 8;
const int redLED = 12;
//unsigned long currentTime = mills;
const int interval = 1000;
const int interval2 = 5;
unsigned long previousMillis = 0;
int fieldState = 0; //variable to store read data
int ledState = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(bluePin, OUTPUT);  //initialize the LED pin as output
  pinMode(hallPin,INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);
}
void loop() {
  digitalWrite(redLED, HIGH);
  // print out data
  noTone(buzzerPin);
  Serial.println(digitalRead(hallPin));
  unsigned long currentMillis  = millis();
  
//read state of digital pin
fieldState = digitalRead(hallPin);

if (fieldState == HIGH) { 
  tone(buzzerPin, 293, 150); 
  //delay(1700);
  //noTone(buzzerPin);
 
      if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      // if led is on, turn off, vice versa
      if (ledState == HIGH) {
        ledState = LOW;
      }
      else {
        ledState = HIGH;
      }
      // set led with ledState
      digitalWrite(redLED, ledState);
     }
     delay(1000);
}

else {
tone(buzzerPin, 349);
 if (currentMillis - previousMillis >= interval2) {
      previousMillis = currentMillis;
      // if led is on, turn off, vice versa
      if (ledState == LOW) {
        ledState = HIGH;
      }
      else {
        ledState = LOW;
      }
      // set led with ledState
      digitalWrite(redLED, ledState);
     }
delay(100);


}

 // delay(1800);
}
  
