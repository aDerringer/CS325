/************************************************
 * Author: Andrew Derringer
 * Program: Knapsack algorithm
 * Last Edit: 10/22/2019
 * Description: Use of arrays for price and weight of items
 * 		desired weight to optimize and total items.
 * 		Then returns an array of the size used.
************************************************/
#include "knapsack.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
   return (a > b)? a : b;
}



/*
 * Description: Dynamic program to find the most optimized list
 * 		of items for highest value given a constraint of
 * 		some carring weight,
 * Param: weight - maximum weight for total items used
 * Param: wt - array of item weights.
 * Param: val - array of item values.
 * Param: itemCount - length of item arrays
 * Ret: array of count of items used.
 * Citation: Inspired by https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/
int* knapSack(int weight, int wt[], int val[], int itemCount) { 
   int item, w; 
   int K[itemCount+1][weight+1]; 
  

   //Loop through every possible weight to find optimized value for weight
   for (item = 0; item <= itemCount; item++) { 
      //Inner loop restricts observable items to attempt variety of combinations.
      for (w = 0; w <= weight; w++) {
         //If no items or no weight then no value present.
         if (item == 0 || w == 0) {
            K[item][w] = 0;
         }
         //If current observed weight within constraint then compare optomized results between
         //using this item and optomizing remaining weigh or the previous best method at this
         //weight without this item.
         else if (wt[item - 1] <= w) {
            K[item][w] = max(val[item - 1] + K[item - 1][w-wt[item -1 ]],  K[item - 1][w]); 
         }
         else {
            K[item][w] = K[item - 1 ][w];
         }
      } 
   } 
                                                                               
   int totalMax = K[itemCount][weight];
   int remainingWeight = weight;
   int itemsUsed[itemCount];
   for (item = 0; item < itemCount; item++) {
      itemsUsed[item] = 0;
   }

   //Loop back tracks to find items used while total weight and items greater than zero
   for (item = itemCount; item > 0 && totalMax > 0; item--) { 
          
      // slide left to find first item addition that caused the current optimization
      // then tally that item and subtract its weight and value to find next item.
      if (totalMax != K[item - 1][remainingWeight]) {
         itemsUsed[item]++;                                                                                

         totalMax -= val[item - 1]; 
         remainingWeight -= wt[item - 1]; 
      }
   }
   printf("\n");

   //return K[n][W];
   return itemsUsed;
}
