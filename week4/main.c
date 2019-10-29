/************************************************
 * Author: Andrew Derringer
 * Program: Greedy Scheduling
 * Last Edit: 10/23/2019
 * Description: Reads a file containing events with
 * 		start and end times and places these
 * 		values in an array. Sorts the events
 * 		by start time and outputs a schedule
 * 		of the most possible events to
 * 		complete without overlapping as
 * 		determined by greedy algorithm.
************************************************/
#include "utilities.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main () {

   FILE *filePtr;
   filePtr = fopen("act.txt","r");
   if(filePtr == NULL) {
      printf("Invalid file\n");
      exit(0);
   }

   // variable declarations for loop
   int arraySize, i;	//number of sched events used for array allocation etx
   int set = 1;		//set of events number printed every loop

   int* eventNum;	//event identification number from input file
   int* startTime;	//event start time from input file
   int* endTime;	//event end time from input file

   // Until EOF outer loop grabs first number which is the number of events
   // in that set. The inner loop goes through that list of events and 
   // assignes them to their respecrtive arrays.
   while (fscanf(filePtr, "%3d", &arraySize) != EOF) {
      //ararys are allocated long enough to print then free'd and reused
      eventNum = (int*)malloc(sizeof(int) * arraySize);
      startTime = (int*)malloc(sizeof(int) * arraySize);
      endTime = (int*)malloc(sizeof(int) * arraySize);

      // grab structured lines from file and place into arrays
      for (i = 0; i < arraySize; i++) {
         fscanf(filePtr, "%3d %3d %3d", &eventNum[i], &startTime[i], &endTime[i]);
      }

      // sort by start time and adjust other arrays to maintain cooresponding values
      modMergeSort(eventNum, startTime, endTime, 0, arraySize - 1);

      // prepare variables for loop  to create optomized schedule from events
      int* events = (int*)malloc(sizeof(int) * arraySize);	// save optimal events
      events[0] = eventNum[arraySize - 1];			// latest starting event always added
      int available = startTime[arraySize - 1];			// track latest unscheduled time
      int currIdx = 1;

      // Go through entire array of events backwards and the first event
      // with an end time within latest available time will be the latest
      // start time thanks to the sort and should be added to the final array.
      for (i = arraySize - 2; i >= 0; i--) {
         if (endTime[i] <= available) {
            events[currIdx] = eventNum[i];
            currIdx++;
            available = startTime[i];
         }
      }

      printf("Set %d\n", set);
      printf("Number of activities selected = %d\n", currIdx);
      printf("Activities: ");
      printArr(events, currIdx);
      printf("\n");

      set++;
      free(events);
      free(eventNum);
      free(startTime);
      free(endTime);
   }

   fclose(filePtr);

   return 0;

}
