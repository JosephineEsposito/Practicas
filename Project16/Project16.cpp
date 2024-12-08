// Project16.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

///
/// [X] Implementar una lista con la misma funcionalidad que la TList pero que pueda almacenar cualquier tipo de elementos que implementen un interfaz
///

#include <iostream>

#include "TList.h"

int main()
{
	TList<int> iList;
  iList.Push(10);
  iList.Push(20);
  iList.Push(30);

  std::cout << "Integer list size: " << iList.Size() << std::endl;
  Node<int>* currentNode = iList.First();
  while (currentNode) {
    std::cout << currentNode->m_value << " ";
    currentNode = iList.Next();
  }
  std::cout << std::endl;
}
//EOF
