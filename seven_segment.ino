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

void blink_all_segs() {
  int delay_time_ms = 200;
  for (int i = 0; i < 3; i++) {
    turn_off_all_segs();
    delay(delay_time_ms);
    turn_on_all_segs();
    delay(delay_time_ms);
  }
  turn_off_all_segs();
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
  for (byte i = 0; i < arr_len; i++) {
    digitalWrite(arr[i], HIGH);
  }
}

void display_num(int num) {
  // given a num, display the num on the seven segment display
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

  turn_off_all_segs();

  switch (num) {
    case 0 :
      display_dig(zero_dig, 6);
      break;
    case 1 :
      display_dig(one_dig, 2);
      break;
    case 2 :
      display_dig(two_dig, 5);
      break;
    case 3 :
      display_dig(three_dig, 5);
      break;
    case 4 :
      display_dig(four_dig, 4);
      break;
    case 5 :
      display_dig(five_dig, 5);
      break;
    case 6 :
      display_dig(six_dig, 5);
      break;
    case 7 :
      display_dig(seven_dig, 3);
      break;
    case 8 :
      display_dig(eight_dig, 7);
      break;
    case 9 :
      display_dig(nine_dig, 5);
      break;
  }
}

void test_blink_all_segs() {
  int delay_time_ms = 1000;
  delay(delay_time_ms);
  blink_all_segs();
  delay(delay_time_ms);
}

void test_display_all_nums() {
  for (int i = 0; i <= 9; i++) {
    display_num(i);
    delay(1000);
  }
}

void loop() {
  Serial.println("Starting new loop!");
  // test_blink_all_segs();
  test_display_all_nums();
}