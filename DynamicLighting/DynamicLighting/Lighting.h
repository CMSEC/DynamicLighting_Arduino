#pragma once
#include "Adafruit_NeoPixel.h";
#include "Colour.h";
#include "Sequence.h";
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
		EFFECT_SENSORDATA
	};

//STATE - DEFINITIONS
		//PUBLICALLY MODIFIABLE - STATE:
	States state = STATE_COLOR; //Current STATE
	Colour stateColor = Colour(0, 0, 255); //Color of the solid color if STATE = STATE_COLOR
		//NONE PUBLIC ACCESSABLE - STATE:
	uint16_t stateTotalSteps; //Total number of steps in the STATE
	uint16_t stateIndex; //Current step within the STATE

//TRANSITION - DEFINITIONS
		//PUBLICALLY MODIFIABLE - TRANSITION:
	Transitions transition = TRANSITION_LINEAR; //Current TRANSITION
	uint16_t transitionSpeed = 1500; //How long it takes to complete the transition
		//NONE PUBLIC ACCESSABLE - TRANSITION:
	uint16_t transitionTotalSteps; //Total number of steps in the TRANSITION
	uint16_t transtionIndex; //Current step within the TRANSITION

//IDLE - DEFINITIONS
		//PUBLICALLY MODIFIABLE - IDLE:
	Idle idle = IDLE_PORTERPULSE; //Current IDLE
	uint16_t idleSpeed = 10000; //How long the IDLE lasts, different strips take different amount of time unless synchronous is checked
	uint16_t idleDelay = 5000; //How long until the IDLE starts again
	Colour idleColor = Colour(255, 255, 255);
		//NONE PUBLIC ACCESSABLE - TRANSITION:
	uint16_t idleTotalSteps; //Total number of steps in the IDLE
	uint16_t idleIndex; //Current step within the IDLE

//EFFECT - DEFINITIONS
		//PUBLICALLY MODIFIABLE - EFFECT:
	Effects effect = EFFECT_NONE; //Current EFFECT
	uint16_t effectDuration = 2000; //How long the EFFECT lasts
	Colour effectTint = Colour(255, 255, 255);
		//NONE PUBLIC ACCESSABLE - TRANSITION:
	uint16_t effectTotalSteps; //Total number of steps in the TRANSITION
	uint16_t effectIndex; //Current step within the TRANSITION


	unsigned long Interval = 50; //Milliseconds between updates (DEFAULT IS 50 MILLISECONDS (0.05s) EVEN IF DURATIONS OR DELAYS ARE 25 MILLISECONDS THEY ROUND UP TO THE NEAREST 50 MILLISECONDS!)
	unsigned long lastUpdate = 0; //Last update of position


	uint16_t numPixels; //How many pixels are in the strip or array
	uint16_t numPin; //Pin number the pixels are assigned to

	bool reverse = false; //If the whole system iterates in reverse

	Sequence display; //What is being displayed, BASE LAYER
	Sequence nextDisplay; //What is next, what the transition uses to keep both up to date, erased after transition completion
	Sequence idleOverlay; //What the idle ques in to. Overlays or affects the display (state).
	Sequence effectDisplay; //Chooses to completely take over, or simply overlay EVERYTHING.

	void(*OnComplete)();
	Lighting(uint16_t _pixels, uint8_t _pin, neoPixelType _type, void(*callback)()):Adafruit_NeoPixel(_pixels, _pin, _type)
	{
		numPixels = _pixels; //REFERENCE - Theses variables are for reference, the NeoPixel class saves them elsewhere. These are what the states, transitions, idle, and effects use to judge duration
		numPin = _pin; //REFERENCE - " "
		OnComplete = callback; //REFERENCE - " "

		display = Sequence(_pixels); //Creates linked lists that store the color of every individual pixel, others like next, idle, and effect are usually just modifiers of display
		nextDisplay = Sequence(_pixels);
		idleOverlay = Sequence(_pixels);
		effectDisplay = Sequence(_pixels);
	}

	void Update()
	{
		if ((millis() - lastUpdate) > Interval) //Update if Interval is met, not vary acurate, but they eye doesnt notice.
		{
			lastUpdate = millis();
			switch (state)
			{
			case STATE_COLOR:
				break;
			case STATE_DOWNLOAD:
				break;
			case STATE_DISCO:
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
				break;
			}
		}
	}




//STATES - PROGRAMMING
};

