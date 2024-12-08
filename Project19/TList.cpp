#include "TList.h"

// Costruttore di default
template <typename T>
TList<T>::TList() : m_pRoot(nullptr), m_pNode(nullptr) {}

// Costruttore con valore iniziale
template <typename T>
TList<T>::TList(const T& pValue)
{
  m_pRoot = new Node<T>(pValue);
  m_pNode = m_pRoot;
}

// Metodo per aggiungere un elemento
template <typename T>
void TList<T>::Push(const T& pValue)
{
  if (m_pRoot == nullptr)
  {
    m_pRoot = new Node<T>(pValue);
    m_pNode = m_pRoot;
    return;
  }

  m_pNode = Last();
  m_pNode->m_next = new Node<T>(pValue);
  m_pNode = m_pRoot; // Reset del nodo corrente all'inizio
}

// Metodo per rimuovere e restituire l'elemento
template <typename T>
Node<T>* TList<T>::Pop()
{
  if (m_pRoot == nullptr)
  {
    return nullptr;
  }
  else if (m_pRoot->m_next == nullptr)
  {
    delete m_pRoot;
    m_pRoot = nullptr;
    return nullptr;
  }

  m_pNode = m_pRoot;
  while (m_pNode->m_next->m_next != nullptr)
  {
    m_pNode = m_pNode->m_next;
  }
  delete m_pNode->m_next;
  m_pNode->m_next = nullptr;
  return m_pRoot;
}

// Restituisce la dimensione della lista
template <typename T>
int TList<T>::Size()
{
  int iCounter = 0;
  m_pNode = m_pRoot;
  while (m_pNode)
  {
    ++iCounter;
    m_pNode = m_pNode->m_next;
  }
  return iCounter;
}

// Restituisce il primo nodo
template <typename T>
Node<T>* TList<T>::First()
{
  m_pNode = m_pRoot;
  return m_pRoot;
}

// Restituisce l'ultimo nodo
template <typename T>
Node<T>* TList<T>::Last()
{
  if (!m_pRoot) return nullptr;

  m_pNode = m_pRoot;
  while (m_pNode->m_next)
  {
    m_pNode = m_pNode->m_next;
  }
  return m_pNode;
}

// Restituisce il nodo successivo
template <typename T>
Node<T>* TList<T>::Next()
{
  if (!m_pNode) return nullptr;
  m_pNode = m_pNode->m_next;
  return m_pNode;
}

// Resetta la lista
template <typename T>
void TList<T>::Reset()
{
  while (m_pRoot)
  {
    Node<T>* temp = m_pRoot;
    m_pRoot = m_pRoot->m_next;
    delete temp;
  }
  m_pNode = nullptr;
}

// Esplicitazione dei template per i tipi che si intende usare
template class TList<int>;
template class TList<float>;
template class TList<const char*>;
