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
/*-----------------------------------------
 *Unidimensional linked list class
 *-----------------------------------------*/

class uLinkList
{
public:
	uLinkList();
	~uLinkList();
	
	//basic operations
    void insert(int,int);
    void remove(int);
	int search(int);
	void sortByIndex(char);
	void shuffle();
    void display();	


	//auxiliary operations
    int getLength();
	bool nodeExisted(int);
	int indexOfLargestBetween(int, int); 
	int numOfNodeGt(int);
	int numOfNodeBtw(int,int); 

private:
    struct node
    {
		int index;		
		int data;
		node *next;
    };
	node *head;
};