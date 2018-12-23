// File: thread_example.cpp
// Created on: 23rd Dec 2018
// Updated on: 23rd Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

#include <iostream>
#include <thread>

using namespace std;

void print_atoz() {
    for(char i = 'a'; i <= 'z'; i++)
        cout << i << endl;
}

struct thread_ex {
    void operator()(){
      print_1to100();
    }
    void print_1to100() {
      for(int i = 1; i <= 100; i++)
          cout << i << endl;
    }
};

int main() {
   cout << " ** Thread Example ** " << endl;
   thread_ex thread_example;
   //create new threads and execute them
   thread t1(thread_example);
   thread t2(print_atoz);

   //Wait untill both thread stops executing
   t1.join();
   t2.join();

   return 0;
}
