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

	answer = ok1 && ok2;
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
	ChildNode* theChildrenPs[10];//addresses for 10 rooms

	Production* pP = new Production();
	ok = pP->readFile("houseGraph.txt", &answer, adjMP, theChildrenPs); //read the file
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


	return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
	bool ans = true;
	puts("starting testGotAdjacencyMatrix"); fflush(stdout);


	return ans;
}
