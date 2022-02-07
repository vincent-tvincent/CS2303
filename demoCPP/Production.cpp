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
			puts("Didn't find any arguments.");
			fflush(stdout);
			answer = false;
		}
		else //there is interesting information
		{
			printf("Found %d interesting arguments.\n", argc-1);
			fflush(stdout);
			char filename[FILENAMELENGTHALLOWANCE];
			char* eptr=(char*)-1;
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
				case 2:
					//this is maximum number of rooms

					aL= strtol(argv[i], &eptr, 10);
					maxRooms = (int) aL;
					printf("Limit of rooms is %d\n",maxRooms);fflush(stdout);
					break;
				case 3:
					//this is maximum amount of treasure

					maxTreas = atof(argv[i]);
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
			int nrooms = -1;
			AdjMat* adjMP = new AdjMat(nrooms);
			//cannot, do not know nrooms init(adjMP);
			//puts("Back from init Adj Mat"); fflush(stdout);
			Room* theRoomPs[10];//addresses for 10 rooms

			puts("Before read file"); fflush(stdout);
			answer = readFile(filename, &nrooms, adjMP, theRoomPs); //read the file
			puts("Back from read file"); fflush(stdout);

			//we'll want to conduct the search
			//for the search we'll need an empty search history
			LinkedList* ll2 = new LinkedList();
			LLNode2* start2 = ll2->makeEmptyLinkedList2();
			ll2->setBegin2(start2);
			//we'll need the Queue, into which we put rooms, and remove rooms
			LinkedList* ll1 = new LinkedList();
			LLNode* start1 =ll1->makeEmptyLinkedList();
			ll1->setBegin1(start1);
			puts("starting search"); fflush(stdout);
			//we'll start searching with room 0
			bool done = false;
			int searchedRooms = 0;
			float foundTreasure = 0.0;
			Room* roomBeingSearchedP = theRoomPs[0];
			//we set its searched field to true, and take its treasure
			roomBeingSearchedP->setSearched(true);
			//we record it in the history
			SearchResults* srP = (SearchResults*) malloc(sizeof(SearchResults));
			srP->roomNumber= 0;
			srP->treasure = roomBeingSearchedP->getTreasure();
			puts("Checking limits with room 0"); fflush(stdout);
			if((srP->treasure <= maxTreas) && (maxRooms>0))
			{
				puts("Enqueuing room 0");fflush(stdout);
				ll2->savePayload2(srP);//here we are enqueueing room 0
				puts("Back from save"); fflush(stdout);
				foundTreasure = roomBeingSearchedP->getTreasure();
				searchedRooms = 1;
			}
			else
			{
				puts("Not enqueuing room 0, over a limit");fflush(stdout);
				done=true;
			}

			while(!done)
			{   //here we want to find all of the rooms adjacent to the roomBeingSearched,
				//so we look in the adj matrix
				for(int col = 0; (col<nrooms)&&!done; col++)
				{
					//we check whether this room is neighboring
					printf("checking rooms %d and %d.\n", roomBeingSearchedP->getRoomNumber(), col); fflush(stdout);
					if(adjMP->getEdge(roomBeingSearchedP->getRoomNumber(), col)==1)
					{
						puts("found an edge"); fflush(stdout);
						//if so, we check whether room has been searched
						if(!(theRoomPs[col]->getSearched()))
						{//if it hasn't been searched
							printf("Room %d hasn't already been searched.\n", col);
							//we set it to searched
							theRoomPs[col]->setSearched(true);
							if(((foundTreasure + theRoomPs[col]->getTreasure())<= maxTreasure)&&(searchedRooms < maxRooms))
								//we check whether we can take the treasure vs. limit
								//we check whether we've hit the room limit
							{//we enqueue it for search
								foundTreasure += theRoomPs[col]->getTreasure();
								searchedRooms++;
								printf("found treasure updated to %f.\n", foundTreasure);
								printf("searched rooms updated to %d.\n", searchedRooms);
								printf("enqueuing room %d.\n", col); fflush(stdout);
								printf("Before enqueuing queue empty reports %d\n", ll1->isEmpty());
								ll1->savePayload(theRoomPs[col]);
								srP = (SearchResults*) malloc(sizeof(SearchResults));
								srP->roomNumber=theRoomPs[col]->getRoomNumber();
								srP->treasure = theRoomPs[col]->getTreasure();
								ll2->savePayload2(srP);
								printf("After enqueuing, queue empty reports %d\n", ll1->isEmpty());
							}//check about search limits
						}//room can still be searched
					}//room is a neighbor

					if(foundTreasure >= maxTreasure)
					{
						done = true;
						printf("Done by treasure, with %f.\n", foundTreasure);
					}
					if (searchedRooms>=maxRooms)
					{
						done = true;
						printf("Done by rooms, with %d.\n", searchedRooms);
					}
				}//scan for all possible rooms to search from this room
				//time to get the next room
				if(ll1->isEmpty())
				{
					done=true;
					puts("Done by queue empty");
				}
				if(!done)
				{

					puts("Invoking  dequeue");fflush(stdout);
					roomBeingSearchedP = ll1->dequeueLIFO();
					printf("Treasure so far is %f.\n", foundTreasure);
					printf("Rooms so far is %d.\n", searchedRooms);

				}
			}//while search is not done
			//search is now done, time to print the history
			ll2->printHistory();


		}//end of else we have good arguments

	return answer;
}
bool Production::readFile(char* filename, int* nrooms, AdjMat* adjMP, Room** theRoomPs)
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

		float tempTreas = 2.9;
		for(int roomr = 0; roomr<*nrooms; roomr++)
		{
			fscanf(fp,"%f", &tempTreas);
			//make a room and set its treasure
			Room** aRoomP = theRoomPs;
			aRoomP = aRoomP+roomr;
			//*aRoomP = (Room*) malloc(sizeof(Room));
			*aRoomP = new Room();
			//now set the treasures
			(*aRoomP)->setTreasure(tempTreas);
			(*aRoomP)->setRoomNumber(roomr);
			printf("The treasure in room %d is %f\n", roomr, (*aRoomP)->getTreasure());
		}
		ok = true;
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
