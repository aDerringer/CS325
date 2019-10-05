#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

void outputArr(char* fileName, int arr[], int size) {
   FILE *filePtr;
   filePtr = fopen(fileName,"a");

   fprintf(filePtr,"%d ", size);
   for(int i = 0; i < size; i++) {
      if(i == size - 1) {
         fprintf(filePtr, "%d\n", arr[i]); 
      } else {
         fprintf(filePtr, "%d ", arr[i]);
      }
   }

   fclose(filePtr);
}

void arrFile(char* fileName, int sortType) {
   FILE *filePtr;
   filePtr = fopen(fileName,"r");
   if(filePtr == NULL) {
      printf("Invalid file\n");
      exit(0);
   }

   int i = -1;
   int size, val;
   bool cont = false;
   int *arr;
   char c = fgetc(filePtr);
   
   while (c != EOF) {

      if(c >= 48 && c <= 57 && cont == false) {
         val = c - 48;
         cont = true;
      }
      else if(c >= 48 && c <= 57 && cont == true) {
         val *= 10;
         val += (c - 48);
      }
      else if(c == 32 && i == -1) {
         size = val;
         //printf("size is %d\n", size);
         arr = (int *)malloc(sizeof(int) * size);
         cont = false;
         i++;
      }
      else if((c == 32 || c == 10) && i >= 0) {
         //printf("value to add is %d\n", val);
         arr[i] = val;
         cont = false;
         i++;

         if( c == 10) {
            //printf("Starting Array:\n");
            //printArr(arr, size);
            if(sortType == 1) { // 1 = insert sort
               //printf("Insert Sorted Array:\n");
               insertSort(arr, size);
               //printArr(arr, size);
               outputArr("insert.txt", arr, size);
            }
            else if(sortType == 2) { // 2 = merge sort
               //printf("Merge Sorted Array:\n");
               mergeSort(arr, 0, size - 1);
               //printArr(arr, size);
               outputArr("merge.txt", arr, size);
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
