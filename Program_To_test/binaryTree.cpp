#include "binaryTree.h"
#include <iostream>
#include <ctime>
using namespace std;

binaryTree::binaryTree()
{
	root = NULL;
	max_temperature = 0.00;
	countNode = 0;
}

binaryTree::~binaryTree()
{
	delete root;
}

void binaryTree::insert(int date,int temperature)
{
	treeNode* newNode = new treeNode(date,temperature);
	treeNode* parent = NULL;

	if(dateExist(date))
	{
		cout<<"date existed"<<endl;
		return;
	}

	if(isEmpty())
		root = newNode;
	else
	{
		treeNode* curr;
		curr = root;

		while(curr)
		{
			parent = curr;
			if(newNode->date>curr->date)
				curr = curr->right;
			else
				curr = curr->left;
		}

		if(newNode->date>parent->date)
			parent->right = newNode;
		else
			parent->left = newNode;
	}
}

bool binaryTree::insertSet()
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
		this->insert(date,temperature);
	}
	return false;
}

void binaryTree::remove(int date)
{
	bool found = false;
	treeNode* curr = root;
	treeNode* parent = root;


	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return;
	}

	//move curr pointer to the element to be deleted
	while(curr)
	{
		if(date==curr->date)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if(date>curr->date)
				curr = curr->right;
			else
				curr = curr->left;
		}
	}
	if(!found)
	{
		cout<<"\nDate:"<<date<<" not Found.\n";
		return;
	}

	//delete a node with no child, which is a leaf node
	if((curr->left == NULL) && (curr->right == NULL))
	{
		if(parent->left == curr)
			parent->left = NULL;
		else
			parent->right = NULL;

		//the last element in the tree to be deleted
		if(parent==curr) 
			root = NULL;

		delete curr;
		
		return;
	}

	//delete a node with a single child
	if((curr->left == NULL) && (curr->right != NULL) ||
		(curr->left !=NULL) && (curr->right == NULL))
	{
		cout<<"case2"<<endl;
		if((curr->left == NULL) && (curr->right != NULL))
		{
			if(parent!=curr)
			{
				if(parent->left == curr)
					parent->left = curr->right;
				else
					parent->right = curr->right;
			}
			else
				root = curr->right;
		}
		else
		{
			if(parent!=curr)
			{
				if(parent->left == curr)
					parent->left = curr->left;
				else
					parent->right = curr->left;
			}
			else
				root = curr->left;
		}
		delete curr;
		return;
	}

	//delete a node with two children
	if((curr->left !=NULL) && (curr->right != NULL))
	{
		cout<<"case3"<<endl;
		if((curr->right)->left != NULL)
		{
			cout<<"case3.1"<<endl;
			treeNode* lcurr=NULL;
			treeNode* lcurrp=NULL;
			lcurrp = curr->right;
			lcurr = (curr->right)->left;
			while(lcurr->left != NULL)
			{
				lcurrp = lcurr;
				lcurr = lcurr->left;
			}
			curr->date = lcurr->date;
			curr->temperature = lcurr->temperature;
			delete lcurr;
			lcurrp->left = NULL;
		}
		else
		{
			cout<<"case3.2"<<endl;
			treeNode* temp;
			temp = curr->right;
			curr->date = temp->date;
			curr->temperature = temp->temperature;
			curr->right = temp->right;
			delete temp;
		}
	return;
	}
}

bool binaryTree::removeSet()
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

int binaryTree::getTemperature(int date)
{
	treeNode* curr = root;
	while(curr)
	{
		if(date==curr->date)
			return curr->temperature;
		else if(date>curr->date)
			curr = curr->right;
		else if(date<curr->date)
			curr = curr->left;
	}
	return -1;
}

void binaryTree::sortByIndex(char ch)
{
	if(ch == 'A')
		inorder(root);
	else if (ch == 'D')
		postorder(root);
}

