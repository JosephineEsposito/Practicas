#include "TFile.h"

#include <cstdio>		// moved here so that when including the .h, we do not load the whole library all the time we make a change
#include <cstring>	// For strstr()

#include <sstream>	// For stringstream
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



TFile::TFile()
{
	_pFile = nullptr;
}

void* TFile::OpenFile(const char* _sFilename, const char* _sMode)
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


	std::ios_base::openmode mode;
	if (strcmp(_sMode, "r") == 0) mode = std::ios::in;
	else if (strcmp(_sMode, "w") == 0) mode = std::ios::out;
	else if (strcmp(_sMode, "r+") == 0) mode = std::ios::in | std::ios::out;
	else if (strcmp(_sMode, "w+") == 0) mode = std::ios::in | std::ios::out | std::ios::trunc;
	else if (strcmp(_sMode, "a") == 0) mode = std::ios::app;
	else if (strcmp(_sMode, "a+") == 0) mode = std::ios::in | std::ios::app;
	else return nullptr;

	std::fstream* sFile = new std::fstream; // initial file pointer
	sFile->open(_sFilename, mode);

	if (sFile->fail())
	{
		printf("Error opening the file\n");  // Print detailed error
		return nullptr;
	}

	_pFile = sFile; // salviamo il valore nella classe
	return sFile; // lo ritorniamo
}

bool TFile::CloseFile()
{
	std::fstream* sFile = reinterpret_cast<std::fstream*>(_pFile);
	if (sFile)
	{
		sFile->close();
		_pFile = nullptr; // puliamo il puntatore
		return true;
	}
	return false;
}

unsigned int TFile::ReadFile(char* _pBuffer, unsigned int _uSize)
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

unsigned int TFile::WriteFile(char* _pBuffer, unsigned int _uSize)
{
	std::fstream* pFile = reinterpret_cast<std::fstream*>(_pFile);

	if (!pFile->is_open())
	{
		printf("File not open.\n");
		return 0;
	}

	pFile->write(_pBuffer, _uSize);
	unsigned int uCharactersWritten_ = static_cast<unsigned int>(pFile->tellp());

	if (pFile->fail())
	{
		printf("An error occurred while writing.\n");
	}

	return uCharactersWritten_;
}

unsigned int TFile::SumaEnFichero()
{
	std::ifstream* pFile = reinterpret_cast<std::ifstream*>(_pFile);
	if (!pFile->is_open())
	{
		printf("File not open.\n");
		return 0;
	}

	std::string sLine;
	int iSuma = 0;

	// Read the file line by line
	while (std::getline(*pFile, sLine))
	{
		std::stringstream ss(sLine);
		std::string token;
		while (std::getline(ss, token, ','))
		{
			try
			{
				iSuma += std::stoi(token);  // Convert token to integer and add to sum
			}
			catch (const std::invalid_argument& e)
			{
				printf("Not a number :(.\n");
			}
		}
	}

	return iSuma;
}

unsigned int TFile::SubStringFind(const char* _pCadena, unsigned int uSize)
{
	std::fstream* pFile = reinterpret_cast<std::fstream*>(_pFile);

	if (!pFile->is_open())
	{
		printf("File not open.\n");
		return -1;
	}

	unsigned int uRepeticiones_ = 0u;
	unsigned int uCount = 0u;
	const char* pBuffer;
	std::string cLine; // per il getline()
	while (!pFile->eof())
	{
		std::getline(*pFile, cLine);
		pBuffer = cLine.c_str(); // convertiamo al puntatore

		const char* cCaracter = std::strstr(pBuffer, _pCadena); //ritorna il primo carattere della catena trovato

		while (cCaracter)
		{
			uRepeticiones_++;
			cCaracter = std::strstr(cCaracter + 1, _pCadena); // controlliamo dal prossimo carattere in poi
		}
	}

	return uRepeticiones_;
}

//EOF