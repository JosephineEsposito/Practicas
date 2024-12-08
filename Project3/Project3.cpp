// 21102024 | @josephineesposito
// Project3.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

#include <iostream>

/*

Hacer una función que, dado un índice a la tabla de cadenas, retorne la cadena de índice dado si exíste
Hacer una función que, dado un índice a la tabla de cadenas, retorne la cadena de índice dado, si existe, invertida

*/

const char* sTablaDeCadenas[]
{
	"Mi primera cadena",
	"Segunda",
	"Tercera",
	"Y ultima!"
};
const unsigned int uTablaDeCadenasSize = sizeof(sTablaDeCadenas) / sizeof(const char*);

// Función que retorna la cadena de índice si existe
const char* GetCadena(unsigned int _uIndex)
{
	if (_uIndex < uTablaDeCadenasSize)
	{
		return sTablaDeCadenas[_uIndex];
	}
	return nullptr;
}

// Función que retorna la cadena de índice si existe e invertida
char* GetCadenaInvertida(unsigned int _uIndex)
{
	const char* sCadenaOriginal = GetCadena(_uIndex);
	if (sCadenaOriginal != nullptr)
	{
		unsigned int uSize = std::strlen(sCadenaOriginal);
		char* sNuevaCadena = new char[uSize + 1];
		sNuevaCadena[uSize] = '\0';

		for (unsigned int uIndex = 0; uIndex < uSize; uIndex++)
		{
			sNuevaCadena[uSize - 1 - uIndex] = sCadenaOriginal[uIndex];
		}
		return sNuevaCadena;
	}
	return nullptr;
}

int main()
{
	printf("%s\n", GetCadena(0));

	char* sCadena = GetCadenaInvertida(0);
	printf("%s\n", sCadena);
	delete sCadena;
}

