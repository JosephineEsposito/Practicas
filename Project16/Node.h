#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
  T m_value;        // Il valore del nodo
  Node* m_next;     // Puntatore al nodo successivo

  // Costruttore di default
  Node() : m_value(T()), m_next(nullptr) {}

  // Costruttore con valore iniziale
  Node(const T& pValue) : m_value(pValue), m_next(nullptr) {}
};

#endif

// Esplicitazione del template per tipi specifici
template class Node<int>;
template class Node<float>;
template class Node<const char*>;
