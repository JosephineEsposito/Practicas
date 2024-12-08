#pragma once
#include "CStream.h"


class CCom : public CStream
{
public:
	unsigned int uPort;
	unsigned int uAddress;

	CCom();

	void Open() override;
	void Close() override;
	void Read() override;
	void Write() override;
};