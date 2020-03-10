/*
Author: Mitchell T Dennis
Date Created: March 3, 2020
Project: Calculating Pi
Last Updated: March 3, 2020

Summary: Let's try a MeshGrid
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
  time_t start, end;
  
  time(&start);
  
  double count = 1000;
  double circle[count][count] = {0};
  double

  srand(time(0));
  for (double i = 0; i < count; i++) {
    for (double j = 0; j < count; j++) {
      if((i/count)*(i/count)+(j/count)*(j/count) <= 1) {
	circle[i][j] = circle[i][j]+1;
	circle[i-1][j] = circle[i-1][j]-0.5;
	circle[i+1][j] = circle[i+1][j]-0.5;
	circle[i][j-1] = circle[i][j-1]-0.5;
	circle[i][j+1] = circle[i][j+1]-0.5;
      }
      else {
	circle[i][j] = circle[i][j]+1;
	circle[i-1][j] = circle[i-1][j]-0.5;
	circle[i+1][j] = circle[i+1][j]-0.5;
	circle[i][j-1] = circle[i][j-1]-0.5;
	circle[i][j+1] = circle[i][j+1]-0.5;
      }
    }
  }
 
  for (int k = 0; k < count; k++) {
    
  }
  
}


double smallest(double array[]) {
  double position = 0;
  for (int i = 0; sizeof(array); i++) {
    if(array[i] < array[position])
      position = i;
  }
  return position;
}
