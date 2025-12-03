// #ifndef GLOBALS_H
// #define GLOBALS_H

// extern const int W;
// extern const int H;
// extern const float DEGTORAD;

// #endif


#ifndef GLOBALS_H
#define GLOBALS_H

extern const int W;
extern const int H;
extern const float DEGTORAD;

#endif


// This file stores global constants that are used throughout the game so you don’t have to type the same values multiple times.
// W → screen width (1200 pixels)
// H → screen height (800 pixels)
// DEGTORAD → conversion factor from degrees to radians (used for rotation and movement calculations)
// By putting these in a header file, all other files can include Globals.h and use these constants easily.