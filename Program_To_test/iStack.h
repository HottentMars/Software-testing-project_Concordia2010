#pragma once
#include "ibidirectionallinkedlist.h"

class iStack :
	public iBiDirectionalLinkedList
{
public:
	iStack(void);
	~iStack(void);

	bool pop();
	void push(int date,int temperature);
};
