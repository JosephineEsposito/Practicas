#pragma once
#include "CStream.h"


class CFile : public CStream
{
public:
	const char* cMode;

	CFile();

	void Open() override;
	void Close() override;
	void Read() override;
	void Write() override;
};