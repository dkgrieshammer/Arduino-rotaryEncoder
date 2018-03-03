/*
* Read rotary endcoders like a champ - 
* based on the great explanations of Matthias Hertel & example code https://github.com/mathertel/RotaryEncoder
* Thx to Tim from presseverykey for ur helps https://github.com/presseverykey
*/

int pin3 = 3; // this one needs to be interruptable
int pin4 = 4;
int counter = 0;
volatile int oldState = 0;

void setup() {
  pinMode (pin3, INPUT_PULLUP);
  pinMode (pin4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin3), intercount, CHANGE);
  Serial.begin (9600);
}

void loop() {
  //  whatever man
}

// my version, thx to mathertel for your explanations :)
void intercount() {
  int sig1 = digitalRead(pin3); //if high
  int sig2= digitalRead(pin4);
  int tmpState = sig1 + 2 * sig2;
  if(tmpState == 3 && oldState == 0) {
    counter --;
    Serial.println(counter);
  }
  if(tmpState == 2 && oldState == 1) {
    counter ++;
    Serial.println(counter);
  }
  oldState = tmpState;
}
