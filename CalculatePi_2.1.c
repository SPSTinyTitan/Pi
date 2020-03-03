/*
Author: Mitchell T Dennis
Date Created: February 02, 2020
Project: Calculating Pi
Last Updated: March 3, 2020

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
    
  double count = 100000000;
  double circle = 0;
  double x[count];
  double y[count];
  
  srand(time(0));
  for (int i = 0; i < count; i++) {
    x[i] = (double)rand()/RAND_MAX;
    y[i] = (double)rand()/RAND_MAX;
  
  
  for (int i = 0; i < count; i++) {
    if (y[i]<=-x[i]+1)
      circle++;
    else if(x[i]*x[i] + y[i]*y[i] <= 1)
      circle++;
  }
  double pi = (circle)/(count)*4;
  printf("The value of pi is %f\n", pi);

  time(&end);
  double time_taken = (end - start);
  printf("The run time is %f\n", time_taken);
  
}
