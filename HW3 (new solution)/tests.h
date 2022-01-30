/*
 * tests.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

bool tests();

bool testLoad();
bool testRandChoose();
bool testSwap();
bool testSelect();

void printBoard();
#endif /* TESTS_H_ */