#include <iostream>
using namespace std;

/* Given an integer n, return the number of trailing zeroes in n */

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        long p = 5;
        int res = 0;
        while (p <= n){
            res += n/p;
            p = p*5;
        }
        return res;
    }
};