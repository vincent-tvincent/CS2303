#include "testReadMatrix.h"
testReadMatrix::testReadMatrix() {
	inputFile = "test.txt";
	outputFile = "testout.txt";
	testLength = 5;
}

bool testReadMatrix:: test() {
	cout << "start test readMatrix " << endl;
	cout << "printMatrix() directly call the printBoard() function of matrix class, which is already tested,\nthus printMatrix will not be tested here." << endl;
	bool ok = false;
	ok = testFillMatrix() && testFixMatrix();
	if (ok) {
		cout << "readMatrix pass the test" << endl;
	}
	else {
		cout << "readMatrix does not pass the test" << endl;
	}
	return ok; 
}


bool testReadMatrix:: testFillMatrix() {
	int testMatrix[5][5] = {{0,1,0,1,0},
							{1,0,1,0,1},
							{0,1,0,1,0},
							{1,0,1,0,1},
							{0,1,0,1,0} };
	cout << "start testing fillMatrix()" << endl;
	bool ok = false;
	// fillMatrix() and fixMatrix() will be automatically call during constructing.
	readMatrix* testObject = new readMatrix(inputFile,outputFile); 
	matrix* result = &(testObject->getMatrix());
	int row = 0;
	int col = 0;
	int maxLength = 0;
	bool done = false;
	do{
		cout << "here" << endl;
		ok = *(result->getPointer(row, col)) == testMatrix[row][col];
		printf("testMatrix value: %d", testMatrix[row][col]);
		if (row < maxLength) {
			row++;
		}
		else {
			row = 0;
			col++;
			maxLength++;
		}
	} while (row < maxLength && maxLength < testLength && ok);
	
	if (ok) {
		cout << "fillMatrix() pass the test" << endl;
	}
	else {
		cout << "fillMatrix() doesn't pass the test" << endl;
	}
	return ok;
}

bool testReadMatrix::testFixMatrix() {
	cout << "start testing fixMatrix()" << endl;
	bool ok = false;
	// fillMatrix() and fixMatrix() will be automatically call during constructing.
	readMatrix* testObject = new readMatrix(inputFile,outputFile); 
	matrix* result = &(testObject->getMatrix());
	int row = 0;
	int col = 0;
	int maxLength = 0;

	bool done = false;
	do {
		ok = result->getPointer(row, col) == result->getPointer(col, row);
		if (row < maxLength) {
			row++;
		}
		else {
			row = 0;
			col++;
			maxLength++;
		}
	} while (row < maxLength && maxLength < testLength && ok);

	for (int i = 0; i < testLength && ok; i++) {
		ok = result->getPointer(i, i) == 0;
	}

	if (ok) {
		cout << "fixMatrix() pass the test" << endl;
	}
	else {
		cout << "fillMatrix() doesn't pass the test" << endl;
	}
	return ok;
}
