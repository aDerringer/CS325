/************************************************
 * Author: Andrew Derringer
 * Program: Insert/Merge/Stooge Comparison
 * Last Edit: 10/13/2019
 * Description: Functions for reading arrays in and storing
 * 		arrays in files structured such that the
 * 		first int is the size followed by values of
 * 		the array.
************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/*
 * Description: Stores arrays in a file with each line
 * 		representing an array. First int is size
 * 		followed by numbers with a space.
 * Param: String for the file name to be openned
 * Param: array and its size
 * Ret: file created or appended with new array information
*/
void outputArr(char* fileName, int arr[], int size) {
   FILE *filePtr;
   filePtr = fopen(fileName,"a"); //set to append

   fprintf(filePtr,"%d ", size); //first output size of array to file
   for(int i = 0; i < size; i++) {
      if(i == size - 1) {
         fprintf(filePtr, "%d\n", arr[i]); //newline when array is done
      } else {
         fprintf(filePtr, "%d ", arr[i]);
      }
   }

   fclose(filePtr);
}

/*
 * Description: Reads from file and stores each line as an array
 * 		where the first int is size followed by values.
 * Param: String for the file name to be read from
 * Param: Sort type determines if list sorted by insert or merge
 * Ret: A file containing all arrays from openned file but sorted
*/
void arrFile(char* fileName, int sortType) {
   FILE *filePtr;
   filePtr = fopen(fileName,"r");
   if(filePtr == NULL) {
      printf("Invalid file\n");
      exit(0);
   }

   int i = -1; //first sucessful char at -1 is size then following added to index 0+
   int size, val;
   bool cont = false; //tracks if prev read char was int
   int *arr;
   char c = fgetc(filePtr);
   
   while (c != EOF) {

      //if first int after a non-int char then add to val and set cont
      if(c >= 48 && c <= 57 && cont == false) {
         val = c - 48;
         cont = true;
      }
      //if int preceded by int then push val one decimal and add to val
      else if(c >= 48 && c <= 57 && cont == true) {
         val *= 10;
         val += (c - 48);
      }
      //first space after first complete int read then initialize array of that size
      else if(c == 32 && i == -1) {
         size = val;
         //printf("size is %d\n", size);
         arr = (int *)malloc(sizeof(int) * size);
         cont = false;
         i++;
      }
      //if space or newline then previous int done and can add to array. reset values.
      else if((c == 32 || c == 10) && i >= 0) {
         //printf("value to add is %d\n", val);
         arr[i] = val;
         cont = false;
         i++;

         //if newline then array done. Sort and output
         if( c == 10) {
            if(sortType == 1) { // 1 = insert sort
               insertSort(arr, size);
               outputArr("insert.txt", arr, size);
            }
            else if(sortType == 2) { // 2 = merge sort
               mergeSort(arr, 0, size - 1);
               outputArr("merge.txt", arr, size);
            }
            else if(sortType == 3) { // 2 = stooge sort
               stoogeSort(arr, 0, size - 1);
               outputArr("stooge.txt", arr, size);
            }


            free(arr);
            arr = NULL;
            cont = false;
            i = -1;
         }
      }
      c = fgetc(filePtr);   
   }

   if(arr) {
      free(arr);
      arr = NULL;
   }
   fclose(filePtr);
   printf("File(s) read and write complete.\n");
}
