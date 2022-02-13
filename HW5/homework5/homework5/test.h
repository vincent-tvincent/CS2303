#pragma once
#ifndef TEST
#define TEST
#define TEST_OBJECT = new matrix(5,5);
#define TEST_OBJECT2 = new readMatrix("testfile.txt");
#include "hw5main.h"
using namespace std;
void test();
bool testMatrix();
bool testMatrixSet();
bool testMatrixGetPointer();
bool testReadMatrix();

#endif

