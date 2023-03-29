/**
 * CS1010 Semester 1 AY21/22
 * Assignment 6: Life
 *
 * @file: life.c
 * @author: Bryan Lee (Group D08)
 */
#include "cs1010.h"
#include <unistd.h>

/**
 * this program requies a rectangular multi dimensional array which prints out
 * live cell as char '#' and dead cells as char '.'
 *
 * this funtion is used to make nrows and mcols of a sheet through dynamic memory
 * allocation
 *
 * @param[in] n the number of rows array has to be allocated
 *
 * @return returns a 2d array of char
 *
 * @pre inputs are read in as type char of '.' and '#'
 */


char **first_gen_arr(size_t n)
{
  char **gen1 = calloc(n, sizeof(char *));
  if (gen1 == NULL)
  {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }
  for (size_t i = 0; i < n; i += 1)
  {
    gen1[i] = cs1010_read_line();
    if (gen1[i] == NULL)
    {
      for (size_t j = 0; j < i; j += 1)
      {
        free(gen1[j]);
      }
      free(gen1);
      return NULL;
    }
  }
  return gen1;
}

/**
 * this function is used to obtain an uninitialised array canvas_aft_arr with
 * nrows and m cols
 *
 * @param[in] nrows number of rows of the array
 * @param[in] mcols number of columns of the arrat
 *
 * @return returns an uninitialised array with nrows and mcols
 */ 

char **next_gen_arr(size_t nrows, size_t mcols)
{
  char **next_gen = calloc(nrows, sizeof(char *));
  if (next_gen == NULL)
  {
    cs1010_println_string("unable to allocate array");
    return NULL;
  }
  for (size_t i = 0; i < nrows; i += 1)
  {
    next_gen[i] = calloc(mcols, sizeof(char));
    if (next_gen[i] == NULL)
    {
      for (size_t j = 0; j < i; j += 1)
      {
        free(next_gen[j]);
      }
      free(next_gen);
      return NULL;
    }
  }
  return next_gen;
}

/**
 * this function is used to check for the people that are alive in the row/col
 * which is represented by the char '#' and increases count by 1 whenever
 * there is someone that is alive, using a for loop to go through the entire
 * array
 *
 * @param[in] x row number of canvas 
 * @param[in] y column number of canvas
 * @param[in] gen1 the array that is being checked
 *
 * @return returns the total number of people that are alive in the row
 *
 * @pre cells with row 0 or n-1,or column 0 or m- 1, border cells are always dead
 */ 

// checking for people that are alive '#' in the sheet
long people_alive(size_t x, size_t y, char **gen1)
{
  long count = 0;
  for (size_t i = y - 1; i <= (y + 1); i += 1)
  {
    if (gen1[x - 1][i] == '#')
    {
      count += 1;
    }
  }

  for (size_t i = y - 1; i <= (y + 1); i += 1)
  {
    if (gen1[x + 1][i] == '#')
    {
      count += 1;
    }
  }
  if (gen1[x][y - 1] == '#')
  {
    count += 1;
  }
  if (gen1[x][y + 1] == '#')
  {
    count += 1;
  }
  return count;
}

/**
 * this function is subsequently used to update the next generation of people that are
 * alive or dead
 * cells with with <  2 neighbours becomes dead
 * cells witn 2 || 3 neighbours remains alive
 * cells with > 3 neighbours becomes dead
 * cells with exactly 3 neightbours becomes alive
 *
 * @param[in] a row of canvas
 * @param[in] b column of canvas
 * @param[in] gen1 the previous array before updating the status of the neighbout
 * @param[in] next_gen the updated array after the status of the neighbour
 *
 */ 

void update_next_generation(size_t a, size_t b, char **gen1, char **next_gen)
{
  long ppl_alive = people_alive(a, b, gen1);

  // if 2 neighbours are alive, next_gen will still be alive
  if (gen1[a][b] == '#')
  {
    if (ppl_alive == 2)
    {
      next_gen[a][b] = '#';
      return;
    }
    // if 3 neighbours are alive, next_gen will still be alive
    if (ppl_alive == 3)
    {
      next_gen[a][b] = '#';
      return;
    }
    next_gen[a][b] = '.';
  }
  else if (gen1[a][b] == '.')
  {
    if (ppl_alive == 3)
    {
      next_gen[a][b] = '#';
      return;
    }
    next_gen[a][b] = '.';
  }
}

/**
 * a function to iterate through k number of times to print for the canvas
 *
 * @param[in] n rows of canvas
 * @param[in] m column of canvas
 * @param[in] gen1 the first array 
 * @param[in] next_gen the updated array
 *
 */ 

void k_iteration(size_t n, size_t m, char **gen1, char **next_gen)
{
  for (size_t i = 1; i < (n - 1); i += 1)
  {
    for (size_t j = 1; j < (m - 1); j += 1)
    {
      update_next_generation(i, j, gen1, next_gen);
    }
  }
}

void get_ans(size_t n, char **gen1)
{
  cs1010_clear_screen();
  for (size_t i = 0; i < n; i += 1)
  {
    cs1010_print_string(gen1[i]);
  }
   usleep(250*1000);
}


int main()
{
  size_t n = cs1010_read_size_t();
  size_t m = cs1010_read_size_t();
  long k = cs1010_read_long();

  char **gen1;
  gen1 = first_gen_arr(n);

  for (long i = 0; i < k; i += 1)
  {
    char **next_gen = next_gen_arr(n, m);
    k_iteration(n, m, gen1, next_gen);

    for (size_t y = 1; y < n - 1; y += 1)
    {
      for (size_t j = 1; j < m - 1; j += 1)
      {
        gen1[y][j] = next_gen[y][j];
      }
    }
    for (size_t y = 0; y < n; y += 1)
    {
      free(next_gen[y]);
    }
    free(next_gen);

    get_ans(n, gen1);
  }

  for (size_t x = 0; x < n; x += 1)
  {
    free(gen1[x]);
  }
  free(gen1);
}

