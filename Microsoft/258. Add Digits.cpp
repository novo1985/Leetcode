/* Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?*/
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
/*1    1
  2    2
  3    3
  4    4
  5    5
  6    6
  7    7
  8    8
  9    9
  10    1
  11    2
  12    3
  13    4
  14    5
  15    6
  16    7
  17    8
  18    9
  19    1
  20    2   */




























