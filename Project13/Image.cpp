#include <iostream>
#include "Image.h"

Image::Image()
{
	uData = 0x00000000; // alpha, red, green, blue
}
Image::Image(unsigned int _uData)
{
	uData = _uData;
}

void Image::Print()
{
	printf("%X\n", uData);
}

void Image::RemoveAlpha()
{
	unsigned int uAlpha = 0x00000000;

	uData &= 0x00FFFFFF;
	uData = uAlpha | uData;
}