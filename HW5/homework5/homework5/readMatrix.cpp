#include "readMatrix.h"

readMatrix::readMatrix(char** argv) {
	if (checkInput(argv)) {
		Matrix = new matrix((int)(argv[2]) - 48,(int)(argv[2]) - 48);
		fillMatrix(argv[1]);
	}
}

bool readMatrix::checkInput(char** argv) {
	bool vaild = true;
	for (int i = 1; i < 2; i++) 
	{
		switch (i)
		{
		case 1:
			//this is filename
			printf("The length of the filename is %d.\n", (int)strlen(argv[i]));
			printf("The proposed filename is %s.\n", argv[i]);
			if (strlen(argv[i]) >= FILENAMELENGTHALLOWANCE)
			{
				puts("Filename is too long.");
				fflush(stdout);
				vaild = false;
			}
			else
			{
				char* filename = argv[1];
				strcpy(filename, argv[i]);
				printf("Filename was %s.\n", filename);
				fflush(stdout);
			}
			break;
		case 2:
			//this is maximum number of elements

			char* ptr;
			printf("Limit of rooms is %d\n", strtol(argv[2],&ptr,10)); fflush(stdout);
			break;

		default:
			puts("Unexpected argument count."); fflush(stdout);
			vaild = false;
			break;
		}//end of switch
	}//end of for loop on argument count
	return vaild;
}

void readMatrix::fillMatrix(char* fileName) {
	FILE* target = fopen(fileName,"r");
	//set the end of the loop
	int endLength = -1;
	fscanf(target,"%d",endLength);
	//loop elements
	int maxRead = 0;
	int counter = 0;
	while (counter < maxRead && maxRead < endLength) {
		int readValue = -1;
		fscanf(target,"%d",readValue);
		Matrix->set(counter,maxRead,readValue);
		if (counter < maxRead) {//judge if go to next column
			counter++;//not go to next column
		}
		else {//go to next column
			counter = 0;
			maxRead++;
		}
	}
	fixMatrix(endLength);
}

void readMatrix::fixMatrix(int endLength) {
	//initialize the loop 
	int rowStart = 1;
	int row = rowStart;
	int col = 0;
	//start of the loop  
	while (row < endLength && col < endLength) {
		int* adjValue = Matrix->getPointer(col,row);
		Matrix->set(row, col, *adjValue);
		if (row < endLength) {//judge if go to next column
			row++;//not go to next column
		}
		else {//go to next column 
			Matrix->set(rowStart,col,0);// set the connection to itself to 0 
			//move to next column's start point
			rowStart++;
			row = rowStart;
			col++;
		}
	}
}
