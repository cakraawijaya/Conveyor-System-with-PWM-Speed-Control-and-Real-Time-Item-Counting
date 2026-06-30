// global variable initialization
#define PB1_PIN PD2 // PD2 pin to push button 1
#define ENA_PIN PD3 // PD3 pin to enable motor A
#define PB2_PIN PD4 // PD4 pin to push button 2
#define IN1_PIN PD5 // PD5 pin to rotate the motor backward
#define IN2_PIN PD6 // PD6 pin to rotate the motor forward
#define PTM_PIN PC0 // PC0 pin to potentiometer

boolean state1 = false, state2 = false; // initialize the status of digital readings on push buttons 1 and 2 into boolean data type
int pot = 0; // initialize the analog reading on potentiometer into integer data type

// Method: setup
void setup() {
  pinMode(PB1_PIN, INPUT_PULLUP);     // PD2 pin is used as an input
  pinMode(ENA_PIN, OUTPUT);           // PD3 pin is used as an output
  pinMode(PB2_PIN, INPUT_PULLUP);     // PD4 pin is used as an input
  pinMode(IN1_PIN, OUTPUT);           // PD5 pin is used as an output
  pinMode(IN2_PIN, OUTPUT);           // PD6 pin is used as an output
  pinMode(PTM_PIN, INPUT_PULLUP);     // PD7 pin is used as an input
}

// Method: loop
void loop() {
  pot = map(analogRead(PTM_PIN), 0, 1023, 0, 255); analogWrite(ENA_PIN, pot); // motor speed control with PWM
  forward(); // calling the forward method
  reverse(); // calling the reverse method
  delay(1000); // delay -> 1 second
}

// Method: forward
void forward(){
  state1 = digitalRead(PB1_PIN); // digital readout of button 1
  if(digitalRead(IN2_PIN)==LOW && state1==LOW){ // if button 1 is pressed when the motor is off then:
    digitalWrite(IN1_PIN, LOW); digitalWrite(IN2_PIN, HIGH); state1 = true; // motor rotation will be clockwise
  }
  else if(digitalRead(IN2_PIN)==HIGH && state1==LOW){ // if button 1 is pressed while the motor is running then :
    digitalWrite(IN1_PIN, LOW); digitalWrite(IN2_PIN, LOW); state1 = true; // the motor will be shut down as soon as possible
  }
}

// Method: reverse
void reverse(){
  state2 = digitalRead(PB2_PIN); // digital readout of button 2
  if (digitalRead(IN1_PIN)==LOW && state2==LOW) { // if button 2 is pressed when the motor is off then:
    digitalWrite(IN1_PIN, HIGH); digitalWrite(IN2_PIN, LOW); state2 = true; // motor rotation will be counterclockwise
  }
  else if(digitalRead(IN1_PIN)==HIGH && state2==LOW){ // if button 2 is pressed while the motor is running then :
    digitalWrite(IN1_PIN, LOW); digitalWrite(IN2_PIN, LOW); state2 = true; // the motor will be shut down as soon as possible
  }
}
