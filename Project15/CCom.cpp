#include <iostream>
#include "CCom.h"

CCom::CCom()
{
	uPort = 0x03;
	uAddress = 0x080;
}

void CCom::Open()
{
	std::cout << "[CCom] Opened the stream " << std::endl;
}

void CCom::Close()
{
	std::cout << "[CCom] Closed the stream " << std::endl;
}

void CCom::Read()
{
	std::cout << "[CCom] Read from stream " << std::endl;
}

void CCom::Write()
{
	std::cout << "[CCom] Wrote in stream" << std::endl;
}