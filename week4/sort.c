/************************************************
 * Author: Andrew Derringer
 * Program: Greedy Scheduling
 * Last Edit: 10/23/2019
 * Description: Three methods of list sorting
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

/*
 * Description: Stooge method of sorting a list
 * Param: Array address
 * Param: Size of passed array
 * Ret: Array reference rearranged in memory
 * Cite: Inspired by geeksforgeeks.org/stooge-sort/
*/
void stoogeSort(int inputArr[], int lowIdx, int hiIdx) {
   if (lowIdx >= hiIdx) {
      return;
   }

   if (inputArr[lowIdx] > inputArr[hiIdx]) {
      int temp = inputArr[lowIdx];
      inputArr[lowIdx] = inputArr[hiIdx];
      inputArr[hiIdx] = temp;
   }

   if (hiIdx - lowIdx + 1 > 2) {
      int thirdIdx =( (hiIdx - lowIdx + 1 ) / 3 );

      stoogeSort(inputArr, lowIdx, hiIdx - thirdIdx);
      stoogeSort(inputArr, lowIdx + thirdIdx, hiIdx);
      stoogeSort(inputArr, lowIdx, hiIdx - thirdIdx);
   }

}

/*
 * Description: Called only from within mergeSort. Rearranges only the portion
 * 		of an array that fits within its index points received.
 * Param: Array addresses with associated values at cooresponding indeces
 * Param: Index locations of its left, mid, and right index
 * Ret: Array reference rearranged in memory
*/
void modMerge(int eventNum[], int startTime[], int endTime[], int leftIdx, int midIdx, int rightIdx) { 
   //determine lengths of left and right halves
   int nLeft = midIdx - leftIdx + 1; 
   int nRight =  rightIdx - midIdx; 
  
   int arrLeft[nLeft], arrRight[nRight], numLeft[nLeft], numRight[nRight], endLeft[nLeft], endRight[nRight]; 
  
   //build left and right temp arrays using size and passed indeces
   for (int n = 0; n < nLeft; n++) {
       arrLeft[n] = startTime[leftIdx + n];
       numLeft[n] = eventNum[leftIdx + n];
       endLeft[n] = endTime[leftIdx + n];
   }
   for (int m = 0; m < nRight; m++) {
       arrRight[m] = startTime[midIdx + 1 + m];
       numRight[m] = eventNum[midIdx + 1 + m];
       endRight[m] = endTime[midIdx + 1 + m];
   }

   //Combine each temp array lowest to highest order
   int i = 0; //Start index of arrLeft
   int j = 0; //Start index of arrRight
   int inputIdx = leftIdx; //Start index of full sized original array
   while (i < nLeft && j < nRight) 
   { 
       if (arrLeft[i] <= arrRight[j]) 
       { 
           startTime[inputIdx] = arrLeft[i];
           eventNum[inputIdx] = numLeft[i];
           endTime[inputIdx] = endLeft[i];
           i++; 
       } 
       else
       { 
           startTime[inputIdx] = arrRight[j];
           eventNum[inputIdx] = numRight[j];
           endTime[inputIdx] = endRight[j];
           j++; 
       } 
       inputIdx++; 
   } 
  
   //Copy any remaining elements of arrLeft
   while (i < nLeft) 
   { 
       startTime[inputIdx] = arrLeft[i];
       eventNum[inputIdx] = numLeft[i];
       endTime[inputIdx] = endLeft[i];
       i++; 
       inputIdx++; 
   } 
  
   //Copy any remaining elemenrs of arrRight
   while (j < nRight) 
   { 
       startTime[inputIdx] = arrRight[j];
       eventNum[inputIdx] = numRight[j];
       endTime[inputIdx] = endRight[j];
       j++; 
       inputIdx++; 
   }
}
 

/*
 * Description: Recursively calls smaller sections of an array and
 * 		then calls merge to sort and recombine them.
 * Param: Array addresses with associated values at cooresponding indeces
 * Param: Index locations of its left  and right index
 * Ret: Array reference rearrange in mem
 * Cite: Inspired by geeksforgeeks.org/merge-sort/
*/
void modMergeSort(int eventNum[], int startTime[], int endTime[], int leftIdx, int rightIdx) {
   if(leftIdx < rightIdx) {
      int midIdx = (rightIdx + leftIdx) / 2;

      modMergeSort(eventNum, startTime, endTime, leftIdx, midIdx);
      modMergeSort(eventNum, startTime, endTime, midIdx + 1, rightIdx);

      modMerge(eventNum, startTime, endTime, leftIdx, midIdx, rightIdx);
   }
}

