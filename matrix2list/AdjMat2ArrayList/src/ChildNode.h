/*
 * ChildNode.h
 *
 *  Created on: Feb 6, 2022
 *      Author: theresesmith
 */

#ifndef CHILDNODE_H_
#define CHILDNODE_H_

#include <stdlib.h>
#include <stdio.h>
struct LLNode;
typedef struct LLNode
{
	struct LLNode* next;
	struct LLNode* prev;
	int* payP;
}LLNode;

class ChildNode {
public:
	ChildNode();
	virtual ~ChildNode();
	bool getSearched();
	void setSearched(bool s);
	bool getChildrenHaveBeenAdded();
	void setChildrenHaveBeenAdded(bool s);
	void addChild(ChildNode* c);
	bool isMember(int c);
	int getNodeNumber();
	void setNodeNumber(int);
	LLNode* makeEmptyLinkedList();
	void printYourChildren();

private:
	bool searched;
	bool childrenHaveBeenAdded;
	LLNode* myChildrenP;
	int nodeNumber;
};

#endif /* CHILDNODE_H_ */
