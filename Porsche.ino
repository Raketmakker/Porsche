#include <AltSoftSerial.h>

#define in2 7
#define in4 10
//input 2 op L289N = 7 op arduino, hoog is motor A aan.
//input 4 op L289N = 10 op arduino, hoog is motor B aan.

char task = ' ';
AltSoftSerial BTserial; 
// https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html

void setup() {
  pinMode(in2, OUTPUT);
  pinMode(in4, OUTPUT);
  BTserial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        task = BTserial.read();
        BTserial.write(task);

        switch(task){
          case 'L':
            goLeft();
            break;
          case 'R':
            goRight();
            break;
          case 'F':
            forward();
            break;
          default:
            stopDriving();
            break;
        }
    }
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
