/*
 * Tests.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdio.h>
#include "Production.h"
//#include "LinkedList.h"


class Tests {
public:
	Tests();//constructor
	virtual ~Tests();
	bool tests();

private:
	bool testReadFile();
	bool testGotAdjacencyMatrix();
	bool testMakeLList();
	bool testLinkedList();
	bool testEnqueue();
	bool testRemoveFromList();
	bool testPrintHistory();

};
#endif /* TESTS_H_ */
