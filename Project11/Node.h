#pragma once

class Node
{
public:
	const char* m_cValue;
	Node* m_next;

	Node();
	Node(const char* _cValue);

	void Copy(const Node& _COther);
};