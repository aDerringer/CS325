#include <stdio.h>
#include <stdlib.h>

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
void merge(int inputArr[], int leftIdx, int midIdx, int rightIdx) {
   int nLeft = midIdx - leftIdx + 1;
   int nRight = rightIdx - midIdx;

   int leftArr[nLeft], rightArr[nRight];

   for(int m = 0; m < nLeft; m++) {
      leftArr[m] = inputArr[leftIdx + m];
   }
   for(int n = 0; n < nRight; n++) {
      rightArr[n] = inputArr[midIdx + n + 1];
   }

   int j = 0;
   int k = 0;
   int inputIdx = leftIdx;
   while(j < nLeft && k < nRight) {
      if(leftArr[j] <= rightArr[k]) {
         inputArr[inputIdx] = leftArr[j];
         j++;
      } else {
         inputArr[inputIdx] = rightArr[k];
         k++;
      }
      inputIdx++;
   }

   while(j < nLeft) {
      inputArr[inputIdx] = leftArr[j];
      j++;
      inputArr++;
   }
   while(k < nRight) {
      inputArr[inputIdx] = leftArr[k];
      k++;
      inputArr++;
   }
}
*/



void merge(int arr[], int leftIdx, int midIdx, int rightIdx) { 
   int nLeft = midIdx - leftIdx + 1; 
   int nRight =  rightIdx - midIdx; 
  
   int arrLeft[nLeft], arrRight[nRight]; 
  
   for (int n = 0; n < nLeft; n++) 
       arrLeft[n] = arr[leftIdx + n]; 
   for (int m = 0; m < nRight; m++) 
       arrRight[m] = arr[midIdx + 1+ m]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
   int i = 0; // Initial index of first subarray 
   int j = 0; // Initial index of second subarray 
   int inputIdx = leftIdx; // Initial index of merged subarray 
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
  
    /* Copy the remaining elements of L[], if there 
 *        are any */
   while (i < nLeft) 
   { 
       arr[inputIdx] = arrLeft[i]; 
       i++; 
       inputIdx++; 
   } 
  
    /* Copy the remaining elements of R[], if there 
 *        are any */
   while (j < nRight) 
   { 
       arr[inputIdx] = arrRight[j]; 
       j++; 
       inputIdx++; 
   }
} 

void mergeSort(int inputArr[], int leftIdx, int rightIdx) {
   if(leftIdx < rightIdx) {
      int midIdx = (rightIdx + leftIdx) / 2;

      mergeSort(inputArr, leftIdx, midIdx);
      mergeSort(inputArr, midIdx + 1, rightIdx);

      merge(inputArr, leftIdx, midIdx, rightIdx);
   }
}
