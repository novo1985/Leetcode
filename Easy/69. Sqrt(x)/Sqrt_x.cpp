#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*Compute and return the square root of x.*/

class Solution {
public:
    int mySqrt(int x) {
      //由于求平方的结果会很大，可能会超过int的取值范围，所以我们都用long long来定义变量
        long long left = 0, right = (x / 2) + 1;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};