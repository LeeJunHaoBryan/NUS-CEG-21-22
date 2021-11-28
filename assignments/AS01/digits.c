/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Digits
 *
 * Read in a positive integer from the standard input and print
 * the sum of its digits to the standard output.
 *
 * @file: digits.c
 * @author: Bryan Lee (Group B08)
 */

#include "cs1010.h"

long sum_of_digits(long x)
{ // recursion, exit clause if x < 10
  if (x < 10) {
    return x;
  }
  return ((x % 10) + sum_of_digits(x / 10));
}

int main()
{
  // inputing value x
  long x = cs1010_read_long();

  //print output
  cs1010_println_long(sum_of_digits(x));
}