void binaryTree::shuffle()
{
	treeToQueue(root);
	myQueue.shuffle();
	while(!myQueue.isEmpty())
	{
		weather_type temp;
		temp = myQueue.getPop();
		insert(temp.date,temp.temperature);
		cout<<"Date="<<temp.date<<" temperature="<<temp.temperature<<endl;
	}

}

void binaryTree::display()
{
	preorder(root);
}

//Application functions
double binaryTree::highesttemperature(int date1,int date2)
{
	try
	{
		double temp = findMax(root,date1,date2);
		max_temperature = 0;
		return temp;
	}
	catch(...){}
}

int binaryTree::numberofdaysovertemperature(int t)
{
	try
	{
		int temp = countNodeGT(root,t);
		countNode = 0;
		return temp;
	}
	catch(...){}
}

int binaryTree::numberofdaystemperaturebetween(int temp_min,int temp_max)
{
	int temp = countNodeBtw(root,temp_min,temp_max);
	countNode = 0;
	return temp;
}

//auxiliary operations
bool binaryTree::isEmpty()
{
	return root==NULL;
}

bool binaryTree::dateExist(int date)
{
	if(binaryTree::getTemperature(date)==-1)
		return false;
	else
		return true;
}

bool binaryTree::checkDate ( int date ) //date validation
{
	while (date != 0)
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

bool binaryTree::checkTemp ( int temp ) //temp validation
{
	while ( temp !=0 )
	{
	if (temp < -60 || temp > 60) //check temp range
		return 0;
	else
		return 1;
	}
	return 1;
}

//private data memebers
int binaryTree::getSize(treeNode* root)
{
	if (root==NULL)
	{ 
		return(0); 
	}
	else 
	{ 
		return(getSize(root->left) + 1 + getSize(root->right)); 
	} 
}

void binaryTree::inorder(treeNode* root)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return;
	}

	if(root!=NULL)
	{
		if(root->left)
			inorder(root->left);
		cout<<"Date="<<root->date<<" Temperature="<<root->temperature<<endl;
		if(root->right)
			inorder(root->right);
	}
}

void binaryTree::preorder(treeNode* root)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return;
	}

	if(root!=NULL)
	{
		cout<<"Date="<<root->date<<" Temperature="<<root->temperature<<endl;
		if(root->left)
			preorder(root->left);
		if(root->right)
			preorder(root->right);
	}
}

void binaryTree::treeToQueue(treeNode* root)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return;
	}

	if(root!=NULL)
	{
		treeToQueue(root->left);
		treeToQueue(root->right);
		myQueue.push(root->date,root->temperature);
		remove(root->date);
	}
}


void binaryTree::postorder(treeNode* root)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return;
	}

	if(root!=NULL)
	{
		if(root->right)
			postorder(root->right);
		cout<<"Date="<<root->date<<" Temperature="<<root->temperature<<endl;
		if(root->left)
			postorder(root->left);
	}
}

double binaryTree::findMax(treeNode* tPtr,int date1, int date2)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return 0;
	}

	if(tPtr)
	{
		if((tPtr->date>=date1)&&(tPtr->date<=date2))
			if(tPtr->temperature>max_temperature)
				max_temperature=tPtr->temperature;

		findMax(tPtr->left,date1,date2);
		findMax(tPtr->right,date1,date2);
	}

	return max_temperature;
}

int binaryTree::countNodeGT(treeNode* tPtr,int t)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return 0;
	}

	if(tPtr)
	{
		if(tPtr->temperature>t)
			countNode++;

		countNodeGT(tPtr->left,t);
		countNodeGT(tPtr->right,t);
	}

	return countNode;
}

int binaryTree::countNodeBtw(treeNode* tPtr,int t_min, int t_max)
{
	if(isEmpty())
	{
		cout<<"The tree is empty!"<<endl;
		return 0;
	}

	if(tPtr)
	{
		if((tPtr->temperature>t_min)&&((tPtr->temperature<t_max)))
			countNode++;

		countNodeBtw(tPtr->left,t_min,t_max);
		countNodeBtw(tPtr->right,t_min,t_max);
	}

	return countNode;
}