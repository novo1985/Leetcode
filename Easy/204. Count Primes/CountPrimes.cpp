#include <iostream>
using namespace std;

/* Count the number of prime numbers less than a non-negative number, n. */

class Solution {
public:
    int countPrimes(int n) {
      if(n<=2) { return 0; }
      int count = 0;
      vector<bool> numbers (n, true); // define all numbers are prime
      for(int i = 2; i < n; i++){
        if(numbers[i] == true){
          count++;
          for(int j = 2; i * j < n; j++){
            numbers[i*j] = false;
          }
        }
      }
      return count;
    }
};