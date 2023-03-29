/**
 * CS1010 Semester 1 AY21/22
 * Assignment 7: Inversion
 *
 * @file: inversion.c
 * @author: Bryan Lee (Group D08)
 */

#include "cs1010.h"
/**
 * given an array where the first k digits are sorted in an ascending order
 * and the remaining n - k are in a descending order, we are to count the 
 * number of inversions present in the list of the array
 *
 * @param[in] n the number of integers present in the array
 * @return returns counter, the
 */ 

long inversion_sort_ID(long *arr, long n)
{
  // i represents the first index of the array and j being the last index of the array
  long i = 0; 
  long j = n - 1;

  // counter counts the number of inversions 
  long counter = 0;
  long right_position = 0;
  while (i < j)
  {
    if (arr[i] < arr[j])
    {
      right_position += 1;
      i += 1;
    }
    else
    {
      counter += j - right_position;
      j -= 1;
    }
  }
  return counter;
}

int main()
{
  long n = cs1010_read_long();
  long *arr = cs1010_read_long_array((size_t)n);
  if (arr == NULL)
  {
    return 1;
  }
  cs1010_println_long(inversion_sort_ID(arr, n));
  free(arr);
}
