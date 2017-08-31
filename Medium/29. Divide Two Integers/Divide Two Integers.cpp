#include <bits/stdc++.h>
using namespace std;

/* Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.*/

/* 不能用乘除， 就只能用位操作， 左移divisor (2 * divisor)
 * 2~k * divisor <= divident < 2~k+1 * divisor
 * ===>  2~k <= res < 2~k+1    *********************/

class Solution {
public:
    int divide(int dividend, int divisor) {
      long long a = (dividend >= 0)? dividend : -(long long)dividend;//负数全部转化为正数, long 防止溢出
      long long b = (divisor >= 0)? divisor : -(long long)divisor;
      int res = 1;
      long long temp = b;
      while(a > b){
      int i = 1;
      for(i = 1; temp <= a; i++){
        temp = temp << 1;
      }//until i = k+1, now b = b * 2~k+1, which is greater than divident
      res = res << (i-1);
      a = a-temp;
      }
      //truth table: true ^ true = false; false ^ false = false
      //符号一致，则返回false；符号相反，则返回true！！！！
      return (dividend > 0 ^ divisor > 0) ? -res : res;
    }
};



//solution2
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return dividend>=0 ? INT_MAX : INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; //overflow problem

        bool isNeg = false;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) isNeg = true;
        unsigned long long dvd = abs((long long)dividend);
        unsigned long long dvs = abs((long long)divisor);
        unsigned long long dvs_original = dvs;

        int i = 0;
        while(dvs<<(i+1) <= dvd) i++;

        int res = 0;
        while(dvd>=dvs_original) {
            if(dvd >= dvs<<i) {
                dvd -= dvs<<i;
                res += (1<<i);
            }
            i--;
        }

        return isNeg ? 0-res : res;
    }
};






