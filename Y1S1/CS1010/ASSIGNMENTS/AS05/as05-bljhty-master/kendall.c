/*
 * CS1010 Semester 1 AY21/22
 * Assignment 5: Kendall
 *
 * Read in a sequence of numbers and find its kendall tau 
 * distance.
 *
 * @file: kendall.c
 * @author: Bryan Lee (Group D08)
 */
#include "cs1010.h"

/**
 * calculating the kendall tau distance between rankings
 * which counts the number of pairs of items in one ranking 
 * that are ranked in a differen order in the other ranking
 *
 * this function finds the total count where the rankings are
 * being arranged differently and stores as count.
 * 'count' increments by 1 whenever there is a ranking that
 * is arranged differently. the kendall tau distance is than
 * normalised by calculating the ratio between the count
 * and the total number of possible arrangements
 *
 * @param [in, out] n number of items
 * @param [in] rank the ranking of items from 1 to n
 *
 * @return returns counter/normalise , the normalised kendall tau distance
 *
 * @pre n > 1
 * @pre length can fit into 'size_t'
*/
double kendalltau(long n, long rank[n])
{
  long i = 0;
  double counter = 0.0;
  while (i < n)
  {
    for (long j = i + 1; j < n; j += 1)
    {
      if (rank[i] > rank [j])
      {
        counter += 1.0;
      }
    }
    i += 1;
  }
  long normalise = n * (n - 1) / 2;
  return counter / normalise;
}

int main()
{
  size_t n = cs1010_read_size_t();
  long *rank;
  rank = cs1010_read_long_array(n);

  long var = (long) n;
  cs1010_println_double(kendalltau(var, rank));

  free(rank);
  rank = NULL;
}
