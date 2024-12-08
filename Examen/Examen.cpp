// 29102024 | @josephineesposito
// Examen.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

#include <iostream>


// función que dado un color en formato ARGB (0xAARRGGBB) retorne un entero con la cantidad de verde
// en el mismo
unsigned int CantidadVerde(unsigned int _uColor)
{
	// 0000 0000 - 0000 0000 - 0000 0000 - 0000 0000
	//    F    F      3    2      A    8      5    2
	//		A    A      R    R      G    G      B    B
	// ---------------------------------------------
	// 
	unsigned int _uVerde = _uColor >> 8;

	_uVerde = _uVerde & 0x000000FF;

	return _uVerde;
}

int main()
{
	//unsigned int uColor = 0xFF32A852; //  Green = 168
	//std::cout << "Cantidad de verde presente en " << uColor << " equivale a " << CantidadVerde(uColor);

	size_t sz = 4;
	while (--sz >= 0)
	{
		std::cout << sz << std::endl;
	}

}

