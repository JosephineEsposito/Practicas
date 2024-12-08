#pragma once
#include "Image.h"

class Jpeg : public Image
{
public:
	unsigned int uRed;
	unsigned int uGreen;
	unsigned int uBlue;
	unsigned int uAlpha;

	Jpeg();
	Jpeg(unsigned int _uData);
	Jpeg(unsigned int _uRed, unsigned int _uGreen, unsigned int _uBlue, unsigned int _uAlpha);

	void PrintChannels();
};
