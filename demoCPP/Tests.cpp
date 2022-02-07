/*
 * Tests.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}
bool Tests::tests() {
	bool answer = true;
	// This will invoke the other tests
	bool ok1 = testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
	return answer;
}
bool Tests::testReadFile()
{

	puts("starting testReadFile"); fflush(stdout);
	bool ok = false;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;

	AdjMat* adjMP = new AdjMat();
	Room* theRoomPs[10];//addresses for 10 rooms

	Production* pP = new Production();
	ok = pP->readFile("houseGraph.txt", &answer, adjMP, theRoomPs); //read the file
	if(ok)
	{
		if(answer!=rightAnswer)
		{
			puts("test failed on number of rooms");
		}
		else
		{
			puts("read file succeeded on number of rooms");
		}

	}
	else
	{
		puts("test failed on finding file");
	}
	puts("The adjacency matrix");
	for(int i = 0; i<answer; i++)
	{
		for(int j = 0; j<answer; j++)
		{
			printf("%d",adjMP->getEdge(i, j));

		}
		printf("\n");
	}
	puts("The treasure values");
	for(int i = 0; i<answer; i++)
	{
		printf("%f\n", theRoomPs[i]->getTreasure());
	}

	return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
	bool ans = true;
	puts("starting testGotAdjacencyMatrix"); fflush(stdout);


	return ans;
}
bool Tests::testMakeLList()
{
	bool ok = true;
	puts("starting testMakeLList");fflush(stdout);
	//what are the criteria for success for make LList?
	//should be able to make one, add data to it, get the data back
	//test case 1:
	LinkedList* theListP = new LinkedList();
	LLNode* nbg = theListP->makeEmptyLinkedList();
	theListP->setBegin1(nbg);
	printf("The pointer itself is %p.\n", nbg);
	printf("The payload pointer is %p.\n",nbg->payP);
	printf("The next pointer is %p.\n", nbg->next); fflush(stdout);
	LLNode* x = theListP->getBegin1();
	printf("The pointer itself is %p.\n", x);
	printf("The payload pointer is %p.\n",x->payP);
	printf("The next pointer is %p.\n", x->next); fflush(stdout);
	bool rightAnswer = true;
	bool answer = theListP->isEmpty();
	if(answer!=rightAnswer)
	{
		ok = false;
		puts("The list was not judged empty, but should have been.");
	}
	//test case 2:
	//TODO more test cases here
	else
	{
		puts("test make LList passed.");
	}

	return ok;
}

bool Tests::testLinkedList()
{
	bool ok = true;
	puts("starting testLinkedList"); fflush(stdout);
	return ok;
}
bool Tests::testEnqueue()
{
	bool ok = true;
	puts("starting testEnqueue"); fflush(stdout);
	return ok;
}
bool Tests::testRemoveFromList()
{
	bool ok = true;
	puts("starting testRemoveFromList"); fflush(stdout);
	//cases:
	//1 list is empty:return same list
	//2 list is of length one, and item is present: return empty list
	//3 list is of length one, and item is not present: return same list
	//4 list is longer than one, item is present, at first location: return list starting at second element
	//5 list is longer than one, item is present, not at first location: return list with item removed
	//6 list is longer than one, item is not present: return same list
	LinkedList* case1 = new LinkedList();
	LLNode* nbg = case1->makeEmptyLinkedList();
	case1->setBegin1(nbg);
	Payload* pay1 = new Room();
	pay1->setRoomNumber(1);
	LLNode* ans = case1->removeFromList(pay1);
	if((ans != case1->getBegin1()) || (ans->payP != (Payload*)0))
	{
		ok = false;

	}
	printf("testRemove case 1 with %d\n", ok); fflush(stdout);
	case1->savePayload(pay1);
	//this is case2
	ans = case1->removeFromList( pay1);
	if((ans != case1->getBegin1()) || (ans->payP != (Payload*)0))
	{
		ok = false;

	}
	printf("testRemove case 2 with %d\n", ok); fflush(stdout);
	//now case 3
	Payload* pay3 = (Payload*) malloc(sizeof(Room));
	pay3->setRoomNumber(3);
	ans = case1->removeFromList(pay3);
	if(ans != case1->getBegin1())//this is only a partial check for list unchanged
	{
		ok = false;

	}
	printf("testRemove case 3 with %d\n", ok); fflush(stdout);
	//now case 4
	nbg = case1->makeEmptyLinkedList();
	case1->setBegin1(nbg);
	pay1 = new Room();
	pay1->setRoomNumber(1);
	case1->savePayload(pay1);
	pay3 = new Room();
	pay3->setRoomNumber(3);
	case1->savePayload(pay3);
	ans = case1->removeFromList(pay1);

	if(ans == case1->getBegin1())
	{
		ok = false;

	}
	printf("testRemove case 4 with %d\n", ok); fflush(stdout);
	//now case 5
	nbg = case1->makeEmptyLinkedList();
	case1->setBegin1(nbg);
	pay1 =  new Room();
	pay1->setRoomNumber(1);
	case1->savePayload(pay1);
	pay3 =  new Room();
	pay3->setRoomNumber(3);
	case1->savePayload(pay3);
	//puts("trying case 5");fflush(stdout);
	ans = case1->removeFromList(pay3);//ans should be equal to case1
	LLNode* theNext = (LLNode*) ans->next; //this is element where pay3 got attached
	Payload* check = (Payload*) 0;
	if (theNext)
	{
		check = theNext->payP; //this should be pay3, which should have been removed
	}
	//printf("testRemove returned from case 5\n"); fflush(stdout);
	if((ans != case1->getBegin1()) || (check != (Payload*)0))//disquiet
	{
		ok = false;

	}
	//printf("ans == case1 is %d\n", ans==case1);
	//printf("check != 0 is %d\n", check != (Payload*)0);
	printf("testRemove case 5 with %d\n", ok); fflush(stdout);
	//now case 6
	nbg = case1->makeEmptyLinkedList();
	case1->setBegin1(nbg);
	pay1 = new Room();
	pay1->setRoomNumber(1);
	case1->savePayload(pay1);
	case1->printHistory1();
	pay3 = new Room();
	pay3->setRoomNumber(3);
	case1->savePayload(pay3);
	Payload* another = new Room();
	another->setRoomNumber(2);

	case1->printHistory1();

	ans = case1->removeFromList(another);
	if((ans != case1->getBegin1()))
	{
		ok = false;

	}
	printf("testRemove case 6 with %d\n", ok); fflush(stdout);
	return ok;
}
bool Tests::testPrintHistory()
{
	bool ok = true;
	puts("starting testPrintHistory");
	return ok;
}

