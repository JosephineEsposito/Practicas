#pragma once
#include "CStream.h"


class CTcp : public CStream
{
public:
	const char* cHost;
	unsigned int uPort;

	CTcp();

	void Open() override;
	void Close() override;
	void Read() override;
	void Write() override;
};