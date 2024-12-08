// 22102024 | @josephineesposito
// Project11.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

///
/// constructores
/// [X] Realizar un constructor de copia para la lista enlazada de la práctica 9
/// [X] Realizar una función a la que se le pasa una lista y retorna otra lista con los elementos invertidos.La declaración se tiene que ajustar a : TList GetReverseList(TList lstSrc)
/// [X] Observar las llamadas al constructor de copia y rediseñar la función(cambiando el prototipo de la misma) para maximizar el rendimiento de la misma
///

#include <iostream>

#include "TList.h"
#include "Node.h"

TList* GetReverseList(TList* _tList)
{
	TList* tReversed_ = new TList(); // Creiamo una nuova lista vuota per gli elementi invertiti

	// Puntatore al primo nodo della lista originale
	Node* pNode = _tList->First();

	// Iteriamo attraverso la lista originale
	while (pNode != nullptr)
	{
		// Inseriamo ogni elemento all'inizio della lista invertita
		if (tReversed_->m_pRoot == nullptr)
		{
			// Primo elemento: creare la radice
			tReversed_->m_pRoot = new Node(pNode->m_cValue);
			tReversed_->m_pNode = tReversed_->m_pRoot;
		}
		else
		{
			// Creare un nuovo nodo e collegarlo in testa
			Node* newNode = new Node(pNode->m_cValue);
			newNode->m_next = tReversed_->m_pRoot; // Collegare al vecchio root
			tReversed_->m_pRoot = newNode;        // Aggiornare il root
		}

		// Passare al nodo successivo nella lista originale
		pNode = pNode->m_next;
	}

	return tReversed_; // Restituiamo la nuova lista invertita
}


int main()
{
	TList* tList = new TList();
	printf("List size at beginning : % d", tList->Size());

	std::cout << std::endl;

	tList->Push("Hola");
	printf("List size after Push : %d", tList->Size());

	std::cout << std::endl;

	Node* pNode = tList->First();
	printf("The first element is %s", pNode->m_cValue);

	std::cout << std::endl;

	tList->Reset();
	printf("List size after Reset : %d", tList->Size());

	std::cout << std::endl;

	tList->Push("Hola");
	tList->Push("Como");
	tList->Push("Estas");

	printf("List size after 3 Push : %d", tList->Size());

	std::cout << std::endl;

	pNode = tList->First();
	printf("The first element is %s", pNode->m_cValue);
	pNode = tList->Next();
	printf(" and the following element is %s", pNode->m_cValue);

	std::cout << std::endl;

	tList->Pop();
	printf("List size after Pop : %d", tList->Size());

	std::cout << std::endl;

	// Costruttore Copia
	TList* new_tList = new TList(tList);

	printf("New list size is : %d\n", new_tList->Size());
	printf("Old list size is : %d", tList->Size());

	std::cout << std::endl;

	TList* tReversedList = GetReverseList(tList);

	pNode = tReversedList->First();
	printf("The first element is %s", pNode->m_cValue);
	pNode = tReversedList->Next();
	printf(" and the following element is %s", pNode->m_cValue);
}
//EOF