/**
 * 7-segments display example code
 * 
 * This code is distributed under The MIT License (MIT)
 * Copyright (c) 2014 victornpb - www.vitim.us
 * created on 18-nov-2014
 */

#define C_ANODE false
const uint8_t myDisplayPins[8] = {3,4,5,6,7,8,9,10}; //dp A B C D E F G

byte font[] = {
  B1111110, //[0] => "0"
  B0110000, //[1] => "1"
  B1101101, //[2] => "2"
  B1111001, //[3] => "3"
  B0110011, //[4] => "4"
  B1011011, //[5] => "5"
  B1011111, //[6] => "6"
  B1110000, //[7] => "7"
  B1111111, //[8] => "8"
  B1111011, //[9] => "9"
  B1110111, //[10] => "A"
  B0000001, //[11] => "dash"
};

void setup(){
 display7Setup(myDisplayPins); //configure myDisplayPins as outputs
}

void loop(){
  
  display7(myDisplayPins, font[0]); //display "0"
  delay(1000);
  display7(myDisplayPins, font[9]); //display "A"
  delay(1000);
  display7(myDisplayPins, font[11]); //display "-"
  delay(1000);
  display7(myDisplayPins, B00000000); //turn all segments OFF
  delay(1000);

  //count 0 to 9
  for(int i=0; i<=9; i++){
    display7(myDisplayPins, font[i]);
    delay(1000);
  }
}

/* Configure pins as outputs */
void display7Setup(const uint8_t displayPins[]){
  for(uint8_t i=0; i<8; ++i){
    pinMode(displayPins[i], OUTPUT);
  }
}

/* Function that writes a bitmap to a 7-segment display */
void display7(const uint8_t displayPins[], byte bitmap){
  if (C_ANODE) { bitmap = ~bitmap; }
  for (uint8_t i=0; i<8; ++i) {
    digitalWrite(displayPins[7-i], (bitmap & 0x1)?HIGH:LOW);
    bitmap >>= 1;
  }
}
