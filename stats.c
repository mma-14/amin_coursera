/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>

#include "stats.h"

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  int size = SIZE;
  print_array(test,size);
  printf("\n");
  print_statistics(test,size);
  sort_array(test,size);
  printf("\nthe sorted array \n");
  print_array(test,size);
}

void print_array(unsigned char *ptr, int size){

  for (i =0 ;i < size ;i++){
    printf("%d  ",ptr[i]);
    if ((i+1)%8 == 0){
      printf("\n");
    }
  }
}

unsigned char find_median(unsigned char *ptr,int size){

  unsigned char tmp1,tmp2,median_value;
  tmp1 = ((size)/2.0)-1;
  tmp2 = tmp1+1;
  median_value = ((ptr[tmp1]+ptr[tmp2])/2.0);
  return median_value;
}

float find_mean(unsigned char *ptr,int size){

  /* the data type here is int because the sum of all array elements is larger than unsigned char */
  int tmp=0;
  float mean_value;
  for( i=0;i < size;i++){
    tmp += ptr[i];
  }
  mean_value = tmp / (size*1.0);
  return mean_value;
}

unsigned char find_maximum(unsigned char *ptr,int size){

  unsigned char max_value;
  max_value = ptr[0];
  for(i=1;i<size;i++){
    if (max_value<ptr[i]){
      max_value = ptr[i];
    }
  }
  return max_value;
}

unsigned char find_minimum(unsigned char *ptr,int size){

  int min_value;
  min_value = ptr[0];
  for(i=1;i<size;i++){
    if (min_value>ptr[i]){
      min_value = ptr[i];
    }
  }
  return min_value;
}

void sort_array(unsigned char *ptr,int size){

  unsigned char tmp;
  for (i = 0 ; i < size-1; i++)
  {
    for (j = 0 ; j < size-i-1; j++)
    {
      if (ptr[j] < ptr[j+1])
      {
        tmp = ptr[j];
        ptr[j] = ptr[j+1];
        ptr[j+1] = tmp;
      }
    }
  }
}

void print_statistics(unsigned char *ptr,int size){

  unsigned char minimum_value,maximum_value,median_value;
  float mean_value;
  minimum_value = find_minimum(ptr,size);
  maximum_value = find_maximum(ptr,size);
  median_value  = find_median(ptr,size);
  mean_value    = find_mean(ptr,size);

  printf("the minimum value is %d\n",minimum_value);
  printf("the maximum value is %d\n",maximum_value);
  printf("the median value is %d\n",median_value);
  printf("the mean value is %.2f\n",mean_value);

}

