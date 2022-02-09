/*
 * ChildNode.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: theresesmith
 */

#include "ChildNode.h"

ChildNode::ChildNode() {
	// TODO Auto-generated constructor stub
	searched = false;
	childrenHaveBeenAdded = false;
	myChildrenP = makeEmptyLinkedList();
}

ChildNode::~ChildNode() {
	// TODO Auto-generated destructor stub
}

bool ChildNode::getSearched()
{
	return searched;
}
void ChildNode::setSearched(bool s)
{
	searched = s;
}
bool ChildNode::getChildrenHaveBeenAdded()
{
	return searched;
}
void ChildNode::setChildrenHaveBeenAdded(bool s)
{
	searched = s;
}
void ChildNode::addChild(ChildNode* c)
{
	//list of children should contain c, exactly once
	//puts("starting add child"); fflush(stdout);
	if(!isMember(c->getNodeNumber()))
	{
		if((myChildrenP->payP) ==0)//is the list empty?
		{
			myChildrenP->payP = (int*) malloc (sizeof(int)); //memory to store the int
			*(myChildrenP->payP) = c->getNodeNumber();
			//printf("Adding child %d.", c->getNodeNumber()); fflush(stdout);
		}
		else
		{
			//traverse the list
			LLNode* temp = myChildrenP;
			while(temp->next)
			{
				temp=(LLNode*)temp->next;
			}
			//add it
			//puts("about to add by extending list");fflush(stdout);
			LLNode* newList = makeEmptyLinkedList();  //<- this now sets begin1, which it should not
			newList->payP = (int*) malloc (sizeof(int)); //memory to store the int
			*(newList->payP) = c->getNodeNumber();
			temp->next = (struct LLNode*)newList;
			newList->prev = (struct LLNode*) temp;
		}
	}
}

int ChildNode::getNodeNumber()
{
	return nodeNumber;
}
void ChildNode::setNodeNumber(int s)
{
	nodeNumber = s;
}
LLNode* ChildNode::makeEmptyLinkedList()
{
	LLNode* nbg = (LLNode*) malloc(sizeof(LLNode));
	nbg->next = (struct LLNode*)0;
	nbg->prev = (struct LLNode*)0;
	nbg->payP = (int*)0;

	return nbg;
}
bool ChildNode::isMember(int c)
{
	bool answer = false;
	//puts("Starting isMember"); fflush(stdout);
	//printf("myChildrenP is %p\n", myChildrenP);fflush(stdout);
	//printf("its payp is %p\n", myChildrenP->payP);
	if((myChildrenP->payP) ==0)
	{
		//puts("isMember found empty list"); fflush(stdout);
	}
	else
	{
		//puts("isMember did not find empty list"); fflush(stdout);
		//traverse the list
		LLNode* temp = myChildrenP;
		while(!answer && temp->next)
		{
			if(*(temp->payP) == c)
			{
				answer = true;
			}
			temp=(LLNode*)temp->next;
		}
		if(*(temp->payP) == c)
		{
			answer = true;
		}
	}
	return answer;
}
void ChildNode::printYourChildren()
{
	printf("From node %d, my children are:\n", nodeNumber); fflush(stdout);
	if((myChildrenP->payP) ==0)//is it empty?
	{
		puts("I have no children");
	}
	else
	{
		//traverse the list
		LLNode* temp = myChildrenP;
		while(temp->next)
		{
			printf(" Node %d and ", *(temp->payP));
			temp=(LLNode*)temp->next;

		}
		printf("%d.\n", *(temp->payP));
	}
}
