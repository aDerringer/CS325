# Program: Bin Packing Algorithms
# Author: Andrew Derringer
# Last Modified: 12/4/2019
# Summary: Grabs integer input from formatted text file
# 	and performs first_fit, first_fit_dec, and bes_fit
#	bin packing algorithms while tracking time to
#	completion.


import sys
import time

def first_fit(arr, cap):
   binSet = []
   binSet.append(cap)

   for i in arr:
      j = 0
      done = False
      while j < len(binSet) and done == False:
         if i <= binSet[j]:
            binSet[j] -= i
            done = True
         elif j == len(binSet) - 1:
            binSet.append(cap)
         j += 1

   return(len(binSet))


def best_fit(arr, cap):
   binSet = []
   binSet.append(cap) # start with at least one bin

   for i in arr:
      j = 0
      done = False
      while j < len(binSet) and done == False: # using while loop for easy append
         if i <= binSet[j]:
            binSet[j] -= i
            done = True
         elif j == len(binSet) - 1:
            binSet.append(cap)
         j += 1

      binSet.sort() # sorting at end in place of running through entire list every iter

   return(len(binSet))


def main ():
   binFile = open(sys.argv[1], "r")
 
   # get number of cases
   cases = int(binFile.readline())

   # loop through file accrding to number of cases
   for i in range(cases):
      binCap = int(binFile.readline())
      itemCount = int(binFile.readline())
      itemLine = binFile.readline()
      itemArray = [int(x) for x in itemLine.split(' ')]

      # once capcity and list of tiems grabbed run each fit type
      # use time library functions to track start and finish times
      start = time.time()
      firstNoOr = first_fit(itemArray, binCap)
      firstNoOr_time = time.time() - start

      start = time.time()
      bestNoOr = best_fit(itemArray, binCap)
      bestNoOr_time = time.time() - start

      itemArray.sort()
      itemArray.reverse()

      start = time.time()
      firstOr = first_fit(itemArray, binCap)
      firstOr_time = time.time() - start

      # take all results information and print as outlined in assingment
      print("Test Case {} First Fit: {}, {}. First Fit Decreasing: {}, {}. Best Fit: {}, {}.".format(i + 1, firstNoOr, firstNoOr_time, firstOr, firstOr_time, bestNoOr, bestNoOr_time))

   binFile.close()


main()
