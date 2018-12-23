// File: pthread_sum.c
// Created on: 27th Jan 2018
// Updated on: 23rd Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;
void *runner(void *params);

int main(int argc, char *argv[]){
    pthread_t pid;
    pthread_attr_t attr;

    if( argc != 2) {
      fprintf(stderr, "usage: a.out <integer value>\n");
      return -1;
    }

    if ( atoi(argv[1]) < 0){
      fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
      return -1;
    }

    pthread_attr_init(&attr);
    pthread_create(&pid, &attr, runner, argv[1]);
    pthread_join(pid, NULL);

    printf("sum = %d\n", sum);
}

void *runner(void *params) {
  int i, upper = atoi(params);

  for(i = 1; i <= upper; i++)
    sum += i;
  pthread_exit(0);
}
