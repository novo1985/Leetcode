#include <bits/stdc++.h>
using namespace std;

/* Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/./b/../c/", => "/a/c"
path = "/a/./b/c/", => "/a/b/c"
path = "/home//foo/", => "/home/foo"  ****************************/


/*solution1:
[解题思路]
利用栈的特性，如果sub string element
1. 等于“/”，跳过，直接开始寻找下一个element
2. 等于“.”，什么都不需要干，直接开始寻找下一个element
3. 等于“..”，弹出栈顶元素，寻找下一个element
4. 等于其他，插入当前elemnt为新的栈顶，寻找下一个element*/
class Solution {
public:
    string simplifyPath(string path) {
      vector<string> stack;
      assert(path[0] == '/'); // make sure the first char of path is '/'
      int i = 0;
      while(i < path.size()){
        while(path[i] == '/' && i < path.size()) { i++; } //skip duplicate '/'
        if(i == path.size()) { break; }
        int start = i; //
        while(path[i] != '/' && i < path.size()) { i++; }// find the first directory
        int end = i-1;
        string dir = path.substr(start, end - start + 1);
        if(dir == ".."){
          if(!stack.empty()){ stack.pop_back();}
        }
        else if(dir != ".") {stack.push_back(dir);}
      }//while loop, it will iterate all index i [0, path.size()-1]
      if(stack.empty()) { return "/";} // empty path;
      string simpath;
      for(int i = 0; i < stack.size(); i++){
        simpath += "/" + stack[i];
      }
      return simpath;
    }
};

/*solution2: stringstream */
class Solution {
public:
    string simplifyPath(string path) {
      string res, t;
      stringstream ss(path);
      vector<string> v;
      while(getline(ss, t, '/')){
        if(t == "" || t == ".") { continue; }
        if(t == ".." && !v.empty()) { v.pop_back(); }
        else if(t != ".."){ v.push_back(t);}
      }
      for(string s : v){ res += "/" + s; }
      return res.empty()? "/" : res;
    }
};











