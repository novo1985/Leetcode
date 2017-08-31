#include <bits/stdc++.h>
using namespace std;

/* Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space. */

//O(n)
class Solution {
public:
    void reverseWords(string &s) {
        string ret;
        int j = s.size();
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]==' ')
                j = i;
            else if(i==0 || s[i-1]==' ') {
                if(!ret.empty()) ret.append(" ");
                ret.append(s.substr(i, j-i));
            }
        }
        s = ret;
    }
};
//
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
    }
};
//
class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
    }
};





