#include "iStack.h"
#include <iostream>

using namespace std;

iStack::iStack(void)
{
	head = NULL;
	tail = NULL;
}

iStack::~iStack(void)
{
}

void iStack::push(int date, int temperature)
{
	this->add(date,temperature);
}

bool iStack::pop()
{
	if (tail != NULL)
	{
		cout<<"Date:"<<this->tail->w.date<<" Temperature:"<<this->tail->w.temperature<<" has been removed"<<endl;
		tail=tail->before;
		if(tail != NULL)
		{
		tail->after=NULL;
		}
		if(tail == NULL)
		{
			head  = NULL;
		}
		return true;
	}
	else
	{
		cout<<"No element in the stack."<<endl;
		return false;
	}
}