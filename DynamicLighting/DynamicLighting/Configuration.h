#pragma once

#define DEBUG true //Severe slowdowns when in debug mode, but allows the serial communication to be human readable
#define BAUD (115200)
#define MAX_BUFFER (128)

#define VERSION "0.4.6"

static Colour blue = Colour(255, 0, 0);
static Colour red = Colour(0, 255, 0);
static Colour yellow = Colour(255, 255, 0);
static Colour orange = Colour(255, 128, 0);
static Colour green = Colour(0, 0, 255);
static Colour cyan = Colour(0, 255, 255);
static Colour magenta = Colour(255, 0, 255);
static Colour white = Colour(255, 255, 255);
static Colour black = Colour(0, 0, 0);