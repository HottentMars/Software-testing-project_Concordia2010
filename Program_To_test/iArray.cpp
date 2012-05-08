#include "iArray.h"
#include <iostream>

using namespace std;

iArray::iArray(void)
{
	counter=0;
}


iArray::~iArray(void)
{
}

bool iArray::add(int date, int temperature)
{
	weather w;
	w.date=date;
	w.temperature=temperature;

	add(w);

	return true;
}

bool iArray::add(weather w)
{
	if(counter<ARRAYSIZE)
	{
		mainarray[counter] = w;
		counter++;
	}
	else
	{
		cout<<"Array is full."<<endl;
		return false;
	}
	return true;
}

bool iArray::addset()
{
	int date=1,temperature;

	while (date!=0)
	{
		cout<<"Please enter 0 if you want to stop add more data."<<endl;
		cout<<"Please enter the date(YYYYMMDD):";
		cin>>date;
		cout<<"Please enter the temperature(C):";
		cin>>temperature;
		if(date!=0)
		this->add(date,temperature);
	}
	return false;
}


bool iArray::remove(int idate)
{
	for(int i=0; i<ARRAYSIZE; i++)
	{
		if(mainarray[i].date==idate)
		{
			for(int j=i;j<counter;j++)
			{
				mainarray[j].date=mainarray[j+1].date;
				mainarray[j].temperature=mainarray[j+1].temperature;
			}
			mainarray[counter].date=NULL;
			mainarray[counter].temperature=NULL;
			counter--;
			return true;
		}
	}
	return false;
}

bool iArray::removeset()
{
	int date=1;
	while(date!=0)
	{
		cout<<"Please enter 0 if you want to stop remove data."<<endl;
		cout<<"Please enter the date(YYYYMMDD):";
		cin>>date;
		this->remove(date);
	}
	return true;
}

bool iArray::shuffle()
{
	for(int i=0; i<counter; i++)
	{
		int random=rand()%counter;
		int tempdate=mainarray[0].date,temptemperature=mainarray[0].temperature;
		for(int j=0; j<random; j++)
		{
			mainarray[j].date=mainarray[j+1].date;
			mainarray[j].temperature=mainarray[j+1].temperature;
		}
		mainarray[random].date=tempdate;
		mainarray[random].temperature=temptemperature;

	}
	return true;
}

bool iArray::sort(char type)
{
	bool resort=true;
	while(resort)
	{
		resort=false;
		if(type=='A')
		{
			for(int i=0; i<counter-1; i++)
			{
				if(mainarray[i].date>mainarray[i+1].date)
				{
					int tempdate,temptemperature;
					tempdate=mainarray[i].date;
					temptemperature=mainarray[i].temperature;
					mainarray[i].date=mainarray[i+1].date;
					mainarray[i].temperature=mainarray[i+1].temperature;
					mainarray[i+1].date=tempdate;
					mainarray[i+1].temperature=temptemperature;
					resort=true;
				}
			}
		}
		else if(type=='D')
		{
			for(int i=0; i<counter-1; i++)
			{
				if(mainarray[i].date<mainarray[i+1].date)
				{
					int tempdate,temptemperature;
					tempdate=mainarray[i].date;
					temptemperature=mainarray[i].temperature;
					mainarray[i].date=mainarray[i+1].date;
					mainarray[i].temperature=mainarray[i+1].temperature;
					mainarray[i+1].date=tempdate;
					mainarray[i+1].temperature=temptemperature;
					resort=true;
				}
			}
		}

	}
	
return true;
}

bool iArray::display()
{
	for(int i=0; i<counter; i++)
	{
		cout<<"Date:"<<mainarray[i].date<<" Temperature:"<<mainarray[i].temperature<<endl;
	}
return true;
}

int iArray::highesttemperature(int date1,int date2)
{
	int lowdate,highdate;
	int highesttemp=mainarray[0].temperature;
	if(date1>date2)
	{
		highdate=date1;
		lowdate=date2;
	}
	else
	{
		highdate=date2;
		lowdate=date1;
	}
	for(int i=0; i<ARRAYSIZE; i++)
	{
		if(mainarray[i].temperature>highesttemp)
			highesttemp=mainarray[i].temperature;
	}
	return highesttemp;
}
int iArray::numberofdaysovertemperature(int tempe)
{
	int days=0;
	for (int i=0; i<ARRAYSIZE; i++)
	{
		if(mainarray[i].temperature>tempe)
			days++;
	}

	return days;
}
int iArray::numberofdaystemperaturebetween(int temp1,int temp2)
{
	int days=0;
	int hightemp,lowtemp;
	if(temp1>temp2)
	{
		hightemp=temp1;
		lowtemp=temp2;
	}
	else
	{
		hightemp=temp2;
		lowtemp=temp1;
	}
	for (int i=0; i<ARRAYSIZE; i++)
	{
		if(mainarray[i].temperature>lowtemp && mainarray[i].temperature<hightemp)
			days++;
	}

	return days;
}

int iArray::getTemperature(int date)
{
	int temp=0;
	for (int i=0; i<ARRAYSIZE; i++)
	{if(mainarray[i].date==date)
		{
			temp=mainarray[i].temperature;
			return temp;
		}
	}
	cout<<"\nDate not found!";
	return 0;
}

bool iArray::dateExist(int date)
{
	for (int i=0; i<ARRAYSIZE; i++)
	{
		if(mainarray[i].date==date)
			return true;
	}
	return false;
}