#include "Node.h"

#include <iostream>
#include <cstring> // For strlen
#include <cstdio>  // For strcpy_s

// --- Costruttore --- //
Node::Node()
{
	m_next = nullptr;
	m_cValue = nullptr;
}
Node::Node(const char* _cValue)
{
	m_cValue = _cValue;
	m_next = nullptr;
}


void Node::Copy(const Node& _COther)
{
  // Libera la memoria esistente per evitare perdite
  if (m_cValue)
  {
    delete[] m_cValue;
    m_cValue = nullptr;
  }

  // Copia profonda di _COther.m_cValue
  if (_COther.m_cValue)
  {
    m_cValue = _COther.m_cValue;
  }

  // Copia o reset di m_next
  m_next = nullptr; // Modifica secondo la logica della tua lista collegata
}