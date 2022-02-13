#ifndef TM
#define TM
#include"matrix.h"
class testMatrix {
public:
	testMatrix();
	virtual ~testMatrix();
	bool test();
private:
	char* testOutputName;
	matrix* testObject;
	bool scanBoard(int*,int);
	bool testGetPointer();
	bool testSet();
	bool testPrintBoard();
};
#endif