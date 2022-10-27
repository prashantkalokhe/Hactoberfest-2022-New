#include "LedControl.h"

LedControl lc=LedControl(7,6,5,1);
int incomingByte = 0; 
void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps


 lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}
byte smile[8]=  {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};  
   byte neutral[8]= {0x3C,0x42,0xA5,0x81,0x81,0xBD,0x42,0x3C,};  
   byte sad[8]=  {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C,};  
void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    switch(incomingByte){

      case 1 :{
        printByte(smile);
        break;
      }

      case 2 : {
         printByte(sad);
        break;
      }

      case 3 : {
        printByte(neutral);
        break;
      }
              
    }

 
  }
  

}

void printByte(byte character [])  
 {  
  int i = 0;  
  for(i=0;i<8;i++)  
  {  
   lc.setRow(0,i,character[i]);  
  }  
 }  
