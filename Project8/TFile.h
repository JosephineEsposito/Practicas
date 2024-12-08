#pragma once // -> to avoid including twice the same header

// F1 on FILE to open online official documentation

class TFile
{

public:
	void* _pFile;

	TFile();

	// Method to open a file
	void* OpenFile(const char* _sFilename, const char* _sMode);

	// Method to close a file
	bool CloseFile();

	// Method to read a file
	unsigned int ReadFile(char* _pBuffer, unsigned int _uSize);

	// Method to write in a file
	unsigned int WriteFile(char* _pBuffer, unsigned int _uSize);

	// Funcion que retorna la suma de los numeros enteros separados por coma presentes en un fichero
	unsigned int SumaEnFichero();

	// Funcion que retorna el numero de apariciones de una cadena en un fichero
	unsigned int SubStringFind(const char* _pCadena, unsigned int uSize);
};
