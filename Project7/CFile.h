#pragma once // -> to avoid including twice the same header

// F1 on FILE to open online official documentation

namespace FileManager
{
	// Method to open a file
	void* OpenFile(void* _sFile, const char* _sFilename, const char* _sMode);

	// Method to close a file
	bool CloseFile(void* _pFile);

	// Method to read a file
	unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

	// Method to write in a file
	unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

	// Funcion que retorna la suma de los numeros enteros separados por coma presentes en un fichero
	unsigned int SumaEnFichero(void* _pFile);

	// Funcion que retorna el numero de apariciones de una cadena en un fichero
	unsigned int SubStringFind(const char* _pCadena, unsigned int uSize, void* _pFile);
}
