/* ---------------------------------------------------------
 *COEN345 - Software Testing and Validation
 *Project - Data Structure
 *<<Teperature Registration System>>
 *
 *Author:
 *Kaki Wong -9230971
 *Samson Xian -6163378 
 *Zhaoyu Zhang - 9097260
 *
 *Fall 2010
 *Concordia University
 * ---------------------------------------------------------*/

#include "uLinkList.h"
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

/* ---------------------------------------------------------
 * uLinkList default constructor
 * ---------------------------------------------------------*/
uLinkList::uLinkList():head(NULL)
{
}

/* ---------------------------------------------------------
 * Insert a node to the end of the list
 *@ input: int index, int data
 *@ output: none
 * ---------------------------------------------------------*/
void uLinkList::insert(int index,int data)
{
   node *endNode,*newNode;

   if(!nodeExisted(index))
   {
	   if( head == NULL ) 
	   {
		  head = new node;
		  head->data = data;
		  head->index = index;
		  head->next = NULL;
	   }
	   else
	   {
		  endNode = head;
		  while( endNode->next != NULL )
			   endNode = endNode->next;

		  newNode = new node;
		  newNode->data = data;
		  newNode->index = index;
		  newNode->next = NULL;
		  endNode->next = newNode;
	   }
   }
   else
	   cout<<"Index "<<index<<" existed. Insertion Failed\n";
}

/* ---------------------------------------------------------
 * remove a node
 *@ input: int index
 *@ output: none
 * ---------------------------------------------------------*/
void uLinkList::remove( int index )
{
   node *cur,*prev;
   cur = head;

   if(!nodeExisted(index))
   {
	   cout<<"\nDate:"<<index<<" not Found.\n";
	   return;
   }

   if( cur->index == index )
   {
      head = cur->next;
      delete cur;
      return;
   }

   prev = cur;
   while( cur!=NULL )
   {
        if( cur->index == index )
      {
           prev->next = cur->next;
         delete cur;
         return;
      }

      prev = cur;
      cur = cur->next;
   }
  
}

/* ---------------------------------------------------------
 * search a node by index and give the data of the node
 *@ input: int index 
 *@ output: int data 
 * ---------------------------------------------------------*/
int uLinkList::search(int index)
{
	node *cur;
	cur = head;
	while(cur!=NULL)
	{
		if(cur->index == index)
			return cur->data;
		else
			cur = cur->next;
	}
	return -1;
}


/* ---------------------------------------------------------
 * Sort list by index using bubble sort.
 * It can be sorted by ascending and descending order.
 *@ input: char order 'a' or 'd'
 *@ output: none
 * ---------------------------------------------------------*/
void uLinkList::sortByIndex(char order) 
{
	bool sorted = false;
	node *cur,*temp;

	cur = head;
	temp = new node;

	if((order!='A')&&(order!='D'))
	{
		cout<<"ERR: Invalid input parameter.\n";
		return;
	}

	for(int pass = 1; (pass < getLength()) && !sorted; ++pass) //repeat until this list is sorted
	{
		sorted = true;

		for(cur = head;cur->next!=NULL; cur=cur->next)
		{
			switch(order)
			{
			case 'D':
				if(cur->index < cur->next->index) 
				{
					//swap nodes
					temp->index = cur->index;
					temp->data = cur->data;

					cur->index = cur->next->index;
					cur->data = cur->next->data;

					cur->next->index = temp->index;
					cur->next->data = temp->data;

					sorted = false;
				} 
				break;
			case 'A':
				if(cur->index > cur->next->index) 
				{
					//swap nodes
					temp->index = cur->index;
					temp->data = cur->data;

					cur->index = cur->next->index;
					cur->data = cur->next->data;

					cur->next->index = temp->index;
					cur->next->data = temp->data;

					sorted = false;
				} 
				break;
			default:
				break;
			}
		} 
	}
} 

/* ---------------------------------------------------------
 * print list 
 *@ input: none
 *@ output: none 
 * ---------------------------------------------------------*/
void uLinkList::display()
{
   node *q;
   cout<<endl;

   for( q = head ; q != NULL ; q = q->next )
        cout<<q->index<<"\t"<<q->data<<endl;

}

/* ---------------------------------------------------------
 * Obtain length of the list
 *@ input: none
 *@ output: int  
 * ---------------------------------------------------------*/
int uLinkList::getLength()
{
   node *ptr;
   int length=0;
   for( ptr=head ; ptr != NULL ; ptr = ptr->next )
        length++;

   return length;
}

/* ---------------------------------------------------------
 * check a node if it is existed.
 *@ input: int index
 *@ output: bool
 * ---------------------------------------------------------*/
bool uLinkList::nodeExisted(int index)
{
	if(uLinkList::search(index)!=-1)
		return true;
	else
		return false;
}

/* ---------------------------------------------------------
 * randomly suffle the list 
 *@ input: none
 *@ output: none
 * ---------------------------------------------------------*/
void uLinkList::shuffle()
{
	node *cur, *temp=NULL;
	
	cur = head;
	temp = new node;

	srand(time(NULL));

	for(int i=0; i<getLength()/2; i++) //suffle only half of list
	{
		int r = (rand() % getLength()) + 1;
		for(int j=0;j<r-1;j++)
		{
			cur = cur->next;	
		}
		//Randomly pick a node
		temp->index = cur->index;
		temp->data  = cur->data;
			
		//place the node to the end of the list
		remove(cur->index);  
		insert(temp->index, temp->data);
		cur = head;
	}
}

/* ---------------------------------------------------------
 * find the node with the largest data with in a range, and return its index
 *@ input: int minimum index, int maximum index
 *@ output: int index
 * ---------------------------------------------------------*/
int uLinkList::indexOfLargestBetween(int minIndex, int maxIndex)
{
	int max = 0;
	int date = 0;
	node *cur;

	cur = head;

	if((!nodeExisted(minIndex)||(!nodeExisted(maxIndex))))
	{
		cout<<"ERR: Undefined range.\n";
		return 0;
	}
	
	max = search(minIndex);

	while(cur != NULL )
	{
		if((cur->index>=minIndex)&&(cur->index<=maxIndex))
		{
			if(cur->data > max)
			{
				max = cur->data;
				date = cur->index;
			}
		}

		cur=cur->next;
	}
	
	return date;
}

/* ---------------------------------------------------------
 * Count numbers of node greater t
 *@ input: int threshold t
 *@ output: int count
 * ---------------------------------------------------------*/
int uLinkList::numOfNodeGt(int t)
{
	int count = 0;
	node *p = head;
	while(p != NULL)
	{
		if(p->data > t)
		{
			count++;
		}
		p = p->next;
	}
	return count;
}

/* ---------------------------------------------------------
 * Count numbers of node in a given data range 
 *@ input: index of the node
 *@ output: data of the node
 * ---------------------------------------------------------*/
int uLinkList::numOfNodeBtw(int min, int max)
{
	int count = 0;
	node*p = head;
	while(p != NULL)
	{
		if((p->data>min)&&(p->data<max))
		{
			count++;
		}
		p = p->next;
	}
	return count;
}

/* ---------------------------------------------------------
 * uLinkList destructor
 * ---------------------------------------------------------*/
uLinkList::~uLinkList()
{
   node *cur;
   if( head == NULL )
        return;

   while( head != NULL )
   {
      cur = head->next;
      delete head;
      head = cur;
   }
}

