/************************************************
 * Author: Andrew Derringer
 * Program: Insert/Merge Comparison
 * Last Edit: 10/6/2019
 * Description: Two methods of list sorting
************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
 * Description: Insert method of sorting a list
 * Param: Array address
 * Param: Size of passed array
 * Ret: Array reference rearranged in memory
 * Cite: Inspired by geeksforgeeks.org/insertion-sort/
*/
void insertSort(int inputArr[],int n) {
   int key, i, j;

   for(i = 1; i < n; i++) {
      key = inputArr[i];
      j = i - 1;

      while(j >= 0 && inputArr[j] > key){
         inputArr[j + 1] = inputArr[j];
         j--;
      }
      inputArr[j + 1] = key;
   }
}

/*
 * Description: Called only from within mergeSort. Rearranges only the portion
 * 		of an array that fits within its index points received.
 * Param: Array address
 * Param: Index locations of its left, mid, and right index
 * Ret: Array reference rearranged in memory
*/
void merge(int arr[], int leftIdx, int midIdx, int rightIdx) { 
   //determine lengths of left and right halves
   int nLeft = midIdx - leftIdx + 1; 
   int nRight =  rightIdx - midIdx; 
  
   int arrLeft[nLeft], arrRight[nRight]; 
  
   //build left and right temp arrays using sinze and passed indeces
   for (int n = 0; n < nLeft; n++) 
       arrLeft[n] = arr[leftIdx + n]; 
   for (int m = 0; m < nRight; m++) 
       arrRight[m] = arr[midIdx + 1+ m]; 
  
   //Combine each temp array lowest to highest order
   int i = 0; //Start index of arrLeft
   int j = 0; //Start index of arrRight
   int inputIdx = leftIdx; //Start index of full sized original array
   while (i < nLeft && j < nRight) 
   { 
       if (arrLeft[i] <= arrRight[j]) 
       { 
           arr[inputIdx] = arrLeft[i]; 
           i++; 
       } 
       else
       { 
           arr[inputIdx] = arrRight[j]; 
           j++; 
       } 
       inputIdx++; 
   } 
  
   //Copy any remaining elements of arrLeft
   while (i < nLeft) 
   { 
       arr[inputIdx] = arrLeft[i]; 
       i++; 
       inputIdx++; 
   } 
  
   //Copy any remaining elemenrs of arrRight
   while (j < nRight) 
   { 
       arr[inputIdx] = arrRight[j]; 
       j++; 
       inputIdx++; 
   }
} 

/*
 * Description: Recursively calls smaller sections of an array and
 * 		then calls merge to sort and recombine them.
 * Param: Array address
 * Param: Index locations of its left  and right index
 * Ret: Array reference rearrange in mem
 * Cite: Inspired by geeksforgeeks.org/merge-sort/
*/
void mergeSort(int inputArr[], int leftIdx, int rightIdx) {
   if(leftIdx < rightIdx) {
      int midIdx = (rightIdx + leftIdx) / 2;

      mergeSort(inputArr, leftIdx, midIdx);
      mergeSort(inputArr, midIdx + 1, rightIdx);

      merge(inputArr, leftIdx, midIdx, rightIdx);
   }
}
