/**
 * CS1010 Semester 1 AY21/22
 * Assignment 6: Contact
 *
 * @file: contact.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdbool.h>

/**
 * using a jagged array we are to determine if people are
 * (a) in direct contact with one another
 * (b) in indirect contact with one another
 * (c) no contact with each other at all
 * the array will be represent with char type of '1' and '0'
 * where '1' suggests that one in in direct contact with the other
 * and '0' suggests that they are not in contact with each other
 * contact is a symmetric relation where if person a is in contact
 * with person b, person b is also said to be in contact with person
 * a
 *
 *
 * this function is used to obtain the lower triangular jagged array used for the inputs
 *
 * @param[in] n The jagged array input
 * @return returns get_arr
 *
 * @pre inputs are given in terms of char type of '1' and '0'
 */

char **get_person_arr(size_t n)
{
  char **get_arr = calloc(n, sizeof(char *));
  if (get_arr == NULL)
  {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }

  for (size_t i = 0; i < n; i += 1)
  {
    get_arr[i] = cs1010_read_line();
    if (get_arr[i] == NULL)
    {
      for (size_t j = 0; j < i; j += 1)
      {
        free(get_arr[j]);
      }
      free(get_arr);
      return NULL;
    }
  }
  return get_arr;
}

/**
 * This bool function checks for direct contact
 *
 * @param[in] idx the id of the first person
 * @param[in] idy the id of the second person
 *
 * @return returns true if idy is in direct contact with idy, else returns false
 */ 

bool is_direct_contact(char **get_arr, size_t idx, size_t idy)
{
  if (get_arr[idx][idy] == '1')
  {
    cs1010_println_string("direct contact");
    return true;
  }
  if (get_arr[idx][idy] == '0')
  {
    return false;
  }
  return true;
}

/**
 * this is a bool function to check for indirect contact. there are 3 possible scenarios
 * where one will be indirect contact with another
 * scenario 1: when id(indirect) is < that id(x) and id(y)
 * scenario 2: when id(indirect) > id(x) and id(y)
 * scenario 3: when id(x) < id(indirect) < id(y)
 *
 * @param[in] n the input of jagged array
 * @param[in] idx id of person 
 * @param[in] idy id of person
 *
 * @return returns true if either of the scenario == '1' else returns false
 *
 */

bool is_indirect_contact(size_t n, char **get_arr, size_t idx, size_t idy)
{
  for (size_t i = 0; i < idy; i += 1)
  {
    // indirect contact through scenario 1 where indirect < idx & idy
    if (get_arr[idx][i] == '1' && get_arr[idy][i] == '1')
    {
      cs1010_print_string("contact through ");
      cs1010_println_size_t(i);
      return true;
    }
  }
  
  // indirect contact through scenario 2 where idx < indirect < idy
  for (size_t i = idy + 1; i < idx; i += 1)
  {
    if (get_arr[idx][i] == '1' && get_arr[i][idy] == '1')
    {
      cs1010_print_string("contact through ");
      cs1010_println_size_t(i);
      return true;
    }
  }
  
  // indirect contact through scenario 3 where indirect > idx & idy
  for (size_t i = idx + 1; i < n; i += 1)
  {
    if (get_arr[i][idx] == '1' && get_arr[i][idy] == '1')
    {
      cs1010_print_string("contact through ");
      cs1010_print_size_t(i);
      return true;
    }
  }
  return false;
}

/**
 * This function checks whether one is (a)direct contact or (b)indirect contact and prints respectively
 * else will print no contact
 *
 * @param[in] n the input of array
 * @param[in] idx id of person
 * @param[in] idy id of person
 *
 */
void check(size_t n, char **get_arr, size_t idx, size_t idy)
{
  // prints 'direct contact when idx and idy are in direct contact
  if (is_direct_contact(get_arr, idx, idy))
  {
    // nothing
  }
  // else prints indirect contact if idx and idy are in indirect thru another person
  else if (is_indirect_contact(n, get_arr, idx, idy))
  {
    // nothing
  }
  // else print no contact at all
  else
  {
    cs1010_println_string("no contact");
  }
}


int main()
{
  size_t k = cs1010_read_size_t();
  char ** arr;
  arr = get_person_arr(k);
  size_t m = cs1010_read_size_t();
  size_t n = cs1010_read_size_t();

  // as for jagged array [x][y] value on right hand side must be larger thn
  // left hand side
  if (m > n)
  {
    check(k,arr, m, n);
  }
  else
  {
    check(k, arr, n, m);
  }
  for (size_t i = 0; i < k; i += 1)
  {
    free(arr[i]);
    arr[i] = NULL;
  }
  free(arr);
  arr = NULL;
}
