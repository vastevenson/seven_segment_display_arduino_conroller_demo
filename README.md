### Arduino Seven Segment Display Controller Demo

Goal: demonstrate how to have Arduino control a seven segment display to display digits from 0 through 9 at one-second intervals on a loop. 

Link to video demo: https://youtu.be/NGkCj7XrylE

Link to image of segment-to-character map: https://theorycircuit.com/7-segment-arduino-interface/ (you'll need this to wire things up correctly!)
To set up your Arduino, make sure you connect each pin to its corresponding segment: 
```
int a = 4;
int b = 5;
int c = 6;
int d = 7;
int e = 8;
int f = 9;
int g = 10;
```

This example is using a common cathod seven segment display. For this type, the common wire goes to ground and which ever segments are sent a higher voltage (5V) will be illuminated. 

If your seven segment display is a common annode, then the common wire will instead go to 5V side and when you set voltage to LOW (0V) on a given pin, it will make that segment illuminate - which will require code changes. 

Also make sure that you are using one 220 ohm resistor on each pin of the seven segment display to ensure that you don't burn out any LEDs via short circuits AND provide equal brightness to all digits as digits like `8` that have all segments illuminated can show up dimmer than digits like `1` that only have 2 segments illuminated.

To build on this code, we can write a function that just takes an int as an argument and will use a switch statement to look up where the array is containing the appropriate pins to light up for that given segment, like the digit `2` requires segments {a, b, g, e, d} to be illuminated.

Relative to other languages like Python, C++ (the language Arduino is using) has a hard time determining the size of an array that is passed to a function. When you pass an array to a function in C++, you are really just passing a pointer (a memory location of the first element in the array) to a function, but the pointer itself (the memory address) does NOT have any info on the size of the downstream array - so we pass in the size of the array (such as calls to the `display_dig` function): 

Example of passing an array to a function in C++: 
`display_dig(zero_dig, 6);` 
Note how we need to tell `display_dig()` that the size of the array we passed in `zero_dig` has 6 elements in it. 

In terms of best programming styles, I highly recommend creating functions that don't take any inputs - see the `turn_on_all_segs()` function. This encapsulates its logic and makes it easier for other developers to call your function as they won't need to know which inputs and their types are needed (none is simplest!). 
