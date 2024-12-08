// 16102024 | @josephineesposito
// Project2.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>

int main()
{
	int iValue = 65535; // -> FFFF, 26 -> 0x1A

	// obtener por separado cada uno de los byte que lo forman
	int* _pInt = &iValue;
	int iLen = sizeof(*_pInt);
	unsigned char* uBytes = reinterpret_cast<unsigned char*>(_pInt);
	std::cout << "Cada byte del entero : ";
	for (int i = 0; i < iLen; i++)
	{
		printf("%02hhx", *(uBytes + i));
	}
	std::cout << std::endl;



	int iTabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };
	int* _pValue = iTabla;

	// obtener el entero mayor
	const int iSizeTable = sizeof(iTabla) / sizeof(int);
	int iIntMayor = 0;
	for (int i = 0; i < 7; i++)
	{
		if (*(_pValue + i) > iIntMayor)
		{
			iIntMayor = *(_pValue + i);
		}
	}
	printf("El entero mayor es : %d\n", iIntMayor);


	
	// obtener el byte mayor
	uBytes = reinterpret_cast<unsigned char*>(_pValue);
	unsigned char iCharMayor = *uBytes;
	const int iSizeTable2 = sizeof(iTabla); // para practica

	for (int i = 0; i < iSizeTable2; i++)
	{
		if (*(uBytes + i) > iCharMayor)
		{
			iCharMayor = *(uBytes + i);
		}
	}
	printf("El byte mayor es: %X\n", iCharMayor);



	char sText[] = "Josephine";

	// darle la vuelta
	iLen = sizeof(sText);
	char* _pSText = sText;

	std::cout << "El texto revuelto es : ";
	for (int i = iLen - 1; i >= 0; i--)
	{
		printf("%c", *(_pSText + i));
	}
	std::cout << std::endl;
}