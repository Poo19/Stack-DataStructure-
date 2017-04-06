#pragma once
#include<iostream>

struct StackNode
{
	char m_cCh;
	StackNode *m_pNext;	
};

class Decoder
{
public:
	StackNode *m_pTop;
	void Push(char ch); 
	char Pop();
public:
	Decoder();
	~Decoder();
	void Decode(char *encMsg, char *decMsg);
};


