#include "hw5main.h"
#include "testMatrix.h"
#pragma warning(disable: 4996)
int main(int argc, char* argv[]) {
	testMatrix* test1 = new testMatrix(5,5);
	test1->test();
}