#include "iQueue.h"
#include <iostream>

using namespace std;

iQueue::iQueue(void)
{
	head = NULL;
	tail = NULL;
}

iQueue::~iQueue(void)
{
}

void iQueue::push(int date,int temperature)
{
	this->add(date,temperature);
}

bool iQueue::pop()
{
	if(head != NULL)
	{
		cout<<"Date:"<<this->head->w.date<<" Temperature:"<<this->head->w.temperature<<" has been removed"<<endl;
		head=head->after;
		if(head == NULL)
		{
			tail  = NULL;
		}
		return true;
	}
	else
	{
		cout<<"No element in the queue."<<endl;
		return false;
	}
}

weather_type iQueue::getPop()
{
	weather_type temp;

	if(!isEmpty())
	{
		temp.date=this->head->w.date;
		temp.temperature=this->head->w.temperature;
		head=head->after;
	}
	tail = NULL;
	return temp;
}

bool iQueue::isEmpty()
{
	return head==NULL;
}
