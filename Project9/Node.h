#pragma once

class Node
{
public:
  const char* cValue;
  Node* next;

  Node();
  Node(const char* _cValue);
};