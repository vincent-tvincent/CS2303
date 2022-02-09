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
	bool ok5 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4 && ok5;
	return answer;
}
bool Tests::testReadFile()
{

	puts("starting testReadFile"); fflush(stdout);
	bool ok = false;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 6;

	AdjMat* adjMP = new AdjMat();
	Terminal* theStopPs[10];//addresses for 10 rooms

	Production* pP = new Production();
	ok = pP->readFile("subwayGraph.txt", &answer, adjMP, theStopPs); //read the file
	if(ok)
	{
		if(answer!=rightAnswer)
		{
			puts("test failed on number of stops");
		}
		else
		{
			puts("read file succeeded on number of stops");
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
	//printf("The pointer itself is %p.\n", nbg);
	//printf("The payload pointer is %p.\n",nbg->payP);
	//printf("The next pointer is %p.\n", nbg->next); fflush(stdout);
	LLNode* x = theListP->getBegin1();
	//printf("The pointer itself is %p.\n", x);
	//printf("The payload pointer is %p.\n",x->payP);
	//printf("The next pointer is %p.\n", x->next); fflush(stdout);
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

bool Tests::testPrintHistory()
{
	bool ok = true;
	puts("starting testPrintHistory");
	return ok;
}

