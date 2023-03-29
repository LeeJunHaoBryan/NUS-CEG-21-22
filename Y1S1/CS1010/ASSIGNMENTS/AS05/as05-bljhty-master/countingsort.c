/**
 * CS1010 Semester 1 AY21/22
 * Assignment 5: CountingSort
 *
 * Read in a series of numbers between 0 and 10000 
 * and sort them using counting sort.
 *
 * @file: countingsort.c
 * @author: Bryan Lee (Group D08)
 */

/**
 * this funtion takes a count arrat to store the count of each unique object
 * and modify the count array such that each elemet at each index stores the sum
 * of previous counts
 * the modified count array indicates the position of each object in thee output sequence
 * lastly it outputs each object from the input sequence followed by increasing its
 * count by 1
 *
 * @param [in] n the numbers of integers to sort
 * @param [in, out] arr the integers to be sorted, between 0 t0 10000
 * 
 * @pre count <= 100001
 * @pre length of input can fit into type 'size_t'
 */ 
#include "cs1010.h"
void countingsort(long arr[], long n)
{
  long output[n];

  long count [10001] = { 0 };
  for (long i = 0; i < n ; i += 1)
  {
    count[arr[i]] += 1;
  }

  for (long i = 1; i <= 10000; i += 1)
  {
    count[i] += count[i - 1];
  }

  for (long i = 0; i < n; i += 1)
  {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]] -= 1;
  }

  for (long i = 0; i < n; i += 1)
  {
    arr[i] = output[i];
  }
}

int main()
{
  size_t k = cs1010_read_size_t();
  long * arr = cs1010_read_long_array(k);

  long n = (long)k;
  countingsort(arr, n);

  for (long i = 0; i < n; i += 1)
  {
    cs1010_println_long(arr[i]);
  }

  free(arr);
  arr = NULL;
}
