/**
 * CS1010 Semester 1 AY21/22
 * Assignment 6: Social
 *
 * @file: social.c
 * @author: Bryan Lee (Group D08)
 */

#include "cs1010.h"
#include <stdbool.h>

/**
 * by reading a jagged array, find out the chain of friendships up 
 * k degrees of network. we are to assume that the friendship
 * is such that if a is a friend of b, b will also be a friend of a
 * inputs of arrays are given as of type char where '1' means person a
 * and person b are friends and '0' meaning otherwise
 * by making use of functions present in the first question
 * to solve this question
 *
 * this function is used to obtain the jagged array that should be read
 * @param[in] n array to be read
 *
 * @pre inputs of array are of type char '1' and '0'
 */

char **get_friendship_arr(size_t n)
{
  char **get_arr = calloc(n, sizeof(char *));
  if (get_arr == NULL)
  {
    cs1010_println_string(" unable to allocate array");
    return NULL;
  }

  for (size_t i = 0; i < n; i += 1)
  {
    get_arr[i] = cs1010_read_line();
    if (get_arr == NULL)
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
 * this bool function is to check if one is connected to other thru a third person
 * with 3 different scenarios displayed in the 3 different for loops
 *
 * @param[in] n n lines of strings for array
 * @param[in] F1 friend no 1
 * @param[in] F2 friend no 2
 * 
 * @return returns true if they are connected thru a third person, else return false
 */ 

bool is_indirect_friend(size_t n, char **get_arr, size_t F1, size_t F2)
{
  for (size_t i = 0 ;  i < F2; i += 1)
  {
    if (get_arr[F1][i] == '1' && get_arr[F2][i] == '1')
    {
      return true;
    }
  }

  for (size_t i = F2 + 1; i < F1; i += 1)
  {
    if (get_arr[F1][i] == '1' && get_arr[i][F2] == '1')
    {
      return true;
    }
  }

  for (size_t i = F1 + 1; i < n; i += 1)
  {
    if (get_arr[i][F1] == '1' && get_arr[i][F2] =='1')
    {
      return true;
    }
  }
  return false;
}

/**
 * This function is used to check for the degree of friendship k
 * by receving the array from the input and check for '1'
 *
 * this is a recursive function where by the base case is when x = 1 ie
 * ending clause
 * else it calls itself till it reaches the base case
 *
 * @param[in] n size of array
 * @param[in] x degree of frienship
 *
 * @return returns x degree of friendship
 */ 

char **degree_friendship(size_t n ,char **arr_1, char **arr_2, size_t x)
{
  // recursive ending clause returns array of degree = 1
  if (x == 1)
  {
    return arr_1;
  }
  // else enters recusive calls
  for (size_t i = 0; i < n; i += 1)
  {
    for (size_t j = 0; j < i; j += 1)
    {
      if (is_indirect_friend(n, arr_2, i, j))
      {
        arr_1[i][j] = '1';
      }
    }
  }
  return degree_friendship(n, arr_1, arr_1, x - 1);
}

int main()
{
  // taking in of inputs
  size_t n = cs1010_read_size_t();
  size_t x = cs1010_read_size_t();
  char **arr;
  arr = get_friendship_arr(n);
  char **degree_of_frenship;
  degree_of_frenship = degree_friendship(n, arr, arr, x);
  for (size_t i = 0; i < n; i += 1)
  {
    cs1010_print_string(degree_of_frenship[i]);
    free(degree_of_frenship[i]);
    degree_of_frenship[i] = NULL;
  }
  free(degree_of_frenship);
  degree_of_frenship = NULL;
}
