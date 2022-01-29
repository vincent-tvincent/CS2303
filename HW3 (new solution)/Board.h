/*
 * Board.h
 *
 *  Created on: Nov 9, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdbool.h>
#include <stdlib.h>
typedef struct{
    int row;
    int col;

}pair;

void load(int* theBoard, int nrows, int ncols);
pair* randChoose(int row, int col);
void swap(int* theBoard, int nrows, int ncols,int row,int col);
int select(int* theBoard,int nRow,int nCol);

#endif /* BOARD_H_ */
