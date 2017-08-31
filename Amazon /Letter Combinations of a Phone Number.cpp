#include <bits/stdc++.h>
using namespace std;

/* Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons)

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) { return res; }
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string out;
        DFSsearch(digits, 0, out, res, dict);
        return res;
    }

    void DFSsearch(string& digits, int index, string out, vector<string>& res, string dict[]){
        // DFS ending condition index beyond the size
        if(index == digits.size()){ res.push_back(out); }
        else{
            string temp = dict[digits[index] - '0'];//index of dict need [char to int];
            for(int i = 0; i < temp.size(); i++){
                out.push_back(temp[i]);
                DFSsearch(digits, index+1, out, res, dict);
                out.pop_back();
            }
        }
    }
};