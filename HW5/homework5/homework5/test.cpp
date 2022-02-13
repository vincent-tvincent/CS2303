#include "test.h"
void test() {
	cout << "start test" << endl; fflush(stdout);
	if (testMatrix() && testReadMatrix()) {
		cout << "test passed" << endl; fflush(stdout);
	}
	else {
		cout << "test did not pass" << endl;
	}
}

bool testMatrix() {
	return testMatrixSet() && testMatrixGetPointer();
}

bool testMatrixSet() {
}