/**
 * CS1010 Semester 1 AY21/22
 * Assignment 4: SelectionSort
 *
 * @file: selection.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"

void selection_sort(long list[], long n)
{
  long max;
  long temp;
  for (long i = n - 1; i >= 1; i -= 1)
  {
    max = i;
    for (long j = i; j >= 0; j -= 1)
    {
      if (list[max] < list[j])
      {
        max = j;
      }
    }
    temp = list[max];
    list[max] = list[i];
    list[i] = temp;
    for (long x = 0; x < n; x +=1)
    {
      cs1010_print_long(list[x]);
      cs1010_print_string(" ");
    }
    cs1010_println_string("");

  }
}




int main() 
{
  long list[1000];
  long n = cs1010_read_long();

  for (long i = 0; i < n; i += 1)
  {
    list[i] = cs1010_read_long();
  }
  selection_sort(list, n);

}

