#include "FileUtil.h";

#include <cstdio> // moved here so that when including the .h, we do not load the whole library all the time we make a change
#include <iostream>

#include <fstream>
#include <sstream>


const char* _sModalidades[]
{
	"r",
	"w",
	"a",
	"r+",
	"w+",
	"a+"
};

// F1 on FILE to open online official documentation
void* OpenFile(void* _sFile, const char* _sFilename, const char* _sMode)
{
	bool bValidMode = false;

	for (const char* _cModalidad : _sModalidades)
	{
		if (*_sMode == *_cModalidad)
		{
			bValidMode = true;
			break;
		}
	}

	if (!bValidMode)
	{
		printf("Invalid mode specified for file opening.\n");
		return nullptr;
	}

	std::fstream* sFile = reinterpret_cast<std::fstream*>(_sFile);

	std::ios_base::openmode mode;
	if (strcmp(_sMode, "r") == 0) mode = std::ios::in;
	else if (strcmp(_sMode, "w") == 0) mode = std::ios::out;
	else if (strcmp(_sMode, "r+") == 0) mode = std::ios::in | std::ios::out;
	else if (strcmp(_sMode, "w+") == 0) mode = std::ios::in | std::ios::out | std::ios::trunc;
	else if (strcmp(_sMode, "a") == 0) mode = std::ios::app;
	else if (strcmp(_sMode, "a+") == 0) mode = std::ios::in | std::ios::app;
	else return nullptr;

	sFile->open(_sFilename, mode);

	if (sFile->fail())
	{
		printf("Error opening the file\n");  // Print detailed error
		return nullptr;
	}

	return sFile;
}

bool CloseFile(void* _pFile)
{
	std::fstream* sFile = reinterpret_cast<std::fstream*>(_pFile);
	if (sFile)
	{
		sFile->close();
		return true;
	}
	return false;
}

unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile)
{
	std::fstream* pFile = reinterpret_cast<std::fstream*>(_pFile);

	if (!pFile->is_open())
	{
		printf("File not open.\n");
		return 0;
	}

	unsigned int uCount_ = 0u;
	while (uCount_ < _uSize && pFile->get(_pBuffer[uCount_]))
	{
		printf("Valori letti : %c\n", _pBuffer[uCount_]);
		uCount_++;
	}

	if (pFile->eof())
	{
		printf("End of file reached!\n");
	}
	else if (pFile->fail())
	{
		printf("Error when reading the file.\n");
	}

	return uCount_;
}

unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile)
{
	std::fstream* pFile = reinterpret_cast<std::fstream*>(_pFile);

	if (!pFile->is_open())
	{
		printf("File not open.\n");
		return 0;
	}

	pFile->write(_pBuffer, _uSize);
	unsigned int uCharactersWritten_ = pFile->tellp();

	if (pFile->fail())
	{
		printf("An error occurred while writing.\n");
	}

	return uCharactersWritten_;
}
