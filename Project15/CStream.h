#pragma once

class CStream
{
public:
	const char* cConnection;

	CStream();
	
	virtual void Open();

	virtual void Close();

	virtual void Read();

	virtual void Write();

};