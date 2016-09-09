/*
 Name:		DynamicLighting_Arduino
 Company:	Inventicon
 Author:	Connor Widtfeldt
 Github:	https://github.com/CMSEC/DynamicLighting_Arduino/
 Website:	https://inventicon.com/
 Verison:	0.4.6	ALPHA
 License:	Attribution-ShareAlike 4.0 International

 Christa McAuliffe Space Education Center
*/

#include "Lighting.h";
using namespace CMSEC;

LightInformation Strip1Information("Demo Strip", "This is the details for the strip used in the demo");
Lighting Strip1(45, 8, NEO_GRB + NEO_KHZ800, NULL, Strip1Information); //#Leds, #Pin, Speed, Complete Callback

ESC PhyInterface(ESC::SERIAL_1); //SERIAL1, SERIAL2, and SERIAL3 good. SERIAL_DEFAULT is used for USB communication
ESC MiniInterface(ESC::SERIAL_2);
ESC ESP32(ESC::SERIAL_3);

void setup() {
	Serial.begin(BAUD); //USB COMMUNICATOR
	help();
	
	Strip1.Reverse();
	Strip1.Disco(5);//Strip1.SolidColor(Colour(0, 0, 255));
	Strip1.begin();

	ready();
}

void loop() {
	//check();
	Strip1.Update();
}



//PARSER
char buffer[MAX_BUFFER];
int sofar;
void help() {
	Serial.print(F("Arduino/AVR/RISC Pseudo Async Lighting System with Serial Commands | Version: "));
	Serial.println(VERSION);
	Serial.println(F("Commands:"));
	Serial.println(F("STATE [TARGET_STATE] R[RED BYTE] G[GREEN BYTE] B[BLUE BYTE] I[INTERVAL_MILLISECONDS]"));
	Serial.println(F("TRANSITION [TARGET_TRANSITION] I[INTERVAL-MILLISECONDS]"));
	Serial.println(F("IDLE [TARGET_IDLE] R[RED BYTE] G[GREEN BYTE] B[BLUE BYTE] I[INTERVAL-MILLISECONDS]"));
	Serial.println(F("EFFECT [TARGET_EFFECT] D[DURATION]"));
	Serial.println(F("REVERSE [1/0]"));
	Serial.println(F("ORGANIC [1/0]"));
}
void ready() {
	sofar = 0;
	Serial.print(F("> "));
}
void check() {
	if (Serial.available()) {
		char c = Serial.read();
		Serial.print(c);
	}
}
void process() {
	// look for commands that start with 'G'
	String command = parseCommand();
	//Serial.println(command);
}
String parseCommand() {
	char* command = strchr(buffer, ' ');
	return command;
}