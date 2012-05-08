#include "iBiDirectionalLinkedList.h"
#include <iostream>

using namespace std;

iBiDirectionalLinkedList::iBiDirectionalLinkedList(void)
{

	head = NULL;
	tail = NULL;
}

iBiDirectionalLinkedList::~iBiDirectionalLinkedList(void)
{
}

bool iBiDirectionalLinkedList::add(int date,int temperature)
{
	if(head==NULL&&tail==NULL)
	{
		BiDirectional * Bi = new BiDirectional;
		Bi->before=NULL;
		Bi->after=NULL;
		Bi->w.date=date;
		Bi->w.temperature=temperature;
		head=Bi;
		tail=Bi;
	}
	else
	{
		BiDirectional * temp = head;
		while(temp->after!=NULL)
		{
			temp=temp->after;
		}
		BiDirectional * temp2 = new BiDirectional;
		temp->after=temp2;
		temp2->before=temp;
		temp2->w.date=date;
		temp2->w.temperature=temperature;
		temp2->after=NULL;
		tail=temp2;
	}
	return true;
}

bool iBiDirectionalLinkedList::addset()
{
	int date=1,temperature;

	while (date!=0)
	{
		cout<<"Please enter 0 if you want to stop add more data."<<endl;
		while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
		while ((cout << "Insert temperature(C): ") && (!(cin >> temperature) || checkTemp(temperature) == false)) 
					{
					cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
		if(date!=0)
			this->add(date,temperature);
	}
	return false;
}

bool iBiDirectionalLinkedList::remove(int date)
{
	BiDirectional * temp = head;
	while(temp!=NULL)
	{
		if(temp->w.date==date)
		{
			if(temp->before!=NULL)
			temp->before->after=temp->after;
			if(temp->after!=NULL)
			temp->after->before=temp->before;
			if(temp->after==NULL)
			{
				tail=temp->before;
			}
			else if(temp->before==NULL)
			{
				head=temp->after;
			}
			delete temp;
			return true;
		}
		temp=temp->after;
	}
	cout<<"Date not found."<<endl;
	return false;
}

bool iBiDirectionalLinkedList::removeset()
{
	int date=1;
	while(date!=0)
	{
		cout<<"Please enter 0 if you want to stop remove data."<<endl;
		while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
		this->remove(date);
	}
	return true;
}

bool iBiDirectionalLinkedList::shuffle()
{
	int i=0;
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		temp=temp->after;
		i++;
	}

	for(int j=0;j<i;j++)
	{
		int tempdate=head->w.date,temptemperature=head->w.temperature;
		int random=rand()%i;
		temp=head;

		for(int k=0;k<random;k++)
		{
			temp=temp->after;
		}
		head->w.date=temp->w.date;
		head->w.temperature=temp->w.temperature;
		temp->w.date=tempdate;
		temp->w.temperature=temptemperature;
		
	}
	return true;
}

bool iBiDirectionalLinkedList::sort(char type)
{
	int i=0;
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		temp=temp->after;
		i++;
	}

	bool resort=true;

	while(resort)
	{
		temp=head;
		resort=false;
		if(type=='A')
		{
			while(temp->after!=NULL)
			{
				if(temp->w.date>temp->after->w.date)
				{
					int tempdate=temp->w.date,temptemperature=temp->w.temperature;
					temp->w.date=temp->after->w.date;
					temp->w.temperature=temp->after->w.temperature;
					temp->after->w.date=tempdate;
					temp->after->w.temperature=temptemperature;

					resort = true;
				}
				temp=temp->after;
			}
		}
		else if(type =='D')
		{
			while(temp->after!=NULL)
			{
				if(temp->w.date<temp->after->w.date)
				{
					int tempdate=temp->w.date,temptemperature=temp->w.temperature;
					temp->w.date=temp->after->w.date;
					temp->w.temperature=temp->after->w.temperature;
					temp->after->w.date=tempdate;
					temp->after->w.temperature=temptemperature;

					resort = true;
				}
				temp=temp->after;
			}
		
		}
	}
	return true;
}

bool iBiDirectionalLinkedList::display()
{
		BiDirectional * temp=head;
		while(temp!=NULL)
		{
			cout<<"Date:"<<temp->w.date<<" Temperature:"<<temp->w.temperature<<endl;
			temp=temp->after;
		}
return true;
}
 
bool iBiDirectionalLinkedList::dateExist(int date)
{
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		if(temp->w.date==date)
			return true;
		temp=temp->after;
	}
	return false;
}

int iBiDirectionalLinkedList::highesttemperature(int date1, int date2)
{
	int lowdate,highdate;
	int highesttemp;
	bool found=false;
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
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		if(temp->w.date>lowdate && temp->w.date<highdate && temp->w.temperature>highesttemp)
		{highesttemp=temp->w.temperature;found=true;}
		temp=temp->after;
	}
	
	if(found)
		cout<<"The highest temperature is: "<<highesttemp<<"C"<<endl;
	else
		cout<<"No data found."<<endl;

	return 0;

}

int iBiDirectionalLinkedList::numberofdaysovertemperature(int tempe)
{
	int days=0;
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		if(temp->w.temperature>tempe)
			days++;
		temp=temp->after;
	}
	return days;
}

int iBiDirectionalLinkedList::numberofdaystemperaturebetween(int temp1, int temp2)
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
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		if(temp->w.temperature>lowtemp && temp->w.temperature<hightemp)
			days++;
		temp=temp->after;
	}
	return days;

}

int iBiDirectionalLinkedList::getTemperature(int date)
{
	BiDirectional * temp=head;
	while(temp!=NULL)
	{
		if(temp->w.date==date)
			return temp->w.temperature;
		temp=temp->after;
	}
	return false;
}
bool iBiDirectionalLinkedList::checkDate ( int date ) //date validation
{
	while(date!=0)
	{
	int year = date / 10000; //find year
	int month = ( date % 10000 ) / 100; //find month
	int day = date % 100; //find day
	
	if (year < 1900 || year > 2100) //check year range
		return 0;
	if (month < 1 || month > 12)//check month range
		return 0;
	if (day < 1 || day > 31)//check day range
		return 0;
	
	if ( (year % 4 == 0) || (year % 400 == 0) || (year % 100 != 0) ) // check leap year
 	{
		if ( month == 2)
			if ( day > 29 )
			return 0; // date is invalid
		else
		if ( (month == 4) || (month == 6) || (month == 9) || (month == 12) )
			if ( day > 30 )
			return 0; // date is invalid
		else
			if ( day > 31 )
			return 0; // date is invalid
  	}
  	else // everything else
  	{
		if ( month == 2)
			if ( day > 28 )
			return 0; // date is invalid
		else
		if ( (month == 4) || (month == 6) || (month == 9) || (month == 12) )
			if ( day > 30 )
			return 0; // date is invalid
		else
			if ( day > 31 )
			return 0; // date is invalid
	}
	//system("Pause");
	return 1;
	}
	return 1;
}
bool iBiDirectionalLinkedList::checkTemp ( int temp ) //temp validation
{
	while ( temp != 0)
	{
	if (temp < -60 || temp > 60) //check temp range
		return 0;
	else
		return 1;
	}
	return 1;
}
