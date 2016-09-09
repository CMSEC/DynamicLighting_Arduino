#pragma once
#include "Colour.h";
namespace CMSEC
{
	class Sequence
	{
	public:
		Sequence()
		{
			data = new Colour[0];
		}
		Sequence(int16_t _size)
		{
			data = new Colour[_size];
		}

		void Set(uint16_t _pixel, Colour _value)
		{
			data[_pixel] = _value;
		}
		Colour At(uint16_t _pixel)
		{
			return data[_pixel];
		}

		Colour* data;
	};
}