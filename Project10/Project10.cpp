// 22102024 | @josephineesposito
// Project10.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

///
/// a�adir al namespace de utilizades creado en la practica 5
/// [X] funcion que retorne una lista de cadenas con los numeros separados por comas presentes en un fichero,
/// [X] dise�ar la declaraci�n de la funci�n
/// [X] sacar por consola los n�meros le�dos
///

#include <iostream>
#include <sstream>
#include <fstream>

#include "FileUtil.h"

using namespace FileManager;

int main()
{
	std::fstream* sFile = new std::fstream; //initial file pointer

	unsigned int uSize = 12; //default buffer size
	char* pBuffer = new char[uSize];

	std::list<std::string>* lList = new std::list<std::string>();


	void* pFileTexto = OpenFile(sFile, "Text.txt", "r");
	if (pFileTexto)
	{
		//ReadFile(pBuffer, uSize, pFileTexto); //to test if the file can be opened and read correctly
		GetNumbersInFile(sFile, lList);

		PrintList(lList);

		CloseFile(pFileTexto); // we always must close the file after finishing our tasks
	}



	//Qui puliamo la memoria
	delete sFile;
	delete[] pBuffer;
	//Squeaky clean

	return 0;
}
