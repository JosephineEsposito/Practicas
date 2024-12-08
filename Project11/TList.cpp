#include "TList.h"

#include <iostream>

// --- Costruttore --- //
TList::TList()
{
	m_pRoot = nullptr;
	m_pNode = nullptr;
}
TList::TList(const char* pSz)
{
	m_pRoot = new Node(pSz);
	m_pNode = m_pRoot;
}
TList::TList(TList*& _COther)
{
	m_pRoot = nullptr;
	m_pNode = nullptr;
	if (_COther->m_pRoot)
	{
		m_pRoot = new Node();
		m_pRoot->Copy(*_COther->m_pRoot);
		m_pNode = m_pRoot;

    _COther->m_pNode = _COther->m_pRoot;

		while (_COther->m_pNode->m_next)
		{
      m_pNode->m_next = new Node(); //we create a new one
      m_pNode = m_pNode->m_next; //we move to it
     
      _COther->m_pNode = _COther->Next(); //we move the og to the next
      m_pNode->Copy(*_COther->m_pNode); //we copy its value
		}


	}
}

int TList::Size()
{
	if (m_pRoot == nullptr)
	{
		return 0;
	}

	int iCounter = 1;

	m_pNode = m_pRoot;
	while (m_pNode->m_next != nullptr)
	{
		m_pNode = m_pNode->m_next;
		iCounter++;
	}

	return iCounter;
}

void TList::Push(const char* pSz)
{
  if (m_pRoot == nullptr)
  {
    m_pRoot = new Node(pSz);
    m_pNode = m_pRoot;
    return;
  }
  m_pNode = Last();
  m_pNode->m_next = new Node(pSz);
  m_pNode = m_pRoot; //we reset the index back to the beginning
}

Node* TList::First()
{
  m_pNode = m_pRoot;
  return m_pRoot;
}

Node* TList::Last()
{
  if (m_pRoot == nullptr)
  {
    return nullptr;
  }

  m_pNode = m_pRoot;
  while (m_pNode->m_next != nullptr)
  {
    m_pNode = m_pNode->m_next;
  }
  return m_pNode;
}

Node* TList::Next()
{
  if (m_pNode == nullptr)
  {
    return nullptr;
  }

  if (m_pNode->m_next == nullptr)
  {
    return nullptr;
  }

  m_pNode = m_pNode->m_next;
  return m_pNode;
}

Node* TList::Pop()
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

void TList::Reset()
{
  if (m_pRoot == nullptr)
  {
    return;
  }

  m_pNode = m_pRoot;
  if (m_pNode->m_next != nullptr)
  {
    while (m_pNode->m_next->m_next != nullptr)
    {
      m_pNode = m_pNode->m_next;
    }
    delete m_pNode->m_next;
  }
  else
  {
    delete m_pNode;
    //delete pRoot; // this will double delete stai attenta
    m_pNode = nullptr;
    m_pRoot = nullptr;// qua puliamo perchè dopo al delete avrà valori spazzatura
  }
}
