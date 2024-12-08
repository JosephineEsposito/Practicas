#ifndef TLIST_H
#define TLIST_H

#include "IList.h"
#include "Node.h"

template <typename T>
class TList : public IList<T> {
private:
  Node<T>* m_pRoot;  // Radice della lista
  Node<T>* m_pNode;  // Nodo corrente

public:
  // Costruttore
  TList();

  // Costruttore con un valore iniziale
  TList(const T& value);

  // Metodo per aggiungere un elemento
  void Push(const T& value) override;

  // Metodo per rimuovere e restituire l'elemento
  Node<T>* Pop() override;

  // Restituisce la dimensione della lista
  int Size() override;

  // Restituisce il primo nodo
  Node<T>* First() override;

  // Restituisce l'ultimo nodo
  Node<T>* Last() override;

  // Restituisce il nodo successivo
  Node<T>* Next() override;

  // Resetta la lista
  void Reset() override;
};

#endif // TLIST_H
