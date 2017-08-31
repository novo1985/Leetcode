#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * string convert(string text, int nRows);          ********/

class Solution {
public:
    string convert(string s, int numRows) {
      if(s.empty()) { return "";}
      if(numRows == 1) { return s; }
      //vector<vector<char>> res(numRows, vector<char>());
      //vector<vector<char>> res{numRows, vector<char>{}};
      string convert_str;
      int interval = 2 * numRows - 2; // for res[0] and res[numRows-1]
      // first vector<char> res[0]
      for(int i = 0; i < s.size(); i += interval){
          //res[0].push_back(s[i]);
          convert_str.push_back(s[i]);
      }
      // middle vector<char> res[1,..,numRows-2]
      for(int i = 1; i < numRows-1; i++){
        // interval-2*i, 2*i, interval-2*i, 2*i,...
        int distance = 2*i;
        for(int j = i; j < s.size(); j += distance){
          //res[i].push_back(s[j]);
          convert_str.push_back(s[j]);
          distance = interval - distance;
        }
      }
      //last vector<char> res[numRows-1]
      for(int i = numRows-1; i < s.size(); i += interval){
        //res[numRows-1].push_back(s[i]);
        convert_str.push_back(s[i]);
      }
      //output string
      return convert_str;
    }
};

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1)return s;
        int len = s.size(), k = 0, interval = (nRows<<1)-2;
        string res(len, ' ');
        for(int j = 0; j < len ; j += interval)//处理第一行
            res[k++] = s[j];
        for(int i = 1; i < nRows-1; i++)//处理中间行
        {
            int inter = (i<<1);
            for(int j = i; j < len; j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        for(int j = nRows-1; j < len ; j += interval)//处理最后一行
            res[k++] = s[j];
        return res;
    }
};