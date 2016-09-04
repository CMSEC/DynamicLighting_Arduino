/*
 Name:		DynamicLighting_Arduino
 Company:	Inventicon
 Author:	Connor Widtfeldt
 Github:	https://github.com/CMSEC/DynamicLighting_Arduino/
 Website:	https://inventicon.com/
 Verison:	0.3.2	ALPHA
 License:	Attribution-ShareAlike 4.0 International

 Christa McAuliffe Space Education Center
*/

#include "Lighting.h";

LightInformation Strip1Information("Demo Strip", "This is the details for the strip used in the demo");
Lighting Strip1(60, 5, NEO_GRB + NEO_KHZ800, NULL, Strip1Information); //#Leds, #Pin, Speed

ESC PhyInterface(Serial1);
ESC BlueTooth(Serial2);

void setup() {
	Strip1.SolidColor(Colour(0, 0, 255));
}

void loop() {
	Strip1.Update();
}