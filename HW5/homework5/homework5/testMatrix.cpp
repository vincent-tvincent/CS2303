#include "testMatrix.h"
#pragma warning(disable: 4996)
testMatrix::testMatrix() {
	testOutputName = "testOutput.txt";
	testObject = new matrix(5,5);
}
testMatrix::~testMatrix() {
}

bool testMatrix::test() {
	cout << "start test Matrix" <<endl;
	bool ok = testGetPointer() && testSet() && testPrintBoard();
	if (ok) {
		cout << "Matrix pass the test" << endl;
	}
	else {
		cout << "Matrix doesn't pass the test" << endl;
	}
	return ok; 
}

bool testMatrix::testGetPointer() {
	cout << "start testing getPointer()" << endl;
	bool ok = false;
	int row = rand() % 5;
	printf("	test row is: %d\n", row);
	int col = rand() % 5;
	printf("	test col is: %d\n", col);
	int expect = row + col * 5;
	testObject->initForTest();
	
	ok = *testObject->getPointer(row, col) == expect;
	if (ok) {
		cout << "getPointer() pass the test" << endl;
	}
	else {
		cout << "getPointer() doesn't pass the test" << endl;
	}
	return ok;
}

bool testMatrix::testSet() {
	cout << "start test set()" << endl;	
	bool ok = false;
	for (int col = 0; col < 5; col++) {
		for (int row = 0; row < 5; row++) {
			testObject->set(row,col,1);
		}
	}
	testObject->onlyPrintBoard();
	int* thisBoard = testObject->getBoard();
	ok = scanBoard(thisBoard,1);

	if(ok){
		cout << "set() pass the test" << endl;
	}
	else {
		cout << "set() doesn't pass the test" << endl;
	}
	return ok;
}

bool testMatrix::scanBoard(int* board,int testValue) {
	bool ok = true;
	for (int i = 0; i < 25; i++) {
		if (*board != testValue) {
			ok = !ok;
			break;
		}
	}
	return ok;
}

bool testMatrix:: testPrintBoard() {
	cout << "start testing printBoard()" << endl;
	bool ok = false;
	testObject->printBoard(testOutputName);
	int* reference = testObject->getBoard();
	FILE* readBackFile = fopen(testOutputName,"r");
	int readBack = -1;
	for (int i = 0; i < 25;  i++) {
		fscanf(readBackFile,"%d",readBack);
		ok = readBack == *(reference + i);
		if (!ok) break;
	}

	if (ok) {
		cout << "printBoard() pass the test" << endl;
	}
	else {
		cout << "printBoard() doesn't pass the test" << endl;
	}

	return ok;
}




