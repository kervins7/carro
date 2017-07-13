#include <Esplora.h>
#include <Mouse.h>
#include<SoftwareSerial.h>

SoftwareSerial BT(8,7);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
   Mouse.begin();
}

void loop() {
   
  int adelante=Esplora.readButton(SWITCH_UP);
  int atras=Esplora.readButton(SWITCH_DOWN);
 int xderecha = Esplora.readJoystickX();
 int xizquierda=Esplora.readJoystickX();

if(xderecha>300)
{
  BT.print("d");
  }
  if(xizquierda<-300)
  {
    BT.print("i");
    } 
  

 if (adelante==LOW && atras==HIGH)
  {
    BT.print("a");
  }
 if (adelante==HIGH  && atras==LOW)
  {
    BT.print("b");
  }  
  delay(10);
 }


