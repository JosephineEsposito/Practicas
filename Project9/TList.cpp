#include <iostream>
#include "TList.h"


TList::TList()
{
  pRoot = nullptr;
  pNode = nullptr;
}
TList::TList(const char* pSz)
{
  pRoot = new Node(pSz);
  pNode = pRoot;
}

int TList::Size()
{
  if (pRoot == nullptr)
  {
    return 0;
  }

  int iCounter = 1;

  pNode = pRoot;
  while (pNode->next != nullptr)
  {
    pNode = pNode->next;
    iCounter++;
  }
  return iCounter;
}

void TList::Push(const char* pSz)
{
  if (pRoot == nullptr)
  {
    pRoot = new Node(pSz);
    pNode = pRoot;
    return;
  }
  pNode = Last();
  pNode->next = new Node(pSz);
  pNode = pRoot; //we reset the index back to the beginning
}

Node* TList::First()
{
  pNode = pRoot;
  return pRoot;
}

Node* TList::Last()
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }

  pNode = pRoot;
  while (pNode->next != nullptr)
  {
    pNode = pNode->next;
  }
  return pNode;
}

Node* TList::Next()
{
  if (pNode == nullptr)
  {
    return nullptr;
  }

  if (pNode->next == nullptr)
  {
    return nullptr;
  }

  pNode = pNode->next;
  return pNode;
}

Node* TList::Pop()
{
  if (pRoot == nullptr)
  {
    return nullptr;
  }
  else if (pRoot->next == nullptr)
  {
    delete pRoot;
    pRoot = nullptr;
    return nullptr;
  }

  pNode = pRoot;
  while (pNode->next->next != nullptr)
  {
    pNode = pNode->next;
  }
  delete pNode->next;
  pNode->next = nullptr;
  return pRoot;
}

void TList::Reset()
{
  if (pRoot == nullptr)
  {
    return;
  }

  pNode = pRoot;
  if (pNode->next != nullptr)
  {
    while (pNode->next->next != nullptr)
    {
      pNode = pNode->next;
    }
    delete pNode->next;
  }
  else
  {
    delete pNode;
    //delete pRoot; // this will double delete stai attenta
    pNode = nullptr;
    pRoot = nullptr;// qua puliamo perchè dopo al delete avrà valori spazzatura
  }
}

//EOF