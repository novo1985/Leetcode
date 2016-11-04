#include <iostream>
#include <vector>
using namespace std;

//you are not allowed to use the operator + and -
class two_integer {
public:
  //two_integer() {}
  two_integer(int i, int j):input1(i),input2(j) {}

  int getSum(int a = input1, int b = input2) {
    if (b==0){ return a;}// condition for stopping recursion!(no case of 1 and 1 in the same position)
    int sum = a ^ b;
    int carry = (a & b) << 1; // & will find 1,1 bit and right shift 1 bit.
    a = sum;
    b = carry;
    return getSum(a, b);
  }

public:
  int input1;
  int input2;
};

int main() {
  two_integer test(1,2);
  cout << test.getSum(1,2);
  return 0;
}
