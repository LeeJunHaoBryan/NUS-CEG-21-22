/**
 * CS1010 Semester 1 AY21/22
 * Assignment 9: Digits
 *
 * @file: digits.c
 * @author: Bryan Lee (Group D08)
 */
#include "cs1010.h"
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define NCOLS 28
#define NROWS 28
#define WHITE '.'
#define BLACK '#'
#define K 5
#define MAX_DIGIT 9
typedef struct
{
  long label;
  char** digit;
} digit_t;

typedef struct {
  digit_t sample;
  long distance;
} neighbor;

void read_data(digit_t* array, long n);
void print(long n, digit_t* samples_a, long m, digit_t* test_a);
long train(digit_t* test, digit_t* samples_a, long n);
long get_distance(digit_t* test, digit_t* sample);
void get_smallest(long distance, long index, long* smallest, long* smallest_i);
void free_struct_array(digit_t* array, long n);

int main(){
  // read in samples data
  long train_n = cs1010_read_long();
  digit_t* training_sample = malloc((size_t)train_n * sizeof(digit_t));
  read_data(training_sample, train_n);

  // reading of tests data
  long test_m = cs1010_read_long();
  digit_t* testing_sample = malloc((size_t)test_m * sizeof(digit_t));
  read_data(testing_sample, test_m);

  print(train_n, training_sample, test_m, testing_sample);
 // free memory
  free_struct_array(training_sample, train_n);
  free_struct_array(testing_sample, test_m);

  return 0;
}

/**
 * This function reads in the input into a digit_t array
 * @param[in] array The array of digit_t
 * @param[in] n The number of elements in the array
 */
void read_data(digit_t* array, long n) {
  for (long i = 0; i < n; i += 1) {
    array[i].label = cs1010_read_long();
    array[i].digit = cs1010_read_word_array(NROWS);
  }
}

/**
 * This function prints out the output of comparing the
 * real number in the image and the recognition result from training.
 * and prints out the accuracy obtained
 *
 * @param[in] n The number of digit_t object in samples_a
 * @param[in] samples_a The array of digit_t objects as training samples
 * @param[in] m The number of digit_t object in test_a
 * @param[in] test_a The array of digit_t objects as tests cases
 */
void print(long n, digit_t* samples_a, long m, digit_t* test_a) {
  long correct = 0;
  long result;
  for (long i = 0; i < m; i += 1) {
    result = train(&test_a[i], samples_a, n);
    cs1010_print_long(test_a[i].label);
    putchar(' ');
    cs1010_println_long(result);
    if (result == test_a[i].label) {
      correct += 1;
    }
  }
  double accuracy = correct * (100.0) / m;
  cs1010_println_double(accuracy);
}

/**
 * This function test a digit_t object against a set of training data,
 * and return the result of digit recognition obtained.
 *
 * @param[in] test The pointer to the digit_t object to be tested
 * @param[in] samples_a The array of training data
 * @param[in] n The number of digit_t object in samples_a
 * @return Return (long) the digit recognized by the training set
 */
long train(digit_t* test, digit_t* samples_a, long n) {
  long* smallest = malloc(K * sizeof(*smallest));
  memset(smallest, -1, K * sizeof(*smallest));
  long* smallest_i = malloc(K * sizeof(*smallest));
  long distance = 0;
  for (long i = 0; i < n; i += 1) {
    distance = get_distance(test, &samples_a[i]);
    get_smallest(distance, i, smallest, smallest_i);
  }

  // determine which in the nearest neighbours is the best
  long array[MAX_DIGIT + 1];
  memset(array, 0, sizeof(array));
  for (long i = 0; i < K; i += 1) {
    array[samples_a[smallest_i[i]].label] += 1;
  }
  long result = 0;
  long max = 0;
  for (long i = 0; i < MAX_DIGIT + 1; i += 1) {
    if (array[i] > max) {
      max = array[i];
      result = i;
    }
  }
  free(smallest);
  free(smallest_i);
  return result;
}

/**
 * This function calculates the distance between two images
 *
 * @param[in] test The pointer to the test image
 * @param[in] sample The pointer to the sample image
 * @return Return (long) the distance between two images
 */
long get_distance(digit_t* test, digit_t* sample) {
  long distance = 0;
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      if (test->digit[i][j] != sample->digit[i][j]) {
        distance += 1;
      }
    }
  }
  return distance;
}

/**
 * This function determine if a certain distance (and its corresponding
 * index in the original array) should be put into an array containing the
 * smallest distance
 *
 * @param[in] distance The distance between two images
 * @param[in] index The index indicating from which test data the distance is obtained
 * @param[in] smallest The array containing the smallest distance
 * @param[in] smallest_i The array containing the index from which the smallest
 * distance is obtained
 */
void get_smallest(long distance, long index, long* smallest, long* smallest_i) {
  long fathest = 0;
  long fathest_i = 0;

  for (long i = 0; i < K; i += 1) {
    if (smallest[i] == -1) {
      smallest[i] = distance;
      smallest_i[i] = index;
      return;
    }
    if ((smallest[i] == fathest) && (smallest_i[i] > smallest_i[fathest_i])) {
      fathest_i = i;
    }
    if (smallest[i] > fathest) {
      fathest = smallest[i];
      fathest_i = i;
    }
  }
  if (distance < fathest) {
    smallest[fathest_i] = distance;
    smallest_i[fathest_i] = index;
  }
}

/**
 * this function is used to free the array in struct
 *
 * @param[in] array The array of image_t objects to be freed
 * @param[in] n The number of image_t obejects in the array
 */
void free_struct_array(digit_t* array, long n) {
  for (long i = 0; i < n; i += 1) {
    for (long j = 0; j < NROWS; j += 1) {
      free(array[i].digit[j]);
    }
    free(array[i].digit);
  }
  free(array);
}
