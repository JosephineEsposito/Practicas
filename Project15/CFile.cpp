#include <iostream>
#include "CFile.h"

CFile::CFile()
{
	cMode = "rw";
}

void CFile::Open()
{
	std::cout << "[CFile] Opened the stream " << std::endl;
}

void CFile::Close()
{
	std::cout << "[CFile] Closed the stream " << std::endl;
}

void CFile::Read()
{
	std::cout << "[CFile] Read from stream " << std::endl;
}

void CFile::Write()
{
	std::cout << "[CFile] Wrote in stream" << std::endl;
}