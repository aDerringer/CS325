/************************************************
 * Author: Andrew Derringer
 * Program: Greedy Scheduling
 * Last Edit: 10/23/2019
 * Description: Three methods of list sorting
************************************************/
#ifndef SORT_H
#define SORT_H

//#include <stdio.h>
//#include <stdlib.h>

void insertSort(int*, int);
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
void modMerge(int*, int*, int*, int, int, int);
void modMergeSort(int*, int*, int*, int, int);
void stoogeSort(int*, int, int);
 
#endif
