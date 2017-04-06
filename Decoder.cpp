#include<iostream>
#include "Decoder.h"
#include<ctype.h>

using namespace std;

Decoder::Decoder()
{
	m_pTop = NULL;
}
Decoder::~Decoder()
{
	StackNode *temp;
	while(m_pTop != NULL)
	{
	temp = m_pTop;
	m_pTop = m_pTop-> m_pNext;
	delete temp;
	}
}
void Decoder::Push(char ch)
{
	StackNode *tempPtr = new StackNode;
	tempPtr->m_cCh=ch;
	tempPtr->m_pNext=m_pTop;
	m_pTop=tempPtr;
}
char Decoder::Pop()
{
	StackNode *tempPtr;
	if(m_pTop != NULL)
	{   
		tempPtr = m_pTop;
		char Character;
		Character = m_pTop->m_cCh;
		m_pTop = m_pTop-> m_pNext;
		delete tempPtr;
		return Character;
	}
}
void Decoder::Decode(char *encMsg, char *decMsg)
{
	int flag=0;
	while( *encMsg != '\0')
	{
		if(*encMsg == '1')
		{
		Push(*(encMsg+1));
		}
		if(*encMsg == '2')
		{
		Pop();
		flag++;
		}
		encMsg+2;
	}
	while( flag != 0 )
	{
	*decMsg=Pop();
	decMsg++;
	}
}

void main()
{
	char encMsg[200]="1d211X211o211R1u211f1X1O231E1w1q1n231D1{211O1C1y1@1w231E1]1W221D1W1|1r231 1G1m221^1M221Y1B1H231G1N1I1T1S1W1E1U231^1U221B1C221E1I1]1Y231N1M1{231T";
	char decMsg[100];
	Decoder obj_Decode;
	char data = 'h';

	char result;
	obj_Decode.Push(data);
	result = obj_Decode.Pop();
	cout<< result;

	obj_Decode.Decode(encMsg,decMsg);

}
