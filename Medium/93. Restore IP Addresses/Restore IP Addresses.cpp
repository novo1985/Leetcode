#include <bits/stdc++.h>
using namespace std;

/* Given a string containing only digits, restore it by returning all possible valid IP address
 * combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)*/

/*
一个有效的IP地址由4个数字组成，每个数字在0-255之间。对于其中的2位数或3位数，不能以0开头。所以对于以s[i]开头的数字
有3种可能：

1. s[i]
2. s[i : i+1]，s[i] !=0时
3. s[i : i+2]，s[i] != 0，且s[i : i+2] <= 255

根据以上规律，对s从头开始进行DFS寻找4个数字即可。*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ipComb;
        vector<string> ipNum;
        findIPAddr(s, 0, ipNum, ipComb);
        return ipComb;
    }

    void findIPAddr(string &s, int index, vector<string> &ipNum, vector<string> &ipComb) {
        if(ipNum.size()==4) {
            if(index==s.size()) {
                string ipAddr = ipNum[0];
                for(int i=1; i<4; i++)
                    ipAddr += ("."+ipNum[i]);
                ipComb.push_back(ipAddr);
            }
            return;
        }

        string curNum;
        for(int i=index; i<s.size() && i<index+3; i++) {
            curNum.push_back(s[i]);
            if(isValidNum(curNum)) {
                ipNum.push_back(curNum);
                findIPAddr(s, i+1, ipNum, ipComb);
                ipNum.pop_back();
            }
        }
    }

    bool isValidNum(string s) {
        if(s.empty() || s.size()>3) return false;
        if(s[0]=='0' && s.size()!=1) return false;
        if(s.size()==3 && stoi(s)>255) return false;
        return true;
    }
};

//solution2:
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s, 4, "", res);
        return res;
    }
    void restore(string s, int k, string out, vector<string> &res) {
        if (k == 0) {
            if (s.empty()) res.push_back(out);
        }
        else {
            for (int i = 1; i <= 3; ++i) {
                if (s.size() >= i && isValid(s.substr(0, i))) {
                    if (k == 1) restore(s.substr(i), k - 1, out + s.substr(0, i), res);
                    else restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 0, "", res);
        return res;
    }
    void helper(string s, int n, string out, vector<string>& res) {
        if (n == 4) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int k = 1; k < 4; ++k) {
                if (s.size() < k) break;
                int val = atoi(s.substr(0, k).c_str());
                if (val > 255 || k != std::to_string(val).size()) continue;
                helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
            }
        }
    }
};
