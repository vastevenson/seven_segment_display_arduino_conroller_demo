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
int a = 4;
int b = 5;
int c = 6;
int d = 7;
int e = 8;
int f = 9;
int g = 10;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // send + receive serial monitor at 9600 baud rate 
  // note if you don't have the above line, you won't see anything in serial monitor!
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

// write method that takes an int as an input and turns on the appropriate segs as needed to display the int

void blink_all_segs(int *segs, int seg_len) {
  turn_off_all_segs(segs, seg_len);  
  delay(1000);                      
  turn_on_all_segs(segs, seg_len);  
  delay(1000);                       
}

void turn_off_all_segs(int *segs, int seg_len) {
  Serial.println("Turning off all segments...");
  for (byte i = 0; i < seg_len; i++) {
    digitalWrite(segs[i], LOW); // turn off the seg
  }
}

void turn_on_all_segs(int *segs, int seg_len) {
  Serial.println("Turning on all segments...");
  for (byte i = 0; i < seg_len; i++) {
    digitalWrite(segs[i], HIGH);
  }
}

void print_arr(int *segs, int seg_len) {
  // print out the contents of an input array
  for (int i = 0; i < seg_len; i++) {
    Serial.print(segs[i]);
  }
}

void loop() {
  Serial.println("Starting new loop!");

  int seg_len = 7;
  int segs[seg_len] = {a,b,c,d,e,f,g};
  // I had a lot of trouble dynamically calculating array length so I just hard coded it...
//  print_arr(segs, seg_len);
  // call method to turn off all the lights
  blink_all_segs(segs, seg_len);
}