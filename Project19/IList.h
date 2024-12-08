#pragma once

#ifndef ILIST_H
#define ILIST_H

#include "Node.h"

template <typename T>
class IList
{
public:
	virtual ~IList() = default;

	virtual void Push(const T& pValue) = 0;
	virtual Node<T>* Pop() = 0;
	virtual int Size() = 0;
	virtual Node<T>* First() = 0;
	virtual Node<T>* Last() = 0;
	virtual Node<T>* Next() = 0;
	virtual void Reset() = 0;
};

#endif