/**
 * CS1010 Semester 1 AY21/22
 * Assignment 7: Sort
 *
 * @file: sort.c
 * @author: Bryan Lee (Group D08)
 */
#include "cs1010.h"

/**
 * given an array with a list of integers where the first K numbers are in 
 * increasing order and the rest are in decreasing order. we are required to
 * sort the array in increasing order
 *
 * this function is used to attain the max value in the array
 *
 * @param[in] n the number of integers of the array
 *
 *
 */ 

long get_max(long arr[], long n)
{
  long max = arr[0];
  for (long i = 1; i < n; i += 1)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

/**
 * 
 * this sort functions sorts the digits based on their least significane digit
 * ie. starting from the ones place followed by the tens place and comparing them
 *
 * @param[in] n the numbers present in the array 
 * 
 */ 

void sort1(long arr[], long n, long k)
{
  long output[n];
  long count[10] = {0};

  for (long i = 0; i < n; i += 1)
  {
    count[(arr[i] / k ) % 10] += 1;
  }

  for (long i = 1; i < 10; i += 1)
  {
    count [i] += count[i - 1];
  }

  for (long i = n - 1; i >= 0; i -= 1)
  {
    output[count[(arr[i] / k) % 10] - 1] = arr[i];
    count[(arr[i] / k) % 10] -= 1;
  }

  for (long i = 0; i < n; i += 1)
  {
    arr[i] = output[i];
  }
}

void sort2(long arr[], long n)
{
  long m = get_max(arr, n);

  for (long k = 1; (m  / k) > 0; k *= 10)
  {
    sort1(arr, n, k);
  }
}

void print(long arr[], long n)
{
  for (long i = 0; i < n; i += 1)
  {
    cs1010_print_long(arr[i]);
    cs1010_print_string(" ");
  }
}

int main()
{
  long n = cs1010_read_long();
  long *arr = cs1010_read_long_array((size_t)n);

  sort2(arr, n);
  print(arr, n);

}

