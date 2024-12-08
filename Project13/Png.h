#pragma once
#include "Image.h"

class Png : public Image
{
public:
	unsigned int uRed;
	unsigned int uGreen;
	unsigned int uBlue;

	unsigned int uAlpha;

	Png();
	Png(unsigned int _uData);
	Png(unsigned int _uRed, unsigned int _uGreen, unsigned int _uBlue, unsigned int _uAlpha);

	void PrintChannels();

	void ClearAlpha();
};
