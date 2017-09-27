/* Given a string s, return all the palindromic permutations (without duplicates) of it.
 * Return an empty list if no palindromic permutation could be form.*/


/*solution: step1: can generate palindromes
 *          step2: get all palindromes: First half permutations, Second half reverse
 *                 two cases for step2:
                                        case1) all even frequency
                                        case2) one odd frequence            ***********/
class Solution {
public:
    vector<string> generatePalindromes(string s) {
      vector<string> res;
      if(s.empty()) { return res; }
      unordered_map<char, int> map;
      bool canPal = false;
      for(const auto& it : s) {
        map[it]++;
      }
      int count = 0;
      for(const auto& it : map) {
        if(it.second%2 == 1) {
          count++;
        }
      }
      canPal = count > 1? false : true;
      //finish step1
      if(!canPal) { return res;}

      //step2: two different cases
      string half = "", mid = "";
      for(const auto& it : map) {
        if(it.second%2 == 1) { mid += it.first; }
        half.append(it.second/2, it.first);//append count copies of char!
        if(mid.size() > 1) { return res; }
      }
      dfs(0, half, mid, res);
      return res;
    }
    void dfs(int start, string& half, string& mid, vector<string>& res) {
      if(start >= half.size()) {
        res.push_back(half + mid + string(half.rbegin(), half.rend()));
      }
      set<char> set;
      for(int i = start; i < half.size(); i++) {
        if(set.count(half[i]) == 0) {
          set.insert(half[i]);
          swap(half[start], half[i]);
          dfs(start+1, half, mid, res);
          swap(half[start], half[i]);
        }
      }
    }
};
//good coding
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        for (auto it : m) {
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return res;
    }
    void permute(string &t, int start, string mid, vector<string> &res) {
        if (start >= t.size()) {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        }
        set<char> set;
        for (int i = start; i < t.size(); ++i) {
            if(set.count(t[i]) == 0) {
                set.insert(t[i]);
                swap(t[i], t[start]);
                permute(t, start + 1, mid, res);
                swap(t[i], t[start]);
            }
        }
    }
};











