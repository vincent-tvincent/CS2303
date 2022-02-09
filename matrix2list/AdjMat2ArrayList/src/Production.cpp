/*
 * Production.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Production.h"

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;
	showMax();
	if(argc <=1) //no interesting information
	{
		puts("Usage: Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char filename2[FILENAMELENGTHALLOWANCE];

		long aL=-1L;
		int maxRooms;
		int maxTreasure;
		double maxTreas;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are NR, NC, gens, filename, print and pause
			//because pause is optional, argc could be 6 or 7
			//because print is optional (if print is not present, neither is pause) argc could be 5
			switch(i)
			{
			case 1:
				//this is filename
				printf("The length of the filename is %d.\n",(int)strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 4:
				//this is filename
				printf("The length of the filename is %d.\n",(int)strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename2, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 2:
				//this is maximum number of rooms

				aL= strtol(argv[i], NULL, 10);
				maxRooms = (int) aL;
				printf("Limit of rooms is %d\n",maxRooms);fflush(stdout);
				break;
			case 3:
				//this is maximum amount of treasure

				maxTreas = strtod(argv[i], NULL);
				printf("Limit of  treasure is %f\n",maxTreas);fflush(stdout);
				maxTreasure = (float) maxTreas;
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);
		//we'll want to read the file
		int nrows = -1;
		AdjMat* adjMP = new AdjMat(nrows);
		//cannot, do not know nrooms init(adjMP);
		//puts("Back from init Adj Mat"); fflush(stdout);
		ChildNode* theChildrenPs[10];//addresses for 10 rooms

		puts("Before read file"); fflush(stdout);
		answer = readFile(filename, &nrows, adjMP, theChildrenPs); //read the file
		puts("Back from read file"); fflush(stdout);


		for(int row = 0; row<nrows; row++)
		{
			//make a new instance of childNode
			theChildrenPs[row] = new ChildNode;
			theChildrenPs[row]->setNodeNumber(row);
		}
		puts("made nodes"); fflush(stdout);
		for(int row = 0; row<nrows; row++)
		{
			printf("Working on node %d.\n", row);
			for(int col = 0; col<nrows;col++)
			{
				if (adjMP->getEdge(row, col))
				{
					printf("Found child %d.\n", col); fflush(stdout);
					//then the col node is a child of the row node
					(theChildrenPs[row])->addChild(theChildrenPs[col]);
				}
			}
		}
		puts("added children to nodes"); fflush(stdout);
		for(int node = 0; node<nrows; node++)
		{
			theChildrenPs[node]->printYourChildren();
		}

	}//end of else we have good arguments

	return answer;
}
bool Production::readFile(char* filename, int* nrooms, AdjMat* adjMP, ChildNode** theChildrenPs)
{
	bool ok = true;
	//the file tells how many rooms there are
	FILE* fp = fopen(filename, "r"); //read the file

	if (fp == NULL)
	{
		puts("Error! opening file");
		ok = false;
	}
	else
	{
		fscanf(fp,"%d", nrooms);
		adjMP->setN(*nrooms);
		int howManyRooms = *nrooms;
		//printf("setting edges to hold matrix for %d rooms.\n", howManyRooms);
		adjMP->setEdgesP((int*) malloc(howManyRooms * howManyRooms *sizeof(int)));
		//printf("The malloc for edges returned %p.\n", adjMP);
		//puts("Before init Adj Mat"); fflush(stdout);
		adjMP->init();
		int temp = -1;
		for(int roomr = 1; roomr<*nrooms; roomr++)
		{
			printf("on row %d\n", roomr);fflush(stdout);
			for(int roomc = 0; roomc<roomr; roomc++)
			{
				fscanf(fp,"%d", &temp);
				printf("in column %d, read %d\n", roomc, temp);fflush(stdout);
				//now set the value in the adjacency matrix
				if(temp==1)
				{
					adjMP->setEdge(roomr, roomc);
				}
				//puts("Back from setting any edge."); fflush(stdout);


			}
		}


	}
	fclose(fp);

	//the file contains a triangular array of integers, that are either 1 or 0


	return ok;
}

void Production::showMax()
{
	typedef enum{
		left1,
		right1
	}Dir;
	Dir turn = right1;
	if (turn == left1)
	{
		turn = right1;
	}
	else
	{
		turn = left1;
	}

}
