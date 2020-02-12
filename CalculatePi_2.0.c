/*
Author: Mitchell T Dennis
Date Created: February 02, 2020
Project: Calculating Pi
Last Updated: February 10, 2020

Summary: This project will determine the value of pi by comparing the ratio of the area of a square to the area of a circle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
  time_t start, end;

  time(&start);
    
  double count = 1000000000;
  double circle = 0;

  srand(time(0));
  for (int i = 0; i < count; i++) {
    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    if (y<=-x+1)
      circle++;
    else if(x*x + y*y <= 1)
      circle++;
  }
  double pi = (circle)/(count)*4;
  printf("The value of pi is %f\n", pi);

  time(&end);
  double time_taken = (end - start);
  printf("The run time is %f\n", time_taken);
  
}
