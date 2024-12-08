#pragma once
#include "Node.h"

class TList
{
public:
	Node* m_pRoot;
	Node* m_pNode;

	// Constructor
	TList();
	TList(const char* pSz);
	TList(TList*& _COther);  // (Copy)

	// Returns the number of elements
	int Size();

	// Receives a const char* psz and adds the chain to the list
	void Push(const char* pSz);

	// Returns the first element of the list
	Node* First();

	// Returns the last element of the list
	Node* Last();

	// Returns the next element of the list
	Node* Next();

	// Removes and returns the next element of the list
	Node* Pop();

	// Removes all the elements of the list
	void Reset();
};