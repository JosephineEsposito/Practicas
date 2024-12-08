#include "FileUtil.h"

#include <cstdio>		// moved here so that when including the .h, we do not load the whole library all the time we make a change
#include <cstring>	// for strstr()

#include <sstream>	// for stringstream
#include <fstream>
#include <iostream>

#include <list>

namespace FileManager
{
	const char* _sModalidades[]
	{
		"r",	//read only
		"w",	//write only
		"a",	//
		"r+",	//read and write
		"w+",	//
		"a+"	//
	};

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

		std::ios_base::openmode io_mode;
		if			(strcmp(_sMode, "r")	== 0) io_mode = std::ios::in;
		else if (strcmp(_sMode, "w")	== 0) io_mode = std::ios::out;
		else if (strcmp(_sMode, "r+") == 0) io_mode = std::ios::in | std::ios::out;
		else if (strcmp(_sMode, "w+") == 0) io_mode = std::ios::in | std::ios::out | std::ios::trunc;
		else if (strcmp(_sMode, "a")	== 0) io_mode = std::ios::app;
		else if (strcmp(_sMode, "a+") == 0) io_mode = std::ios::in | std::ios::app;
		else return nullptr;

		sFile->open(_sFilename, io_mode);

		if (sFile->fail())
		{
			printf("Error opening the file\n");
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
		std::fstream* sFile = reinterpret_cast<std::fstream*>(_pFile);

		if (!sFile->is_open())
		{
			printf("File is not open.\n");
			return 0;
		}

		unsigned int uCount_ = 0u;
		while (uCount_ < _uSize && sFile->get(_pBuffer[uCount_]))
		{
			printf("Valori letti: %c\n", _pBuffer[uCount_]);
			uCount_++;
		}

		
		if (sFile->eof())
		{
			printf("End of file reached!\n");
		}
		else if (sFile->fail())
		{
			printf("Error when reading the file.\n");
		}

		return uCount_;
	}

	unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile)
	{
		std::fstream* sFile = reinterpret_cast<std::fstream*>(_pFile);

		if (!sFile->is_open())
		{
			printf("File not open.\n");
			return 0;
		}

		sFile->write(_pBuffer, _uSize);
		unsigned int uCharactersWritten_ = static_cast<unsigned int>(sFile->tellp());

		if (sFile->fail())
		{
			printf("An error occurred while writing.\n");
		}

		return uCharactersWritten_;
	}

	unsigned int SumaEnFichero(void* _pFile)
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
				iSuma += std::stoi(token);  // Convert token to integer and add to sum
			}
		}

		return iSuma;
	}

	void GetNumbersInFile(void* _pFile, std::list<std::string>* _lList)
	{
		std::ifstream* sFile = reinterpret_cast<std::ifstream*>(_pFile);
		if (!sFile->is_open())
		{
			printf("File not open.\n");
			_lList->clear(); //just to check
			return;
		}

		std::string sLine;

		//we read the file line by line
		while (std::getline(*sFile, sLine))
		{
			std::stringstream ss(sLine);
			std::string token;
			while (std::getline(ss, token, ','))
			{
				std::string cNum = token.c_str();
				_lList->push_back(cNum);
			}
		}

	}

	void PrintList(std::list<std::string>* _lList)
	{
		for (std::string cNum : *_lList)
		{
			std::cout << cNum << " ";
		}
		std::cout << "\n";
	}
}