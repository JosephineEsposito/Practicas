#pragma once
#include "Node.h"

class TList
{
public:
  Node* pRoot;              // root node
  Node* pNode;              // current node

  // Constructor
  TList();
  TList(const char* pSz);

  // Retorna el numero de elementos
  int Size();

  // Recibe un const char* psz y añade la cadena a la lista
  void Push(const char* pSz);

  // Retorna el primer elemento de la lista
  Node* First();

  // Retorna el ultimo elemento de la lista
  Node* Last();

  // Retorna el siguiente elemento de la lista
  Node* Next();

  // Elimina y retorna el siguiente elemento de la lista
  Node* Pop();

  // Elimina todos los elementos de la lista
  void Reset();
};