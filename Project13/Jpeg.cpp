#include <iostream>
#include "Jpeg.h"


Jpeg::Jpeg()
{
	uData = 0x00000000;
	uRed = 0x00;
	uGreen = 0x00;
	uBlue = 0x00;
	uAlpha = 0x00;
}
Jpeg::Jpeg(unsigned int _uData)
{
	uBlue = _uData & 0x000000FF;
	uGreen = (_uData >> 8) & 0x000000FF;
	uRed = (_uData >> 16) & 0x000000FF;
	uAlpha = (_uData >> 24) & 0x000000FF;

	uData = _uData;
}
Jpeg::Jpeg(unsigned int _uRed, unsigned int _uGreen, unsigned int _uBlue, unsigned int _uAlpha)
{
	uRed = _uRed;
	uGreen = _uGreen;
	uBlue = _uBlue;
	uAlpha = _uAlpha;

	_uAlpha << 24;
	uData = uData &= 0x00FFFFFF;
	uData = uAlpha | uData;

	_uRed << 16;
	uData = uData &= 0xFF00FFFF;
	uData = uRed | uData;

	_uGreen << 8;
	uData = uData &= 0xFFFF00FF;
	uData = uGreen | uData;

	uData = uData &= 0xFFFFFF00;
	uData = uBlue | uData;
}

void Jpeg::PrintChannels()
{
	printf("HEX(%X, %X, %X, %X);\n", uAlpha, uRed, uGreen, uBlue);
}