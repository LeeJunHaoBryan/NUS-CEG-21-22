/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Pyramid
 *
 * Read in three positive integer corresponding to the width,
 * length, and height of a pyramid from the standard input, and
 * print the total surface area to the standard output.
 *
 * @file: pyramid.c
 * @author: Bryan Lee (Group B08)
 */

#include "cs1010.h"
#include <math.h>
// square function
double square(double bob) {
  return bob * bob;
}
// computing of hypotenuse given legs 
double hypotenuse_of(double x, double y)
{
  double z = sqrt(square(x) + square(y));
  return z;
}
// computing of area of rectangle given length a and width b
long area_of_rectangle(long a, long b)
{
  return a * b;
}
// computing the area of all 3 sides e, f, f
double area_of_triangle(long e, double f)
{
  double s = (e + f + f)/2;
    double area = sqrt(s * (s - e) * (s - f) * (s - f));
    return area;
}



int main() 
{
  // read in 3 integer w, l, h
  long w = cs1010_read_long();
  long l = cs1010_read_long();
  long h = cs1010_read_long();
  
  
  // area of rectangle
 long rectangle = (area_of_rectangle(l, w));

 // length from midpoint to end of triangle
 double slant = 0.5 * (hypotenuse_of(w, l));
 
 //sides of triangle
 double sides = (hypotenuse_of(h, slant));

 // area of triangle
 double triangle_w = (area_of_triangle(w, sides));
 double triangle_l = (area_of_triangle(l, sides));
 
 // surface area of pyramid
 double ans = rectangle + 2 * triangle_w + 2 * triangle_l;

 cs1010_println_double(ans);
 
}
