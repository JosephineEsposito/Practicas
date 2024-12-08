#pragma once // -> to avoid including twice the same header

#include <iostream>
#include <list>

// F1 on FILE to open online documentation

namespace FileManager
{
	//To open a file
	void* OpenFile(void* _sFile, const char* _sFilename, const char* _sMode);

	//To close a file
	bool CloseFile(void* _pPFile);

	//To read a file
	unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

	//To write in a file
	unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

	//To sum all the numbers in a file
	//This returns an unsigned int and required the pointer to the opened filestream
	unsigned int SumaEnFichero(void* _pFile);

	//To get all the numbers in a file that are separated by ",".
	//This returns an array of characters, and requires the pointer to the opened filestream.
	void GetNumbersInFile(void* _pFile, std::list<std::string>* _lList);

	//To print on the console the numbers saved in the list
	void PrintList(std::list<std::string>* _lList);
}
