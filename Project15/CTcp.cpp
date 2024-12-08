#include <iostream>
#include "CTcp.h"

CTcp::CTcp()
{
	cHost = "127.0.0.1";
	uPort = 12800;
}

void CTcp::Open()
{
	std::cout << "[CTcp] Opened the stream " << std::endl;
}

void CTcp::Close()
{
	std::cout << "[CTcp] Closed the stream " << std::endl;
}

void CTcp::Read()
{
	std::cout << "[CTcp] Read from stream " << std::endl;
}

void CTcp::Write()
{
	std::cout << "[CTcp] Wrote in stream" << std::endl;
}