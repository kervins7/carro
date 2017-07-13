#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>
SoftwareSerial BT(2, 3); //Rx,Tx
AF_DCMotor motorA(1);
Servo servo1;

void setup() {
   servo1.attach(10,600,1500);
  Serial.begin(9600);
  BT.begin(9600);
motorA.setSpeed(250);
}

void moverDerecha(){
 
      servo1.write(0);
}

void moverIzquierda(){

      servo1.write(180);
}

void moverAdelante(){
  motorA.run(FORWARD);
}

void moverAtras(){
  motorA.run(BACKWARD);
}

void parar(){
motorA.run(RELEASE);  
}

void loop() {
  
  if (BT.available() > 0) {
    char dataIn = BT.read();
    
    if ( dataIn == 'i') {
       moverIzquierda();
      delay(15);
 
     }
    
    else if ( dataIn == 'b') {
      moverAtras();
      servo1.write(90);
      delay(10);
    }
    
    else if (dataIn == 'd') {
   moverDerecha();
     delay(10);
    }
     
    else if ( dataIn == 'a') {
      moverAdelante();
      delay(15);
    }  else if ( dataIn == '1') {
      servo1.write(90);
    } 

 
   else {
      parar();
      delay(10);
    }
  }
}

