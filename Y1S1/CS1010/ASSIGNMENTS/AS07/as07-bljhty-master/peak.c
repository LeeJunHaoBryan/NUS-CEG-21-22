/**
 * CS1010 Semester 1 AY21/22
 * Assignment 7: Peak
 *
 * @file: peak.c
 * @author: Bryan Lee (Group D08)
 */
#include "cs1010.h"


/**
 * Given a mountain array, we are to find a peak among the array and print
 * the peak as the output. if there is no peak we are to print 'no peak'
 * 
 * a mountain array is such that the number will increase in an ascending order
 * and followed by decreasing order.
 *
 * @param[in] arr the array that will be read in
 * @param[in] n the numbers contains in the array list
 * 
 * @returns returns the peak indeex if found else returns -1.
 *
 */ 
long find_peak(long arr[], long n)
{
  long f = 1;
  long l = n - 2;
  while (f <= l)
  {
    // finding the mid point of the array by taking summing the first and last index and halving it
    long mid = (f + l)/2; 
   
    // if the number in the middle index is greater than both its neighbours, it will then be the
    // peak of the array hence, return the middle index
    if (arr[mid] > arr[mid -1] && arr[mid] > arr[mid + 1])
    {
      return mid;
    }
    // else if the no. in the middle index is smaller than the neighbour to the right, means the first
    // half is sorted in an acsending order
    if (arr[mid] < arr[mid + 1])
    {
      f = mid + 1;
    }
    else
    {
      l = mid - 1;
    }
  }
  return 0;
}


int main()
{
  // reading in of inputs
  long n = cs1010_read_long();
  long *arr = cs1010_read_long_array((size_t)n);
  if (arr == NULL)
  {
    return 1;
  }
  // if no peak is found print 'no peak'
  if (find_peak(arr, n) == 0)
  {
    cs1010_println_string("no peak");
  }
  else 
  {
    cs1010_println_long(find_peak(arr, n));
  }
  free(arr);
}
