#pragma once
#include "ibidirectionallinkedlist.h"

typedef struct weather
{
	int date;
	int temperature;
}weather_type;


class iQueue :
	public iBiDirectionalLinkedList
{
public:

	iQueue(void);
	~iQueue(void);

	bool pop();
	weather_type getPop();
	void push(int date,int temperature);

	bool isEmpty();
};
