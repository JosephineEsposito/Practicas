#include <iostream>
#include "CStream.h"


CStream::CStream()
{
	cConnection = nullptr;
}

void CStream::Open()
{
	std::cout << "[CStream] Opened the stream " << std::endl;
}

void CStream::Close()
{
	std::cout << "[CStream] Closed the stream " << std::endl;
}

void CStream::Read()
{
	std::cout << "[CStream] Read from stream " << std::endl;
}

void CStream::Write()
{
	std::cout << "[CStream] Wrote in stream" << std::endl;
}