#pragma once
class Colour
{
public:
	Colour() {};
	Colour(byte _red, byte _green, byte _blue)
	{
		red = _red;
		green = _green;
		blue = _blue;
	}
	~Colour() {};

	byte red;
	byte green;
	byte blue;
};

