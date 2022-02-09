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


		int start;
		int endingnode;

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
				//this is starting node
				start= (int)strtol(argv[i], NULL, 10);
				break;
			case 3:
				//this is ending node
				endingnode = (int)strtol(argv[i], NULL,10);
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);
		//we'll want to read the file
		int nNodes = -1;
		AdjMat* adjMP = new AdjMat(nNodes);
		//cannot, do not know nrooms init(adjMP);
		//puts("Back from init Adj Mat"); fflush(stdout);
		Terminal* theStopPs[10];//addresses for 10 rooms

		puts("Before read file"); fflush(stdout);
		answer = readFile(filename, &nNodes, adjMP, theStopPs); //read the file
		puts("Back from read file"); fflush(stdout);
        printf("Found %d nodes.\n", nNodes);
		//we'll want to conduct the search
		//for the search we'll need an empty search history
		LinkedList* ll = new LinkedList();

		puts("starting search"); fflush(stdout);

		bool done = false;

		Terminal* nodeBeingSearchedP = theStopPs[0];
		bool found = false;
		for(int node = 0; node<nNodes &&(!found); node++)
		{
			//printf("Node = %d\n", node); fflush(stdout);
			//printf("Node has number %d.\n", theStopPs[node]->getNodeNumber()); fflush(stdout);
			if(theStopPs[node]->getNodeNumber() == start)
			{
				found = true;
				nodeBeingSearchedP = theStopPs[node];
			}
		}
		//printf("Found starting terminal"); fflush(stdout);
		//we set its searched field to true, and take its treasure
		nodeBeingSearchedP->setVisited(true);

		printf("Enqueuing start node, starting with %d.\n", nodeBeingSearchedP->getNodeNumber());fflush(stdout);
		ll->savePayload(nodeBeingSearchedP);

		while(!done)
		{   //here we want to find all of the rooms adjacent to the roomBeingSearched,
			//so we look in the adj matrix
			for(int col = 0; (col<nNodes)&&!done; col++)
			{
				//we check whether this node is neighboring
				printf("Checking node %d with %d\n.", col, nodeBeingSearchedP->getNodeNumber()); fflush(stdout);
				if(adjMP->getEdge(nodeBeingSearchedP->getNodeNumber(), col)==1)
				{
					puts("found an edge"); fflush(stdout);
					//if so, we check whether room has been searched
					if(!(theStopPs[col]->getVisited()))
					{//if it hasn't been searched
						printf("Node %d hasn't already been searched.\n", col);
						//we set it to searched
						theStopPs[col]->setVisited(true);
						//we enqueue it for search
						printf("enqueuing node %d.\n", col); fflush(stdout);
						ll->savePayload(theStopPs[col]);//this is  where the node is enqueued for search

					}//node can still be searched
				}//node is a neighbor
			}//scan for all possible nodes to search from this room
			//time to get the next node
			if(ll->isEmpty())
			{
				done=true;
				puts("Done by queue empty");
			}
			if(!done)
			{

				puts("Invoking  dequeue");fflush(stdout);
				nodeBeingSearchedP = ll->dequeueLIFO();  //here is where the next room is obtained
				printf("Next node for search is %d.\n", nodeBeingSearchedP->getNodeNumber());
				if(nodeBeingSearchedP->getNodeNumber() == endingnode)
				{
					puts("Found the ending stop. Done with success.");
					done = true;
				}
			}
		}//while search is not done
		//search is now done, time to print the history



	}//end of else we have good arguments

	return answer;
}
bool Production::readFile(char* filename, int* nNodes, AdjMat* adjMP, Terminal** theStopPs)
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
		fscanf(fp,"%d", nNodes);
		int howManyNodes = *nNodes;
		adjMP->setN(howManyNodes);

		//printf("setting edges to hold matrix for %d rooms.\n", howManyRooms);
		adjMP->setEdgesP((int*) malloc(howManyNodes * howManyNodes *sizeof(int)));
		//printf("The malloc for edges returned %p.\n", adjMP);
		//puts("Before init Adj Mat"); fflush(stdout);
		adjMP->init();
		int temp = -1;
		theStopPs[0] = new Terminal();
		theStopPs[0]->setNodeNumber(0);
		for(int roomr = 1; roomr<howManyNodes; roomr++)
		{
			printf("on row %d\n", roomr);fflush(stdout);
			theStopPs[roomr] = new Terminal();
			theStopPs[roomr]->setNodeNumber(roomr);
			//printf("The new terminal is at %p.\n", theStopPs[roomr]); fflush(stdout);
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


