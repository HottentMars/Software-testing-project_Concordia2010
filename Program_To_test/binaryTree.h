#pragma once
#include <iostream>
#include "iQueue.h"
using namespace std;

class binaryTree 
{
public:
	binaryTree();
	~binaryTree();
	void insert(int,int);
	bool insertSet();

	void remove(int);
	bool removeSet();
	int getTemperature(int);
	void sortByIndex(char);
	void shuffle();
	void display();

	//
	double highesttemperature(int,int);
	int numberofdaysovertemperature(int);
	int numberofdaystemperaturebetween(int,int);

	//
	bool isEmpty();
	bool dateExist(int);
	bool checkTemp(int);
	bool checkDate(int);

private:
	struct treeNode
	{
		int date;
		int temperature;
		treeNode *left;
		treeNode *right;
		treeNode():date(0),temperature(0),left(NULL),right(NULL){}
		treeNode(int d,int t):date(d),temperature(t),left(NULL),right(NULL){}
	};
	
	iQueue myQueue;
	treeNode* root;
	double max_temperature;
	int countNode;
	
	int getSize(treeNode*);	
	void inorder(treeNode*);
	void preorder(treeNode*);
	void postorder(treeNode*);
	void treeToQueue(treeNode*);

	double findMax(treeNode*,int,int);
	int countNodeGT(treeNode*,int);
	int countNodeBtw(treeNode*,int,int);
};