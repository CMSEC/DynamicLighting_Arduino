#pragma once
#include "Adafruit_NeoPixel.h";
#include "Colour.h";
#include "Sequence.h";
#include "LightInformation.h";
#include "ESC.h";
#include "Configuration.h";

namespace CMSEC
{
	class Lighting : public Adafruit_NeoPixel
	{
	public:
		enum States {
			STATE_COLOR,
			STATE_DOWNLOAD,
			STATE_UPLOAD,
			STATE_DISCO,
			STATE_SHORTCIRCUIT,
			STATE_BUGS,
			STATE_PLASMA,
			STATE_RGB,
			STATE_FAIL,
			STATE_VICTORY,
			STATE_BLACKOUT //BLACKOUT IS NOT JUST A COLOR! It is like a color with an instant transition
			//STATE_BLACK = MERGED INTO: STATE_COLOR + BLACK
		};
		enum Transitions {
			TRANSITION_LINEAR,
			TRANSITION_INSTANT,
			TRANSITION_LEFTRIGHTWIPE,
			TRANSITION_RIGHTLEFTWIPE,
			TRANSITION_SPARKLE,
			TRANSITION_SPECTRUM,
			TRANSITION_FADE
		};
		enum Idle {
			IDLE_NONE,
			IDLE_PORTERPULSE,
			IDLE_CYLON,
			IDLE_STEALTH,
			IDLE_TWINKLE,
			IDLE_ALERT,
			IDLE_CHASE,
			IDLE_FIRE,
			IDLE_PULSE,
			IDLE_SNOW,
			IDLE_WIPE,
			IDLE_STROBE
		};

		enum Effects {
			EFFECT_NONE,
			EFFECT_EXPLOSION,
			EFFECT_SPARKS,
			EFFECT_BROWNOUT,
			EFFECT_SURGE,
			EFFECT_STROBE,
			EFFECT_FLICKER,
			EFFECT_BLOWOUT,
			EFFECT_BOUNCYSPARKS,
			EFFECT_SENSORDATA,
			EFFECT_COMPUTER_BOOT
		};
	private:

			//STATE - DEFINITIONS
			//PUBLICALLY MODIFIABLE - STATE:
			States state = STATE_COLOR; //Current STATE
			Colour stateColor = Colour(0, 0, 255); //Color of the solid color if STATE = STATE_COLOR
												   //NONE PUBLIC ACCESSABLE - STATE:
			uint16_t stateTotalSteps; //Total number of steps in the STATE
			uint16_t stateIndex; //Current step within the STATE
			unsigned long stateInterval;
			unsigned long stateLastUpdate;

			//TRANSITION - DEFINITIONS
			//PUBLICALLY MODIFIABLE - TRANSITION:
			Transitions transition = TRANSITION_LINEAR; //Current TRANSITION
			uint16_t transitionSpeed = 1500; //How long it takes to complete the transition
											 //NONE PUBLIC ACCESSABLE - TRANSITION:
			uint16_t transitionTotalSteps; //Total number of steps in the TRANSITION
			uint16_t transtionIndex; //Current step within the TRANSITION
			unsigned long transitionInterval;
			unsigned long transitionLastUpdate;

			//IDLE - DEFINITIONS
			//PUBLICALLY MODIFIABLE - IDLE:
			Idle idle = IDLE_PORTERPULSE; //Current IDLE
			uint16_t idleSpeed = 10000; //How long the IDLE lasts, different strips take different amount of time unless synchronous is checked
			uint16_t idleDelay = 5000; //How long until the IDLE starts again
			Colour idleColor = Colour(255, 255, 255);
			//NONE PUBLIC ACCESSABLE - TRANSITION:
			uint16_t idleTotalSteps; //Total number of steps in the IDLE
			uint16_t idleIndex; //Current step within the IDLE
			unsigned long idleInterval;
			unsigned long idleLastUpdate;

			//EFFECT - DEFINITIONS
			//PUBLICALLY MODIFIABLE - EFFECT:
			Effects effect = EFFECT_NONE; //Current EFFECT
			uint16_t effectDuration = 2000; //How long the EFFECT lasts
			Colour effectTint = Colour(255, 255, 255);
			//NONE PUBLIC ACCESSABLE - TRANSITION:
			uint16_t effectTotalSteps; //Total number of steps in the TRANSITION
			uint16_t effectIndex; //Current step within the TRANSITION
			unsigned long effectInterval;
			unsigned long effectLastUpdate;


			uint16_t numPixels; //How many pixels are in the strip or array
			uint16_t numPin; //Pin number the pixels are assigned to

			bool reverse = false; //If the whole system iterates in reverse

			Sequence currentDisplay; //What is currently being displayed
			Sequence nextDisplay; //What is next, what the transition uses to keep both up to date, erased after transition completion

			Sequence stateDisplay; //What the idle ques in to. Overlays or affects the display (state).
			Sequence idleOverlay; //What the idle ques in to. Overlays or affects the display (state).
			Sequence effectDisplay; //Chooses to completely take over, or simply overlay EVERYTHING.

		public:

		LightInformation information;


