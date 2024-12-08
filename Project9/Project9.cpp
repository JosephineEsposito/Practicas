// 13112024 | @josephineesposito
// Project9.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

///
/// Creación de una lista enlazada TList que tenga
/// [X] int size, que retorna el numero de elementos
/// [X] int push, que recibe un const char* psz y añade la cadena a la lista
/// [X] const char* First, que retorna el primer elemento de la lista
/// [X] const char* Next, que retorna el siguiente elemento e la lista
/// [X] const char* Pop, que elimina y retorna el primer elemento de la lista
/// [X] void Reset, que elimina todos los elementos de la lista
///

#include <iostream>
#include "TList.h"
#include "Node.h"

int main()
{
	TList* tList = new TList();
	printf("List size at beginning : %d", tList->Size());

	std::cout << std::endl;

	const char* pSz = "Hola";
	tList->Push(pSz);
	printf("List size after Push : %d", tList->Size());

	std::cout << std::endl;

	Node* pNode = tList->First();
	printf("The first element is %s", pNode->cValue);

	std::cout << std::endl;

	tList->Reset();
	printf("List size after Reset : %d", tList->Size());

	std::cout << std::endl;

	pSz = "Hola";
	tList->Push(pSz);
	pSz = "Como";
	tList->Push(pSz);
	pSz = "Estas";
	tList->Push(pSz);
	printf("List size after 3 Push : %d", tList->Size());

	std::cout << std::endl;

	// prova il next
	pNode = tList->First();
	printf("The first element is %s", pNode->cValue);
	pNode = tList->Next();
	printf(" and the following element is %s", pNode->cValue);

	std::cout << std::endl;

	// prova il pop
	tList->Pop();
	printf("List size after Pop : %d", tList->Size());
}
//EOF