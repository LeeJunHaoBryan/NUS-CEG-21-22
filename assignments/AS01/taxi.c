/**
 * CS1010 Semester 1 AY21/22
 * Assignment 1: Taxi
 *
 * Read in four positive integer corresponding to the day of the week,
 * the hour and minute of boarding, and the distance travelled.  Print
 * to the standard output, the taxi fare for the trip.
 *
 * @file: taxi.c
 * @author: Bryan Lee (Group B08)
 */

#include "cs1010.h"
#include <stdbool.h>

bool is_weekday(long day) // checking if day falls during weekday/weekend 1 being monday, 7 being sunday
{
  if ((day >= 1) && (day <= 5)) {
      return true;
    }
      return false;
}

bool is_morning_peak(long hour, long mins) // checking if time lies between morning peak hour 6:00 - 9:29
{
  // check if hour is between 9-6
 if ((hour >= 6) && (hour <= 9)) {
    // if time is after 9.29 return false
    if(hour == 9 && mins > 29) {
      return false;
    } 
    return true;
 }
 return false;
}


bool is_evening_peak(long hour) // check if time falls between afternoon peak hour 1800 - 2359
{
  if ((hour >= 18) && (hour <= 23)) { 
      return true;
  }
  return false;
}

bool is_midnight_peak(long c) // check if time falls between midnight peak hour 0:00-559
{
  if ((c >= 0) && (c <= 5)) {
      return true;
    }
  return false;
}

double fare1(long dist) // calculating the basic fare by inputting distance between 1km to 10km
{
  if (dist <= 400) {
    return 0.22;
  }
  return (0.22 + fare1(dist - 400));
}

double fare2(long dist) // calculating basic fare if dist >10000
{
  if (dist <= 350) {
    return 0.22;
} 
    return (0.22 + fare2(dist - 350));
}

double surcharge(double bsfare, double percent)
{
  return bsfare * percent;
}


int main()
{
 // input 4 integer, day(d) ,time(t1), time(t2), distance(dist)
 long day = cs1010_read_long(); // d represent the day of the week 1 being monday, 7 being sunday
 long hour = cs1010_read_long(); // t1 represents hour of the time <23
 long mins = cs1010_read_long(); // t2 represents minutes of time <60
 long dist = cs1010_read_long(); // dist representing the distance travelled

 // basic fare(flag down fare) + distance
 
 double basicfare = 3.70;

   if ((dist > 1000) && (dist <= 10000)) {
     basicfare = basicfare + fare1(dist - 1000 );
   } else if (dist > 10000) {
     basicfare = basicfare + fare1(9000) + fare2(dist - 10000);
   }
  // tcost will be the total cost including surcharges
  double tcost = basicfare;
  {
    // if weekday and time falls between 6-9.29, there will be morning surcharge of 25%
    if (is_weekday(day)) {
      if (is_morning_peak(hour, mins)) {
        tcost = basicfare + surcharge(basicfare, 0.25);
    }
    }
  }
  // if mon-sun and time falls between 1800-2359, there will be a surcharge of 25%
    if (is_evening_peak(hour)) {
      tcost = basicfare + surcharge(basicfare, 0.25);
    }
    // if mon-sun and time falls between 0000-0559, there will be a surcharge of 50%
    else if (is_midnight_peak(hour)) {
      tcost = basicfare + surcharge(basicfare, 0.50);
    }
  
  // printing the total cost of the taxi fare
  cs1010_println_double(tcost);
}


