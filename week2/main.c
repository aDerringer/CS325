/************************************************
 * Author: Andrew Derringer
 * Program: Insert/Merge/Stooge Comparison
 * Last Edit: 10/13/2019
 * Description: Reads and outputs sorted arrays by insert, merge, and stooge method.
 * 		Offers to perform analysis of 10 different sized arrays
 * 		using all three methods.
************************************************/
#include "utilities.h"
#include "sort.h"
#include "fileio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Creats a rndomized array of size in and sorts it.
//ret: time it took to sort
double stoogeTime(int size) {
   int arr[size];
   clock_t start, end;

   for(int i = 0; i < size; i++) {
      arr[i] = rand();
   }
   //printArr(arr, size);

   start = clock();
   stoogeSort(arr, 0, size - 1);
   end = clock();

   return ((double) (end - start)) / CLOCKS_PER_SEC;
}


//Creats a rndomized array of size in and sorts it.
//ret: time it took to sort
double mergeTime(int size) {
   int arr[size];
   clock_t start, end;

   for(int i = 0; i < size; i++) {
      arr[i] = rand();
   }
   //printArr(arr, size);

   start = clock();
   mergeSort(arr, 0, size -1 );
   end = clock();

   return ((double) (end - start)) / CLOCKS_PER_SEC;
}

//Creats a rndomized array of size in and sorts it.
//ret: time it took to sort
double insertTime(int size) {
   int arr[size];
   clock_t start, end;

   for(int i = 0; i < size; i++) {
      arr[i] = rand();
   }
   //printArr(arr, size);

   start = clock();
   insertSort(arr, size);
   end = clock();

   return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main () {
   srand(0);

   char *fileName = "data.txt";
   arrFile(fileName, 1);
   arrFile(fileName, 2);
   arrFile(fileName, 3);

   //printf("Files output to merge.txt and insert.txt...\n");
   printf("Would you like to run a sort time analysis? (This may take several minutes):\n");
   int num = intInput("1)Yes\n2)No", 1, 2);
   
   if(num == 1) {
      int insertSizes[10] = {20000, 40000, 60000, 80000, 100000, 120000, 160000, 200000, 250000, 350000};
      int mergeSizes[10] = {50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000};
      int stoogeSizes[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

      for(int i = 0; i < 10; i++) {
         printf("N = %8d Insert = %6.5f\n", insertSizes[i], insertTime(insertSizes[i]));
         printf("N = %8d Merge = %6.5f\n", mergeSizes[i], mergeTime(mergeSizes[i]));
         printf("N = %8d Stooge = %6.5f\n", stoogeSizes[i], stoogeTime(stoogeSizes[i]));
         if (i != 9) {
            printf("\n");
         }
      }
   }

   printf("Program End...\n");
   
   return 0;
}
