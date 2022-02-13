#include "testMatrix.h"
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

bool testMatrix::testSet() {
	cout << "start test set()" << endl;	
	bool ok = false;
	for (int col = 0; col < 5; col++) {
		for (int row = 0; row < 5; row++) {
			testObject->set(row,col,1);
		}
	}

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

bool testMatrix::testGetPointer() {
	cout << "start testing getPointer()" << endl;
	bool ok = false;
	int row = rand() % 5;
	printf("	test row is: %d",row);
	int col = rand() % 5;
	printf("	test col is: %d",col);
	
	testObject->set(row,col,0);
	ok = *testObject->getPointer(row,col) == 0;
	if (ok) {
		cout << "getPointer() pass the test" << endl;
	}
	else {
		cout << "getPointer() doesn't pass the test" << endl;
	}
	return ok;
}

bool testPrintBoard() {
	
}




