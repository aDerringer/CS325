/************************************************
 * Author: Andrew Derringer
 * Program: Insert/Merge Comparison
 * Last Edit: 10/6/2019
 * Description: Reads and outputs sorted arrays by input and merge method.
 * 		Offers to perform analysis of 10 different sized arrays
 * 		using both methods.
************************************************/
#include "utilities.h"
#include "sort.h"
#include "fileio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
   mergeSort(arr, 0, size -1);
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

   //printf("Files output to merge.txt and insert.txt...\n");
   printf("Would you like to run a sort time analysis? (This may take several minutes):\n");
   int num = intInput("1)Yes\n2)No", 1, 2);
   
   if(num == 1) {
      //printf("N = 1000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(1000), mergeTime(1000));
      //printf("N = 5000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(5000), mergeTime(5000));
      //printf("N = 10000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(10000), mergeTime(10000));
      //printf("N = 15000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(15000), mergeTime(15000));
      printf("N = 20000     Insert = %6.3lf   Merge = %6.3lf\n", insertTime(20000), mergeTime(50000));
      //printf("N = 25000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(25000), mergeTime(25000));
      //printf("N = 30000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(30000), mergeTime(30000));
      //printf("N = 35000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(35000), mergeTime(35000));
      printf("N = 40000     Insert = %6.3lf   Merge = %6.3lf\n", insertTime(40000), mergeTime(100000));
      //printf("N = 50000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(50000), mergeTime(50000));
      printf("N = 60000     Insert = %6.3lf   Merge = %6.3lf\n", insertTime(60000), mergeTime(200000));
      printf("N = 80000     Insert = %6.3lf   Merge = %6.3lf\n", insertTime(80000), mergeTime(300000));
      printf("N = 100000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(100000), mergeTime(400000));
      printf("N = 120000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(120000), mergeTime(500000));
      printf("N = 160000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(160000), mergeTime(600000));
      printf("N = 200000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(200000), mergeTime(700000));
      printf("N = 230000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(250000), mergeTime(800000));
      printf("N = 350000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(350000), mergeTime(900000));
      //printf("N = 600000    Insert = %6.3lf   Merge = %6.3lf\n", insertTime(600000), mergeTime(600000));
      //printf("N = 1000000   Insert = %6.3lf   Merge = %6.3lf\n", insertTime(1000000), mergeTime(1000000));
   }

   printf("Program End...\n");
   
   return 0;
}
