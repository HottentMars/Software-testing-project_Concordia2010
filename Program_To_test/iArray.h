#pragma once
#define ARRAYSIZE 500 //The array size will be limited to 500

class iArray
{

public:
	iArray(void);
	~iArray(void);

	struct weather
	{
		int date;
		int temperature;
	};
	weather mainarray[ARRAYSIZE];

	bool add(weather);//add an object to  the array using the weather object
	bool addset();//add a set of elements
	bool add(int,int);//add an object to the array using date and temperature
	bool remove(int);//remove the object from the array using date
	bool removeset();//remove a set of elements
	int getTemperature(int);//get temperature using date
	bool dateExist(int);//check if the date exists
	bool sort(char);
	bool shuffle();

	bool display();

	int highesttemperature(int,int);
	int numberofdaysovertemperature(int);
	int numberofdaystemperaturebetween(int,int);

	int counter;

};

