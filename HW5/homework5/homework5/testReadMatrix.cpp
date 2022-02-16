#include "testReadMatrix.h"
testReadMatrix::testReadMatrix(char* testInput, char* testOutput) {
	inputFile = testInput;
	outputFile = testOutput;
}

bool testReadMatrix:: test() {
	cout << "start test readMatrix " << endl;
	bool ok = false;
	ok = testFillMatrix() && testFixMatrix() && testPrintMatrix();
	if (ok) {
		cout << "readMatrix pass the test" << endl;
	}
	else {
		cout << "readMatrix does not pass the test" << endl;
	}
	return ok; 
}

bool testReadMatrix testFillMatrix() {
	
}