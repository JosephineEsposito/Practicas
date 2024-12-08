#pragma once

class Image
{
public:
	unsigned int uData;

	Image();
	Image(unsigned int _uData);

	void Print();

	void RemoveAlpha();
};