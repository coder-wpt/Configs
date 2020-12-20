//===----------------------------------------------------------------------===//
//
// Written by Xing Mingjie (mingjie.xing@gmail.com).
//
// A test program for circuit finding algorithm.
//
//===----------------------------------------------------------------------===//


/*
           V5      V3
     +-<---o---<---o---<--+
     |             |      |
  V1 o             ^      o V4
     |           V2|      |
     +------>------o--->--+
                  / \
                 |   |
                 +->-+

   N = 5
  
        / 2 0 0 0 0 \
        | 2 3 4 0 0 |
   AK = | 5 0 0 0 0 |
        | 3 0 0 0 0 |
        \ 1 0 0 0 0 /
*/

#include "CircuitFinder.h"
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
 /* int A[5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 0, 1,
    0, 0, 1, 0, 0,
    1, 0, 0, 0, 0
  };
*/

 /* int B[19][19]={
//  1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
    0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,

  };
*/

    int B[67][7]={
    55,0,0,0,0,0,0,
    55,54,0,0,0,0,0,
    54,0,0,0,0,0,0,
    52,51,0,0,0,0,0,
    51,0,0,0,0,0,0,
    51,0,0,0,0,0,0,
    50,0,0,0,0,0,0,
    50,51,0,0,0,0,0,
    58,0,0,0,0,0,0,
    58,57,0,0,0,0,0,
    57,56,0,0,0,0,0,
    56,0,0,0,0,0,0,
    54,53,0,0,0,0,0,
    53,0,0,0,0,0,0,
    62,0,0,0,0,0,0,
    62,0,0,0,0,0,0,
    62,0,0,0,0,0,0,
    62,0,0,0,0,0,0,
    62,0,0,0,0,0,0,
    62,0,0,0,0,0,0,
    60,61,0,0,0,0,0,
    60,61,0,0,0,0,0,
    59,60,0,0,0,0,0,
    50,59,0,0,0,0,0,
    60,0,0,0,0,0,0,
    4,0,0,0,0,0,0,
    4,5,0,0,0,0,0,
    4,5,0,0,0,0,0,
    5,6,7,0,0,0,0,
    6,7,8,0,0,0,0,
    8,24,0,0,0,0,0,
    13,14,0,0,0,0,0,
    13,14,0,0,0,0,0,
    13,14,0,0,0,0,0,
    2,3,0,0,0,0,0,
    1,2,3,0,0,0,0,
    15,16,17,0,0,0,0,
    18,19,20,0,0,0,0,
    20,55,56,0,0,0,0,
    11,12,0,0,0,0,0,
    9,10,0,0,0,0,0,
    9,10,0,0,0,0,0,
    9,10,0,0,0,0,0,
    21,22,0,0,0,0,0,
    21,22,25,0,0,0,0,
    21,22,25,0,0,0,0,
    23,25,0,0,0,0,0,
    23,24,0,0,0,0,0,
    23,24,0,0,0,0,0,
    51,63,0,0,0,0,0,
    50,52,63,0,0,0,0,
    51,63,0,0,0,0,0,
    54,64,0,0,0,0,0,
    53,55,64,0,0,0,0,
    54,64,0,0,0,0,0,
    57,65,0,0,0,0,0,
    56,58,65,0,0,0,0,
    57,65,0,0,0,0,0,
    60,66,0,0,0,0,0,
    59,61,66,0,0,0,0,
    60,66,0,0,0,0,0,
    67,0,0,0,0,0,0,
    26,27,28,29,30,31,67,
    32,33,34,35,36,37,67,
    38,39,40,41,42,43,67,
    44,45,46,47,48,49,67,
    63,64,65,66,0,0,0,
    };

  clock_t start,finish;
  double totaltime;
  start=clock();

 /* CircuitFinder<5> CF(A);
  CF.run();*/
  CircuitFinder<19>CF2(B,25,42,0);
  CF2.run();
  
  finish=clock();
  totaltime = double(finish-start)/CLOCKS_PER_SEC;
  cout<<"此程序运行时间为："<<fixed<<setprecision(6)<<totaltime<<"秒！"<<endl;

  return 0;
}