		void(*OnComplete)();
		Lighting(uint16_t _pixels, uint8_t _pin, neoPixelType _type, void(*callback)(), LightInformation _info) :Adafruit_NeoPixel(_pixels, _pin, _type)
		{
			numPixels = _pixels; //REFERENCE - Theses variables are for reference, the NeoPixel class saves them elsewhere. These are what the states, transitions, idle, and effects use to judge duration
			numPin = _pin; //REFERENCE - " "
			OnComplete = callback; //REFERENCE - " "
			information = _info;

			currentDisplay = Sequence(); //Creates linked lists that store the color of every individual pixel, others like next, idle, and effect are usually just modifiers of display
			nextDisplay = Sequence();

			stateDisplay = Sequence();
		    idleOverlay = Sequence();
			effectDisplay = Sequence();
		}

		void Update()
		{
			if ((millis() - stateLastUpdate) > stateInterval) //Update if Interval is met, not vary acurate, but the eye doesnt notice.
			{
				stateLastUpdate = millis();
				switch (state)
				{
				case STATE_COLOR:
					SolidColorUpdate(stateDisplay);
					break;
				case STATE_DOWNLOAD:
					DownloadUpdate(stateDisplay);
					break;
				case STATE_UPLOAD:
					UploadUpdate(stateDisplay);
					break;
				case STATE_DISCO:
					DiscoUpdate(stateDisplay);
					break;
				case STATE_SHORTCIRCUIT:
					break;
				case STATE_BUGS:
					break;
				case STATE_PLASMA:
					break;
				case STATE_RGB:
					break;
				case STATE_FAIL:
					break;
				case STATE_VICTORY:
					break;
				case STATE_BLACKOUT:
					break;
				default:
					//How did you f this up? Usually an undefined enum
					break;
				}
				ShiftUpdate();
			}
			if (transition != TRANSITION_INSTANT && (millis() - transitionLastUpdate) > transitionInterval)
			{

			}
			if (idle != IDLE_NONE && ((millis() - idleLastUpdate) > idleInterval))
			{

			}
			if (effect != EFFECT_NONE && ((millis() - effectLastUpdate) > effectInterval))
			{

			}
			show();
		}
		void Increment()
		{
			if (reverse == false)
			{
				stateIndex++;
				if (stateIndex >= stateTotalSteps)
				{
					stateIndex = 0;
					if (OnComplete != NULL)
					{
						OnComplete();
					}
				}
			}
			else
			{
				--stateIndex;
				if (stateIndex <= 0)
				{
					stateIndex = stateTotalSteps - 1;
					if (OnComplete != NULL)
					{
						OnComplete();
					}
				}
			}
		}
		void Reverse()
		{
			if (reverse == false)
			{
				reverse = true;
				stateIndex = stateTotalSteps - 1;
			}
			else
			{
				reverse = false;
				stateIndex = 0;
			}
		}




		//STATES - PROGRAMMING

		//COLOR
	public:
		void SolidColor(Colour _color)
		{
			stateColor = _color;
		}
	private:
		void SolidColorUpdate(Sequence _seq)
		{
			for (uint16_t i = 0; i < numPixels; i++)
			{
				_seq.Set(i, stateColor);
			}
		}

		//DOWNLOAD
	public:
		void Download()
		{

		}
	private:
		void DownloadUpdate(Sequence _seq)
		{

		}

		//UPLOAD
	public:
		void Upload()
		{

		}
	private:
		void UploadUpdate(Sequence _seq)
		{

		}

		//DISCO
	public:
		void Disco(uint8_t _interval, bool _rev = false)
		{
			state = STATE_DISCO;
			stateInterval = _interval;
			stateTotalSteps = 255;
			stateIndex = 0;
			reverse = _rev;
		}
	private:
		void DiscoUpdate(Sequence _seq)
		{
			for (int i = 0; i < numPixels; i++)
			{
				uint32_t color = Wheel(((i * 256 / numPixels) + stateIndex) & 255);
				SetPixel(_seq, i, color);
				//setPixelColor(i, Wheel(((i * 256 / numPixels) + stateIndex) & 255));
			}
			Increment();
		}











//LAYERS FUNCTIONS
		void SetPixel(Sequence _seq, uint16_t _pixel, uint32_t _color)
		{
			_seq.Set(_pixel, _color);
		}
		void ShiftUpdate()
		{
			for (uint16_t i = 1; i <= numPixels; i++)
			{
				Colour stateColor = stateDisplay.At(i);
				Colour idleColor = idleOverlay.At(i);
				Colour visibleColor = Colour(stateColor, idleColor);
				setPixelColor(i, visibleColor.red, visibleColor.green, visibleColor.blue);
			}
		}

//UTILITY FUNCTIONS
		uint32_t DimColor(uint32_t _color)
		{
			uint32_t dimColor = Color(Red(_color) >> 1, Green(_color) >> 1, Blue(_color) >> 1);
			return dimColor;
		}
		void ColorSet(uint32_t _color)
		{
			for (int i = 0; i < numPixels; i++)
				setPixelColor(i, _color);
			show();
		}
		uint8_t Red(uint32_t _color)
		{
			return (_color >> 16) & 0xFF;
		}
		uint8_t Green(uint32_t _color)
		{
			return (_color >> 8) & 0xFF;
		}
		uint8_t Blue(uint32_t _color)
		{
			return _color & 0xFF;
		}
		uint32_t Wheel(byte _wheel)
		{
			_wheel = 255 - _wheel;
			if (_wheel < 85)
			{
				return Color(255 - _wheel * 3, 0, _wheel * 3);
			}
			else if (_wheel < 170)
			{
				_wheel -= 85;
				return Color(0, _wheel * 3, 255 - _wheel * 3);
			}
			else
			{
				_wheel -= 170;
				return Color(_wheel * 3, 255 - _wheel * 3, 0);
			}
		}
	};
}

