/**
 * CS1010 Semester 1 AY21/22
 * Assignment 5: Add
 *
 * @file: add.c
 * @author: Bryan Lee (Group D08)
 */

#include "cs1010.h"
#include <stdbool.h>

/**
 * addition of two arbitary large numbers that may not fit
 * the size of a 'long long int' 
 * read 2 non-negative integers that are represented by strings
 * which consists of digits 0 - 9 and sum both digits and 
 * output the sum of the digits
 *
 * this function takes in 2 large numbers and add them together
 * by obtaining the last index of the string and summing
 * them
 * if the sum of the 2 values exceeds 10 we will look at
 * the digit to the left of the number and increase them
 * by 1
 *
 * @param[in] no1 first no inputted to calculate the sum
 * @param[in] no2 second no inputted to calculate the sum
 *
 * 
 * @pre numbers are being represented by arbitrarily long string
 * consisting of char of type 'char' from '0' to '9' 
 * @pre to convert char to no. +'0', to convert no. to 
 * char -'0'
 *
 */
void addstr(char no1[], char no2[])
{
  long length1 = (long) strlen(no1);
  long length2 = (long) strlen(no2);
  long a = length1 - 1; // to obtain the last index of the array
  long b = length2 - 1; // to obtain the last index of the array
  long increase = 0; // increase by 1 whenever digits > 10
  long sum = 0; // sum of char 1 and char 2

  while(b >= 0)
  {
    sum = no1[a] + no2[b] - 2  * '0' + increase; // - 2 * 0 to obtain the digit for no1 and no2
    increase = 0;

    if (sum >= 10) // when both digits add together to give > 10, increase value of digit next to it by 1
    {
      increase = 1;
      sum = sum % 10; // final sum would be the remainder
    }

    no1[a] = (char) (sum + '0'); // add 0 to obtain the char of the digit
    b -= 1; // move on to the next index
    a -= 1; // move on to the next index
  }

  while (a >= 0)
  {
    // this loop will only activates when b == 0
    sum = no1[a] - '0' + increase;
    increase = 0;

    if (sum >= 10) // same concept as before
    {
      increase = 1;
      sum = sum % 10;
    }

    no1[a] = (char) (sum + '0');
    a -= 1;
  }

  if (increase > 0)
  {
    cs1010_print_long(1);
  }

  for (long i = 0; i < length1; i += 1)
  {
    long value = no1[i] - '0';
    cs1010_print_long(value);
  }
}

int main()
{
  // reading of inputs of strings provided
  char *no1 = cs1010_read_word();
  char *no2 = cs1010_read_word();

  if (strlen(no1) > strlen(no2))
  {
    addstr(no1, no2);
  } else {
    addstr(no2, no1);
  }

  free(no1);
  free(no2);
  no1 = NULL;
  no2 = NULL;
}
