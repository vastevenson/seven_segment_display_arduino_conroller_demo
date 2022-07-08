/*
Seven Segment Display Demo 
Author: Vincent Stevenson 
Goal: show how to write a function in C++ that can light up a 7 segment display with a digit from 0-9. 

Note I am using 220 ohm resistors (1 for each of the 7 segments)
Digit : Segments On
1: b,c
2: a,b,g,e
3: a,b,g,c,d
4: f,g,b,c
5: a,f,g,c,d
6: f,e,g,c,d
7: a,b,c
8: a,b,c,d,e,f,g
9: a,b,c,f,g
0: a,b,c,d,e,f
// above can be another map data struct in C++!
*/

// define which pins correspond to which of the seven segments: a - g
int seg_a = 4;
int seg_b = 5;
int seg_c = 6;
int seg_d = 7;
int seg_e = 8;
int seg_f = 9;
int seg_g = 10;

map<char,int> char_pin_map = 
{
	// use a map instead of arrays - better data structure for this :) 
	char_pin_map.insert(pair<char,int>('a',4));
	char_pin_map['b']=5;
};



// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(char_pin_map['a'], OUTPUT);
  pinMode(seg_b, OUTPUT);
  pinMode(seg_c, OUTPUT);
  pinMode(seg_d, OUTPUT);
  pinMode(seg_e, OUTPUT);
  pinMode(seg_f, OUTPUT);
  pinMode(seg_g, OUTPUT);
}


// write method that turns all segs ON - use for loop 

// write method that turns all segs OFF - use another for loop 

// write method that takes an int as an input and turns on the appropriate segs as needed to display the int




void blink_seg(int pin_id) {
  digitalWrite(pin_id, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin_id, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

// the loop function runs over and over again forever
void loop() {
  blink_seg(char_pin_map['a']);
}