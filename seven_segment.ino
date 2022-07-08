/*
  Seven Segment Display Demo
  Author: Vincent Stevenson
  Goal: show how to write a function in C++ that can light up a 7 segment display with a digit from 0-9.

  Note I am using 220 ohm resistors (1 for each of the 7 segments)
*/

// define which pins correspond to which of the seven segments: a - g
// https://theorycircuit.com/7-segment-arduino-interface/
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

void blink_all_segs() {
  turn_off_all_segs();
  delay(500);
  turn_on_all_segs();
  delay(500);
}

void turn_off_all_segs() {
  int seg_len = 7;
  int segs[seg_len] = {a, b, c, d, e, f, g};
  Serial.println("Turning off all segments...");
  for (byte i = 0; i < seg_len; i++) {
    digitalWrite(segs[i], LOW); // turn off the seg
  }
}

void turn_on_all_segs() {
  int seg_len = 7;
  int segs[seg_len] = {a, b, c, d, e, f, g};
  Serial.println("Turning on all segments...");
  for (byte i = 0; i < seg_len; i++) {
    digitalWrite(segs[i], HIGH);
  }
}

void display_dig(int *arr, int arr_len) {

  turn_off_all_segs();

  // turn on the segments to display a given digit
  for (byte i = 0; i < arr_len; i++) {
    digitalWrite(arr[i], HIGH);
  }
}

void loop() {
  Serial.println("Starting new loop!");


  // note that we need to hardcode and pass len of array to C++ functions
  // this is because in C++, we are just passing the location in memory (pointer) of the array to the function
  // the pointer doesn't know how big its array is!

  // call method to blink all the lights for testing
  //  blink_all_segs();

  // define the segments that map to each pin
  int one_dig[2] = {b, c};
  int two_dig[5] = {a, b, g, e, d};
  int three_dig[5] = {a, b, g, c, d};
  int four_dig[4] = {f, g, b, c};
  int five_dig[5] = {a, f, g, c, d};
  int six_dig[5] = {f, e, g, c, d};
  int seven_dig[3] = {a, b, c};
  int eight_dig[7] = {a, b, c, d, e, f, g};
  int nine_dig[5] = {a, b, c, f, g};
  int zero_dig[6] = {a, b, c, d, e, f};

  display_dig(zero_dig, 6);
  delay(1000);
  display_dig(one_dig, 2);
  delay(1000);
  display_dig(two_dig, 5);
  delay(1000);
  display_dig(three_dig, 5);
  delay(1000);
  display_dig(four_dig, 4);
  delay(1000);
  display_dig(five_dig, 5);
  delay(1000);
  display_dig(six_dig, 5);
  delay(1000);
  display_dig(seven_dig, 3);
  delay(1000);
  display_dig(eight_dig, 7);
  delay(1000);
  display_dig(nine_dig, 5);
  delay(1000);
}