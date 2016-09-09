#pragma once
namespace CMSEC
{
	class ESC //External Serial Commander
	{
	public:
		enum SerialPort
		{
			SERIAL_DEFAULT,
			SERIAL_1,
			SERIAL_2,
			SERIAL_3
		};

		ESC() {};
		ESC(SerialPort _serial)
		{
			serial = _serial;
		};
		~ESC() {};

		SerialPort serial;

		struct ESC_Physical //Using the Physical controller box with macros to control lighting
		{
			uint8_t labels; //Number of digital labels
			enum DISPLAY_TYPE {
				DISPLAY_NONE,
				DISPLAY_OLED,
				DISPLAY_LCD
			};
			uint8_t rotaryStops; //ROTARY_SWITCH: How many clicks (stops) there are on the switch
			uint8_t switchPositions; //SWITCH: How many ways the switch can be pressed
			uint8_t rotaryStepsPerShift; //ROTARY_ENCODER: How many clicks until a tab change is called
			uint16_t analogMin; //ANALOG_POTENTIOMETER: Min location for the potentiometer
			uint16_t analogMax; //ANALOG_POTENTIOMETER: Max rotation for the potentiometer
			uint16_t analogTabs; //ANALOG_POTENTIOMETER: How many tabs you want for the potentiometer, CURRENT_TAB = ((analogMax - analogMin)/analogTabs)
			enum TAB_CONTROLLER
			{
				TAB_NONE, //No tab controller, can use macro buttons instead, but not as quick
				TAB_ROTARY_SWITCH, //Clicky switch (RECOMMENDED) Sparkfun: https://www.sparkfun.com/products/13253
				TAB_MULTI, //Same as ROTARY_SWITCH
				TAB_SWITCH, //Same as ROTARY_SWITCH | Standard switch, more than 2 positions is recommended. Digikey:
				TAB_ROTARY_ENCODER,
				TAB_ANALOG_POTENTIOMETER, //Smooth movement with limited travel, not recommended due to inablility to determine position
				TAB_NAV_BUTTONS, //Like ROTARY_SWITCH, but with momentary presses, and unlimited pages
			};
		};
		struct ESC_PhysicalMini //Smaller handheld Physical controller
		{

		};

		struct ESC_WiFi //Using ESP8266 to communicate over serial, make sure to handle logic level shifting!
		{

		};

		struct ESC_BlueTooth //Using Bluetooth to communicate over serial, (HC-05, HC-06, HM-10), make sure to handle logic level shifting!
		{

		};

		struct ESC_RaspberryPi //Using RaspberryPi running ESC_RaspberryPi and the Pi's integrated serial, make sure to handle logic level shifting!
		{

		};

		struct ESC_Music //Using the music parser with an aux audio input. Enable with MusicEnable(), and vise-versa with MusicDisable(). Logic levels should be handled by the parser, but be careful!
		{

		};

		struct ESC_RFID //Using RFID chips and cards to cue lights.
		{

		};

	private:
		void DetectESC() //Descovers what struct to use based on data transmission on the serial line
		{

		}
	};
}
