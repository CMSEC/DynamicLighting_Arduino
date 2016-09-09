#pragma once
namespace
{
	class Colour
	{
	public:
		Colour() {};
		Colour(byte _red, byte _green, byte _blue, byte _alpha = (255 & 0xFF))
		{
			red = _red;
			green = _green;
			blue = _blue;
			alpha = _alpha;
		}
		Colour(uint32_t _value)
		{
			red = (_value >> 0) & 0xFF;
			green = (_value >> 8) & 0xFF;
			blue = (_value >> 16) & 0xFF;
			alpha = (_value >> 24) & 0xFF;
		}
		Colour(Colour _base, Colour _overlay, double _blend = 0)
		{
			red = (byte)((_base.red * _blend) + _overlay.red * (1 - _blend));
			green = (byte)((_base.green * _blend) + _overlay.green * (1 - _blend));
			blue = (byte)((_base.blue * _blend) + _overlay.blue * (1 - _blend));
			alpha = (byte)((_base.alpha * _blend) + _overlay.alpha * (1 - _blend));
		}
		~Colour() {};

		uint32_t IntReturn()
		{
			uint32_t rgba = (alpha << 24) | (blue << 16) | (green << 8) | red;
		}

		byte red = 0;
		byte green = 0;
		byte blue = 0;
		byte alpha = 0;
	};
}
