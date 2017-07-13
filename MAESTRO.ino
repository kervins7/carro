#include <Esplora.h>
#include<SoftwareSerial.h>

SoftwareSerial BT(8,7);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
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
  else if(xizquierda<-300)
  {
    BT.print("i");
    }
  else{
    BT.print('q');
  }
  

 if (adelante==LOW && atras==HIGH)
  {
    BT.println("a");
  }
 if (adelante==HIGH  && atras==LOW)
  {
    BT.println("b");
  }  
  delay(10);
 }


