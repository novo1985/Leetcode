/* Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.*/

//solution1: calculate frequence, two case: one odd || all even
class Solution {
public:
    bool canPermutePalindrome(string s) {
      //corner case: s is empty
      if(s.empty()) { return true; }

      unordered_map<char, int> map;
      for(const auto& it : s) {
        map[it]++;
      }

      //check frequency
      int count = 0;
      for(const auto& it : map) {
        if(it.second%2 == 1) { count++; }
      }
      if(count > 1) { return false; }
      else{
        return true;
      }
    }
};


//这种方法用到了一个set，我们遍历字符串，如果某个字母不在set中，我们加入这个字母，如果字母已经存在，我们删除该字母，
//那么最终如果set中没有字母或是只有一个字母时，说明是回文串
class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> t;
        for (auto a : s) {
            if (t.find(a) == t.end()) t.insert(a);
            else t.erase(a);
        }
        return t.empty() || t.size() == 1;
    }
};


