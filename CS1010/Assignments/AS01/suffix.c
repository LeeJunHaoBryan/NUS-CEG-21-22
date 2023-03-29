/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Suffix
 *
 * Read in a number and prints out the number with the appropriate suffix.
 *
 * @file: suffix.c
 * @author: Bryan Lee (Group B08)
 */
#include "cs1010.h"

void print_with_suffix(long n) { 
  // if n = 1 shld be 1st
  if (n == 1) {
    cs1010_println_string("st");
  }
  // if n = 2 shld be 2nd
  else if (n == 2) {
    cs1010_println_string("nd");
  }
  // if n = 3 shld be 3rd
  else if (n == 3) {
    cs1010_println_string("rd");
  }
  // everthing ending with 1 shld be st excpet if % 100 = 11
  else if ((n % 10 == 1) && (n % 100 != 11)) {
    cs1010_println_string("st");
  }
  // everything ending with 2 shld be nd except if % 100 = 12
  else if ((n % 10 == 2) && (n % 100 != 12)) {
    cs1010_println_string("nd");
  }
  // everything ending with 3 shld be rd except if % 100 = 13 
  else if ((n % 10 == 3) && (n % 100 != 13)) {
    cs1010_println_string("rd");
  }
  else {
    cs1010_println_string("th");
  }
}
       


int main() 
{ 
  long n = cs1010_read_long();
  cs1010_print_long(n);
  print_with_suffix(n);

}
