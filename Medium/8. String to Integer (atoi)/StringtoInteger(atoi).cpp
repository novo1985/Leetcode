#include <iostream>
#include <string>
using namespace std;

/* Implement atoi to convert a string to an integer. */

/* Analysis:
 * As there is no need to consider float number, what we need concern here is
 * 1. 跳过所有起始空格，找到第一个非空格字符c0
 * (a) c0非数字字符（包括\0）也非正负号，返回0。
 * (b) c0为+或-，若下一个字符c1为数字，用isNeg记录下正或负，并移到c1。否则返回0。
 * (c) c0为数字，则更新ret

 * 2. 经过1已经找到了第一个数字字符，以及结果的正负。此时只需要逐个扫描后面的数字字符，并更新ret即可。终止的条件有以下几个：
 * (a) 扫到一个非数字字符，包括\0和空格。返回ret
 * (b) ret已经超出int的范围，返回相应的INT_MIN/INT_MAX    ****************/

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int sign = 1, base = 0, i = 0, n = str.size();
        while (i < n && str[i] == ' ') ++i;
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};

class Solution{
public:
  int myAtoi(string str){
    bool isNeg = false;
    unsigned long long res = 0;
    //skip the leading space
    int n = str.size();
    while(i < n && str[i] == ' '){ i++; }
    if(isdigit(str))
  }
};

class Solution {
public:
    // 字符串转int，注意判断超出Int范围
    int myAtoi(string str) {
        if (str == "") return 0;
        // 去首尾空格
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);

        int i = 0, len = str.length(), sign = 1;
        while ( i < len && str[i] == ' ') i++;
        if (i == len) return 0;
        if (str[i] == '+') {
            sign = 1;
            i++;
        } else
            if (str[i] == '-') {
                sign = -1;
                i++;
            }
        // 转换结果可能超出int范围，使用long long作为转换后接收变量的类型
        long long ret = 0;
        for (; i < len; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            ret = ret * 10 + (str[i] - '0');
            if (ret > INT_MAX) break;
        }
        ret *= sign;
        if (ret > INT_MAX) return INT_MAX;
        if (ret < INT_MIN) return INT_MIN;
        return ret;
    }
};