/* Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's permutations is
 * the substring of the second string.  */

/* solution: check permutation subsequence!!!, window sliding hashmap checking!
 * map s1[char, frequency] **** */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      //corner case: s1 is empty string
      if(s1.empty()) { return true; }
      //corner case: s1.length > s2.length
      int n = s1.size(), m = s2.size();
      if(n > m) { return true; }

      unordered_map<char, int> map;//store target string currency info
      for(const auto& it : s1) {
        map[it]++;
      }

      //sliding window size = n
      for(int i = 0; i <= m - n; i++) {//start pointer range
        unordered_map<char, int> temp;
        int j = n + i - 1;//for each start pointer, the index of end pointer
        for(int k = i; k <= j; k++){
          temp[s2[k]]++;
        }
        if(temp == map) { return true; }//how to check two map equality?
      }
      return false;
    }
};

/* solution2: */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> m1(128), m2(128);
        for (int i = 0; i < n1; ++i) {
            ++m1[s1[i]]; ++m2[s2[i]];
        }
        if (m1 == m2) return true;
        for (int i = n1; i < n2; ++i) {
            ++m2[s2[i]];
            --m2[s2[i - n1]];
            if (m1 == m2) return true;
        }
        return false;
    }
};








