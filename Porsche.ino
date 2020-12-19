#define in2 7
#define in4 10
//input 2 op L289N = 7 op arduino, hoog is motor A aan.
//input 4 op L289N = 10 op arduino, hoog is motor A aan.

void setup() {
  pinMode(in2, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in2, HIGH);
  goLeft();
}

void loop() {
  goLeft();
  delay(3000);
  stopDriving();
  delay(3000);
  goRight();
  delay(3000);
  stopDriving();
  delay(3000);
  forward();
  delay(3000);
  stopDriving();
  delay(3000);
}

void goLeft(){  
  digitalWrite(in2, LOW);
  digitalWrite(in4, HIGH);
}

void goRight(){
  digitalWrite(in2, HIGH);
  digitalWrite(in4, LOW);
}

void forward(){
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
}

void stopDriving(){
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
}
