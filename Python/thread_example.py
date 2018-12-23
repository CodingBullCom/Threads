# File: thread_example.py
# Created on: 23rd Dec 2018
# Updated on: 23rd Dec 2018
# Author: Pawan Kumar Singh [pawan@codingbull.com]
# http://www.codingbull.com
#
# This source code is the part of free tutorial series provided by http://www.codingbull.com and
# it can be used/distributed without any restriction.

import threading

def print_atoz():
    for i in range(ord('a'), ord('z')+1):
        print(chr(i))

def print_1to100():
    for i in range(1,100):
        print(i)

if __name__ == "__main__":
    # creating thread
    t1 = threading.Thread(target=print_atoz, args=())
    t2 = threading.Thread(target=print_1to100, args=())

    # starting threads
    t1.start()
    t2.start()

    # wait until threads are completely executed
    t1.join()
    t2.join()
