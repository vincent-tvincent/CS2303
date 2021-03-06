/*
 * Production.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "AdjMat.h"
//#include "Room.h"
#include "Terminal.h"
#include "LinkedList.h"

#include <stdio.h>
#define FILENAMELENGTHALLOWANCE (50)

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool readFile(char* filename, int* nNodes, AdjMat* adjMP, Terminal** theStopPs);

private:
	void showMax();

};

#endif /* PRODUCTION_H_ */
