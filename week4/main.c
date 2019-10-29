/************************************************
 * Author: Andrew Derringer
 * Program: Knap Sack Algorithm
 * Last Edit: 10/22/2019
 * Description: Finds optimal value of items to claim
 * 		given a constraint of total carrying
 * 		capacity for a group of individuals.
************************************************/
#include "utilities.h"
//#include "sort.h"
//#include "fileio.h"
//#include "knapsack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

   FILE *filePtr;
   filePtr = fopen("shopping.txt","r");
   if(filePtr == NULL) {
      printf("Invalid file\n");
      exit(0);
   }
   FILE *fileOut;
   fileOut = fopen("results.txt","w");

   int arraySize, i;
   int* eventNum;
   int* startTime;
   int* endTime;

   while (fscanf(filePtr, "%2d", &arraySize) != EOF) {
      eventNum = (int*)malloc(sizeof(int) * arraySize);
      startTime = (int*)malloc(sizeof(int) * arraySize);
      endTime = (int*)malloc(sizeof(int) * arraySize);

      for (i = 0; i < arraySize; i++) {
         fscanf(filePtr, "%2d %2d %2d", eventNum[i], startTime[i], endTime[i]);
      }

      printf("eventNum:\n");
      printArr(eventNum);
      printf("startTime:\n");
      printArr(startTime);
      printf("endTime:\n");
      printArr(endTime);

      free(eventNum);
      free(startTime);
      free(endTime);
   }
   /*
   int trials, i, itemCount, j, famSize, k;

   //while (fscanf(filePtr, "%50[^\n]\n", buffer) != EOF) {
      
   //}

   fscanf(filePtr, "%2d", &trials);
   //printf("Trials: %d\n", trials);

   for (i = 0; i < trials; i++) {

      fscanf(filePtr, "%2d", &itemCount);
      int prices[itemCount];
      int weight[itemCount];
      for (j = 0; j < itemCount; j++) {
         fscanf(filePtr, "%2d %2d", &prices[j], &weight[j]);
      }

      fscanf(filePtr, "%2d", &famSize);
      int famCapacity[famSize];
      //int famMax[famSize];
      int totalMax = 0;

      fprintf(fileOut, "Test Case %d\n", i + 1);
      //printf("Total Price %d\n", totalMax);
      //streampos jumpBack = fileOut.tellg();
      fprintf(fileOut, "Member Items\n");

      for (k = 0; k < famSize; k++) {
         fscanf(filePtr, "%2d", &famCapacity[k]);
         int* itemsUsed = knapSack(famCapacity[k], weight, prices, itemCount);
         //famMax[k] = famChart[itemCount][(famCapacity[k])];
         fprintf(fileOut, "\t%d: ", k + 1);
         printArrKP(fileOut, itemsUsed, itemCount);
         //famMax[k] = knapSack(famCapacity[k], weight, prices, itemCount);
         //totalMax += famMax[k];
         
         for (j = 0; j < itemCount; j++) {
            if (itemsUsed[j] == 1) {
               totalMax += prices[j];
            }
         }

         if (k == famSize -1) {
            //fprintf(fileOut, "\n");
         }

      }
      //streampos jumpForward = fileOut.tellg();
      //fileOut.seekg(jumpBack);
      fprintf(fileOut, "Total Price %d\n\n", totalMax);
      //fileOut.seekg(jumpForward);

   }


   //printf("trials = %d\n", trials);
   */

   fclose(fileOut);
   fclose(filePtr);

   return 0;

}
