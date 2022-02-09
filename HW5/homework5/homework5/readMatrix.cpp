#include "readMatrix.h"

readMatrix::readMatrix(char** argv) {
	if (checkInput(argv)) {
		Matrix = new matrix((int)(argv[2]) - 48,(int)(argv[2]) - 48);
		fillMatrix(argv[1]);
		fixMatrix();
	}
}

bool readMatrix::checkInput(char** argv) {
	bool vaild = true;
	for (int i = 1; i < 2; i++) //don't want to read argv[0]
	{//argv[i] is a string
		//in this program our arguments are NR, NC, gens, filename, print and pause
		//because pause is optional, argc could be 6 or 7
		//because print is optional (if print is not present, neither is pause) argc could be 5
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