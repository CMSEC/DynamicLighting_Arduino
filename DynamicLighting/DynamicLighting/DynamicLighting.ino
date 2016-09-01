/*
 Name:		DynamicLighting_Arduino
 Author:	Connor Widtfeldt
 Github:	https://github.com/CMSEC/DynamicLighting_Arduino/
 Website:	https://cwidt.com/
 Verison:	0.3.2	ALPHA

 Christa McAuliffe Space Education Center
*/

#include "Adafruit_NeoPixel-master\Adafruit_NeoPixel.h";
#include "Lighting.h";

Lighting Strip1(60, 5, NEO_GRB + NEO_KHZ800, NULL); //#Leds, #Pin, Speed

void setup() {

}

void loop() {
	Strip1.Update();
}




void Strip1Complete()
{

}