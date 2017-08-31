class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) { return 0; }
        int res = 0;
        //create a map
        unordered_map<char, int> map;
        int val = 1;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            map[ch] = val++;
        }
        // s[i] * 26^index
        int index = 0;
        for(auto it = s.rbegin(); it != s.rend(); it++){
            res += map[*it] * pow(26, index);
            index++;
        }
        return res;
    }
};

//
class Solution{
public:
    int titleToNumber(string s) {
        if(s.empty()) { return 0; }
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res += (s.at(i) - 'A' + 1) * pow(26, s.size()-1-i);
        }
        return res;
    }
};