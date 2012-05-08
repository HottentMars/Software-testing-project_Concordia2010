/* ---------------------------------------------------------
 *COEN345 - Software Testing and Validation
 *Project - Data Structure
 *<<Teperature Registration System>>
 *
 *Author:
 *Kaki Wong ?9230971
 *Samson Xian ?6163378 
 *Zhaoyu Zhang - 9097260
 *
 *Fall 2010
 *Concordia University
 * ---------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "uLinkList.h"
#include "iBiDirectionalLinkedList.h"
#include "iArray.h"
#include "iStack.h"
#include "iQueue.h"
#include "binaryTree.h"

void array_submenu(void);
void ullist_submenu(void);
void BiDirectional_Submenu(void);
void Stack_Submenu(void);
void Queue_Submenu(void);

double convertCtoF(int);
bool checkDate (int);
bool checkTemp (int);
void cleancin();

void submenu(int);

int main()
{
	char dsSelect;

	system("cls");
	cout << "Please select the data structure to begin:";
	cout << "\n1.Array\n2.Unidirectional Linked List\n3.Bi-directional Linked List\n4.Stack\n5.Queue\n6.Binary Search Trees\n0.exit the program\n\nPlease choose [1..6]:";
	cin >> dsSelect;

	switch (dsSelect)
	{
		case '1':
			submenu(0);
			break;
		case '2':
			submenu(1);
			break;
		case '3':
			submenu(2);
		   break;
		case '4':
			Stack_Submenu();
			break;
		case '5':
			Queue_Submenu();
			break;
		case '6':
			submenu(3);
			break;
		case '0':	//exit program
		   exit(0);
		   break;
	   default:
		   cout<<"Invalid choice.\n";
		   break;
	}

   system("Pause");
   return 0;
}

void submenu(int ch)
{
	iArray iarray;
	uLinkList uList;
	iBiDirectionalLinkedList BiDirectionalLinkedList;
	binaryTree binTree;

	char sel=NULL;
	int num=0,date,temp,largest;
	const int multiMax = 20;
	int startDate=0,endDate=0;
	int minTemp=0,maxTemp = 0;


	while(sel != '0')
	{
	   system("cls");

		cout<<"\n1.Add data\n2.Add set of data\n3.Remove data\n4.Remove set of data\n";
		cout<<"5.Sort by date(Ascending)\n6.Sort by date(Descending)\n7.Shuffle\n8.Display data\n9.Get Temperature\n";
		cout<<"\na.Highest temperature in a given period\nb.Convert Celsius to Fahrenheit.\nc.Numbers of day where temperature is higher than thresholds t\n";
		cout<<"d.Numbers of day where temperature is between [t1,t2]\n\n0.Exit\n------Choice [0...9] or [a...d]:";
		cin>>sel;
		cout<<"\n";
		switch (sel)
		{
		case('1')://insert data
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}

			while ((cout << "Insert temperature(C): ") && (!(cin >> temp) || checkTemp(temp) == false)) 
				{
					cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
			}

			switch(ch)
			{
			case 0:
				iarray.add(date,temp);
				break;
			case 1:
				uList.insert(date,temp);
				break;
			case 2:
				BiDirectionalLinkedList.add(date,temp);
				break;
			case 3:
				binTree.insert(date,temp);
				break;
			default:
				break;
			}

			break;
		case('2')://insert multiple data


			switch(ch)
			{
			case 0:
				iarray.addset();
				break;
			case 1:
				cout<<"Number of data to be added(MAX 20): ";
				cin>>num;

				if(num <= multiMax)
				{
				   for(int i=0;i<num;i++)
				   {
						while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
						{
						cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
						}
					while ((cout << "Insert temperature(C): ") && (!(cin >> temp) || checkTemp(temp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
					 uList.insert(date,temp);
				  }
			   }
			   else
				   cout<<"ERR: exceed MAX=20\n";
				break;
			case 2:
				BiDirectionalLinkedList.addset();
				break;
			case 3:
				binTree.insertSet();
				break;
			default:
				break;
			}

			break;
		case ('3')://remove data
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}

			switch(ch)
			{
			case 0:
				iarray.remove(date);
				break;
			case 1:
				uList.remove(date);
				break;
			case 2:
				BiDirectionalLinkedList.remove(date);
				break;
			case 3:
				binTree.remove(date);
				break;
			default:
				break;
			}

			break;
		case('4')://remove set of data

			switch(ch)
			{
			case 0:
				iarray.removeset();
				break;
			case 1:
				   cout<<"Number of data to be removed(MAX 20): ";
				   cin>>num;

				   if(num <= multiMax)
				   {
						for(int i=0;i<num;i++)
						{
							while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
							{
							cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
							}
							uList.remove(date);
						}
				   }
				   else
						cout<<"ERR: exceed MAX=20\n";
				break;

			case 2:
				BiDirectionalLinkedList.removeset();
				break;
			case 3:
				binTree.removeSet();
				break;
			default:
				break;
			}

			break;
		case '5'://sort Ascending
			
			switch(ch)
			{
			case 0:
				iarray.sort('A');
				break;
			case 1:
				uList.sortByIndex('A');
				break;
			case 2:
				BiDirectionalLinkedList.sort('A');
				break;
			case 3:
				binTree.sortByIndex('A');
				break;
			default:
				break;
			}


			break;
		case '6'://sort Descending
			switch(ch)
			{
			case 0:
				iarray.sort('D');
				break;
			case 1:
				uList.sortByIndex('D');
				break;
			case 2:
				BiDirectionalLinkedList.sort('D');
				break;
			case 3:
				binTree.sortByIndex('D');
				break;
			default:
				break;
			}

			break;
		case '7'://shuffle

			switch(ch)
			{
			case 0:
				iarray.shuffle();
				break;
			case 1:
				uList.shuffle();
				break;
			case 2:
				BiDirectionalLinkedList.shuffle();
				break;
			case 3:
				binTree.shuffle();
				break;
			default:
				break;
			}


			break;
		case '8'://display

			switch(ch)
			{
			case 0:
				iarray.display();
				break;
			case 1:
				uList.display();
				break;
			case 2:
				BiDirectionalLinkedList.display();
				break;
			case 3:
				binTree.display();
				break;
			default:
				break;
			}

			break;
		case '9':
			cout<<"Input date:";
			cin>>date;

			switch(ch)
			{
			case 0:
				cout<<"Date of "<<date<<" is "<<iarray.getTemperature(date)<<endl;
				break;
			case 1:
				cout<<"Date of "<<date<<" is "<<uList.search(date)<<endl;
				break;
			case 2:
				cout<<"Date of "<<date<<" is "<<BiDirectionalLinkedList.getTemperature(date)<<endl;
				break;
			case 3:
				cout<<"Date of "<<date<<" is "<<binTree.getTemperature(date)<<endl;
				break;
			default:
				break;
			}
			
			break;
		case 'a'://Highest temperature in given date range
			while ((cout << "Insert date1(YYYYMMDD): ") && (!(cin >> startDate) || checkDate(startDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Insert date2(YYYYMMDD): ") && (!(cin >> endDate) || checkDate(endDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			
			switch(ch)
			{
			case 0:
				cout<<iarray.highesttemperature(startDate,endDate)<<"C"<<endl;
				break;
			case 1:
				largest = uList.indexOfLargestBetween(startDate,endDate);
				if(largest != 0)
				{
					cout<<"Maximum temperature between ["<<startDate<<","<<endDate<<"] is: "<<uList.search(largest)<<"on "<<largest<<endl;
				}
				break;
			case 2:
				cout<<BiDirectionalLinkedList.highesttemperature(startDate,endDate)<<"C"<<endl;
				break;
			case 3:
				cout<<binTree.highesttemperature(startDate,endDate)<<"C"<<endl;
				break;
			default:
				break;
			}

			break;
		case 'b'://Convert C -> F
			while ((cout << "Insert date1(YYYYMMDD): ") && (!(cin >> startDate) || checkDate(startDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}

			switch(ch)
			{
			case 0:
				if(iarray.dateExist(date))
				cout<<"Temperature on"<<date<<" is:"<<iarray.getTemperature(date)<<"C and equals "<<convertCtoF(iarray.getTemperature(date))<<"F."<<endl;
				break;
			case 1:
				if(uList.nodeExisted(date))
				{
					cout<<"Temperature on "<<date<<" is: "<<convertCtoF(uList.search(date))<<" in Fahrenheit.\n";
				}
				else
					cout<<date<<" not found.\n";
				break;
			case 2:
				if(BiDirectionalLinkedList.dateExist(date))
				cout<<"Temperature on"<<date<<" is:"<<BiDirectionalLinkedList.getTemperature(date)<<"C and equals "<<convertCtoF(BiDirectionalLinkedList.getTemperature(date))<<"F."<<endl;
				break;
			case 3:
				if(binTree.dateExist(date))
					cout<<"Temperature on "<<date<<" is: "<<convertCtoF(binTree.getTemperature(date))<<" in Fahrenheit.\n";
				break;
			default:
				break;
			}

			break;
		case 'c':
			cout<<"Input threshold temperature(c):";
			cin>>temp;

			switch(ch)
			{
			case 0:
				cout<<"Numbers of date where temperature is greater than "<<temp<<"degree is: "<<iarray.numberofdaysovertemperature(temp)<< " days"<<endl;
				break;
			case 1:
				cout<<"Numbers of date where temperature is greater than "<<temp<<"degree is: "<<uList.numOfNodeGt(temp)<<endl;
				break;
			case 2:
				cout<<"Numbers of date where temperature is greater than "<<temp<<"degree is: "<<BiDirectionalLinkedList.numberofdaysovertemperature(temp)<< " days"<<endl;
				break;
			case 3:
				cout<<"Numbers of date where temperature is greater than "<<temp<<"degree is: "<<binTree.numberofdaysovertemperature(temp)<< " days"<<endl;
				break;
			default:
				break;
			}
			break;
		case 'd':
			while ((cout<<"Input min temperature: ") && (!(cin >> minTemp) || checkTemp(minTemp) == false)) 
					{
					cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}

			while ((cout<<"Input max temperature: ") && (!(cin >> maxTemp) || checkTemp(maxTemp) == false)) 
					{
					cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}

			switch(ch)
			{
			case 0:
				cout<<"Numbers of date where temperature is between ("<<minTemp<<" , "<<maxTemp<<") is: "<<iarray.numberofdaystemperaturebetween(maxTemp,minTemp)<<endl;
				break;
			case 1:
				cout<<"Numbers of date where temperature is between ("<<minTemp<<" , "<<maxTemp<<") is: "<<uList.numOfNodeBtw(minTemp,maxTemp)<<endl; 
				break;
			case 2:
				cout<<"Numbers of date where temperature is between ("<<minTemp<<" , "<<maxTemp<<") is: "<<BiDirectionalLinkedList.numberofdaystemperaturebetween(maxTemp,minTemp)<<endl;
				break;
			case 3:
				cout<<"Numbers of date where temperature is between ("<<minTemp<<" , "<<maxTemp<<") is: "<<binTree.numberofdaystemperaturebetween(minTemp,maxTemp)<<endl;
				break;				
			default:
				break;
			}

			break;
		case '0':
			exit(0);
			break;
		default:
			cout<<"Invalid selection."<<endl;
			break;

		}system("Pause");
	}
}

void Stack_Submenu()
{	
	
	iStack stack;

	char sel=NULL;
	int num=0,date,temp;
	const int multiMax = 20;
	int startDate=0,endDate=0;
	int minTemp=0,maxTemp = 0;
	
	system("cls");
	while(sel != '0')
	{	
	
		
		cout<<"\n1.Push data\n2.Pop data\n3.Search data by date\n4.Display the stack\n";
		cout<<"\na.Highest temperature in a given period\nb.Convert Celsius to Fahrenheit.\nc.Numbers of day where temperature is higher than thresholds t\n";
		cout<<"d.Numbers of day where temperature is between [t1,t2]\n\n0.Exit\n------Choice [0...4] or [a...d]:";
		cin>>sel;
		cout<<"\n";
		switch (sel)
		{
		case('1')://insert data
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Insert temperature(C): ") && (!(cin >> temp) || checkTemp(temp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			stack.push(date,temp);
			break;
		case('2')://pop data
			system("cls");
			stack.pop();
			break;
		case ('3')://search data
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			cout<<"The temperature on "<<date<< " is: " <<stack.getTemperature(date)<< "C";
			break;
		case('4')://display data
			system("cls");
			stack.display();
			break;

		case 'a'://Highest temperature in given date range
			while ((cout << "Insert date1(YYYYMMDD): ") && (!(cin >> startDate) || checkDate(startDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Insert date2(YYYYMMDD): ") && (!(cin >> endDate) || checkDate(endDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			stack.highesttemperature(startDate,endDate);
			break;
		case 'b'://Convert C -> F
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			if(stack.dateExist(date))
				system("cls");
				cout<<"Temperature on"<<date<<" is:"<<stack.getTemperature(date)<<"C and equals "<<convertCtoF(stack.getTemperature(date))<<"F."<<endl;
			break;
		case 'c':
			while ((cout << "Input threshold temperature(c): ") && (!(cin >> temp) || checkTemp(temp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			cout<<"Numbers of date where temperature is greater than "<<temp<<"degree is: "<<stack.numberofdaysovertemperature(temp)<< " days"<<endl;
			break;
		case 'd':
			while ((cout << "Input minimum temperature(c): ") && (!(cin >> minTemp) || checkTemp(minTemp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Input maximum temperature(c): ") && (!(cin >> maxTemp) || checkTemp(maxTemp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			cout<<"Numbers of date where temperature is between ("<<minTemp<<" , "<<maxTemp<<") is: "<<stack.numberofdaystemperaturebetween(maxTemp,minTemp)<<endl;
			break;

		case '0':
			exit(0);
			break;
		default:
			cout<<"Invalid selection."<<endl;
			break;

		}
	}
}

void Queue_Submenu()
{
	system("cls");
	iQueue queue;

	char sel=NULL;
	int num=0,date,temp;
	const int multiMax = 20;
	int startDate=0,endDate=0;
	int minTemp=0,maxTemp = 0;

	system("cls");

	while(sel != '0')
	{
		
		cout<<"\n1.Push data\n2.Pop data\n3.Search data by date\n4.Display the queue\n";
		cout<<"\na.Highest temperature in a given period\nb.Convert Celsius to Fahrenheit.\nc.Numbers of day where temperature is higher than thresholds t\n";
		cout<<"d.Numbers of day where temperature is between [t1,t2]\n\n0.Exit\n------Choice [0...4] or [a...d]:";
		cin>>sel;
		cout<<"\n";
		switch (sel)
		{
		case('1')://insert data
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Insert temperature(C): ") && (!(cin >> temp) || checkTemp(temp) == false)) 
				{
					cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
			}
			queue.push(date,temp);
			break;
		case('2')://pop data
			system("cls");
			queue.pop();
			break;
		case ('3')://search data
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			cout<<"The temperature on "<<date<< " is: " <<queue.getTemperature(date)<< "C";
			break;
		case('4')://display data
			system("cls");
			queue.display();
			break;

		case 'a'://Highest temperature in given date range
			while ((cout << "Insert date1(YYYYMMDD): ") && (!(cin >> startDate) || checkDate(startDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Insert date2(YYYYMMDD): ") && (!(cin >> endDate) || checkDate(endDate) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			queue.highesttemperature(startDate,endDate);
			break;
		case 'b'://Convert C -> F
			while ((cout << "Insert date(YYYYMMDD): ") && (!(cin >> date) || checkDate(date) == false)) 
					{
					cout << "ERROR: INVALID DATE SELECTION OR FORMAT" << endl << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			if(queue.dateExist(date))
				system("cls");
			cout<<"Temperature on"<<date<<" is:"<<queue.getTemperature(date)<<"C and equals "<<convertCtoF(queue.getTemperature(date))<<"F."<<endl;
			break;
		case 'c':
			while ((cout << "Input minimum temperature(c): ") && (!(cin >> temp) || checkTemp(temp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			cout<<"Numbers of date where temperature is greater than "<<temp<<"degree is: "<<queue.numberofdaysovertemperature(temp)<< " days"<<endl;
			break;
		case 'd':
			while ((cout << "Input minimum temperature(c): ") && (!(cin >> minTemp) || checkTemp(minTemp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			while ((cout << "Input maximum temperature(c): ") && (!(cin >> maxTemp) || checkTemp(maxTemp) == false)) 
					{
						cout << "ERROR: TEMPERATURE OUT OF RANGE" << endl << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
					}
			system("cls");
			cout<<"Numbers of date where temperature is between ("<<minTemp<<" , "<<maxTemp<<") is: "<<queue.numberofdaystemperaturebetween(maxTemp,minTemp)<<endl;
			break;

		case '0':
			exit(0);
			break;
		default:
			cout<<"Invalid selection."<<endl;
			break;

		}
	}
}

double convertCtoF(int c)
{
	double f = ( 9 / 5 ) * c + 32;
	return f; 
}
bool checkDate ( int date ) //date validation
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
bool checkTemp ( int temp ) //temp validation
{
	if (temp < -60 || temp > 60) //check temp range
		return 0;
	else
		return 1;
}

