/**
 * CS1010 Semester 1 AY21/22
 * Assignment 4: Mastermind
 *
 * @file: mastermind.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdbool.h>


// reading in the inputs of the list given
void read_arr(long len, long array[])
{
  for (long i = 0; i < len; i += 1)
  {
    array[i] = cs1010_read_long();
  }
}

// checking for black peg when guess matches code
bool is_black_peg(long code_i, long guess_i)
{
  return (code_i == guess_i);
}

// white peg is provided when manages to guess color but not position
bool is_peg_white(long len, long code[], long guess_i)
{
  // checking is white peg is obtained given guess[i]
  // for loop is being used to check through the code
  for (long y = 0; y < len; y += 1)
  {
    if (code[y] == guess_i)
    {
      code[y] = 0;
      return true;
    }
  }
  return false;
}

// checking if the code is correct or how many black and white pegs obtained
bool guess_black_white(long len, long code[], long guess[])
{
  // printing number of rights given same color and position in code and guess
  long black = 0;
  long white = 0;
  
  // for loop to check through the list of guesses for black pegs
  for (long i = 0; i < len; i += 1)
  {
    if (is_black_peg(code[i], guess[i]))
    {
      // checking for i when code = guess, once match, int
      // and increase count of black
      code[i] = 0;
      guess[i] = 0;
      black += 1;
    }
  }
  
  // for loop to check through list of guesses for white pegs
  for (long i = 0; i < len; i += 1)
  {
    if (guess[i] != 0 && is_peg_white(len, code, guess[i]))
    {
      white += 1;
    }
  }
  cs1010_print_long(black);
  cs1010_print_string(" ");
  cs1010_println_long(white);

  return (black == 4);
}

int main()
{
  long len = 4;
  long code[len];
  long guess[len];

  // obtaining code provided
  read_arr(len, code);
  
  // while loop to continue guessing until guess matches the code given
  bool correct_guess = false;
  long check[len];

  while (!correct_guess)
  {
    for (long i = 0; i < len; i += 1)
    {
      check[i] = code[i];
    }
    
    // obtain guess and check againts code to see if its the same as code
    read_arr(len, guess);
    correct_guess = guess_black_white(len, check, guess);
  }
}
