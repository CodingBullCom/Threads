// File: PrintOddEven.java
// Created on: 23rd Nov 2018
// Updated on: 30th Nov 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

import java.util.*;

class Printer {
  boolean isOdd = false;
  synchronized void printOdd(int number) {
      while(isOdd == true) {
        try {
          wait();
        } catch(Exception e) {}
      }
      System.out.println(number);
      isOdd = true;
      notifyAll();
  }

  synchronized void printEven(int number) {
       while(isOdd == false ) {
         try {
           wait();
         } catch(Exception e){}
       }
       System.out.println(number);
       isOdd = false;
       notifyAll();
  }

}

class PrinterUtility implements Runnable {
    private int max;
    private Printer printer;
    private boolean isEvenNumber;

    PrinterUtility(Printer printer, int max, boolean isEvenNumber) {
        this.printer = printer;
        this.max = max;
        this.isEvenNumber = isEvenNumber;
    }

    @Override
    public void run() {
        int number = isEvenNumber ? 2 : 1;
        while(number <= max) {
           if(isEvenNumber)
               printer.printEven(number);
           else
               printer.printOdd(number);
           number += 2;
        }
    }
}

class PrintOddEven {
    public static void main(String[] args) {
        Printer printer = new Printer();
        Thread t1 = new Thread(new PrinterUtility(printer, 10, true));
        Thread t2 = new Thread(new PrinterUtility(printer, 10, false));
        t1.start();
        t2.start();
    }
}
