#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printArr(int arr[], int n) {
   for(int i = 0; i < n; i ++) {
      if(i == n - 1) {
         printf("%d\n", arr[i]);
      } else {
         printf("%d, ", arr[i]);
      }
   }
}

int intInput(char* statement, int min, int max) {
   printf(statement);
   printf("\n");

   char* inputString;
   size_t inputSize = 100;
   int inputInt = 0;
   bool isInt = false;

   inputString = (char*)malloc(sizeof(char) * inputSize);
   getline(&inputString, &inputSize, stdin);

   //printf("You entered %s.\n", inputString);

   while(!isInt) {
      isInt = true;

      int i = 0;
      while(inputString[i] != 10) {
      //for(int i = 0; i < inputSize; i++) {
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
