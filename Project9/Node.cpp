#include "Node.h"

// --- Costruttore --- //
Node::Node()
{
  next = nullptr;
  cValue = nullptr;
}
Node::Node(const char* _cValue)
{
  cValue = _cValue;
  next = nullptr;
}

