//============================================================================
// Name        : demoCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Tests.h"
#include "Production.h"

int main(int argc, char* argv[]) {
	cout << "!!!Hello CS2303 students!!!" << endl; // prints !!!Hello World!!!
	Tests* tsP = new Tests();
	if(tsP->tests())
	{
		Production* pP = new Production();
		pP->prod(argc, argv);
		delete pP;
	}
	delete tsP;


	return 0;
}
