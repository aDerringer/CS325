/************************************************
 * Author: Andrew Derringer
 * Program: Insert/Merge Comparison
 * Last Edit: 10/6/2019
 * Description: Useful utility functions including input validation
 * 		and print functions.
************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * Description: prints array of size n
 * Param: array and its size
 * Ret: None
*/
void printArr(int arr[], int n) {
   for(int i = 0; i < n; i ++) {
      if(i == n - 1) {
         printf("%d\n", arr[i]);
      } else {
         printf("%d, ", arr[i]);
      }
   }
}

void printArrKP(FILE* fileOut, int arr[], int n) {
   for(int i = 0; i < n; i ++) {
      if(arr[i] == 1) {
         fprintf(fileOut, "%d ", i);
      }
   }
   fprintf(fileOut, "\n");
 
}

/*
 * Description: performs getline() and determines if input was an
 * 		in of acceptable perameters. Returns it.
 * Param: string of input request and min and max input range.v
 * Ret: int of an acceptable input
*/
int intInput(char* statement, int min, int max) {
   printf(statement);
   printf("\n");

   char* inputString;
   size_t inputSize = 100;
   int inputInt = 0;
   bool isInt = false;

   inputString = (char*)malloc(sizeof(char) * inputSize);
   getline(&inputString, &inputSize, stdin);

   while(!isInt) {
      isInt = true;

      int i = 0;
      while(inputString[i] != 10) {
         if(inputString[i] >= 48 && inputString[i] <= 57) {
            inputInt *= 10;
            inputInt += (inputString[i] - 48);
         }
         else if(inputString[i] != 10) {
            inputString[i + 1] = 10;
            isInt = false;
         }
         i++;
      }

      if(!isInt) {
         printf("Invalid Input: Not an integer. Try again:\n");
         getline(&inputString, &inputSize, stdin);
         inputInt = 0;
      }

      if(isInt && (inputInt < min || inputInt > max)) {
         printf("Invalid Input: Out of Range. Try again:\n");
         getline(&inputString, &inputSize, stdin);
         isInt = false;
         inputInt = 0;
 
      }
   }

   return inputInt;
}
