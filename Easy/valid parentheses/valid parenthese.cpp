class Solution{
public:
  bool isValid (string s){
    /* using stack container to store "(", "{", "["
     * scaning string from begin, if s[i] == ( or { or [, push it
     * into stack (which is on the top),
     * if s[i++] == ) and stack.top == (, stack.pop
     * else return false
     * The key question is keeping eye on stack!
     * in the final, stack should empty */
    stack<char> sk;
    for(int i = 0; i < s.size();i++){
      //stack push operation
      if(s[i]=='(' || s[i]=='[' ||s[i]=='{'){ sk.push(s[i]); }
      else {
        if(sk.empty()) { return false; }
        if ((s[i]==')' && sk.top()!= '(') || (s[i]=='}' && sk.top()!='{') || (s[i]==']' && sk.top()!='[')){ return false; }
        else{ sk.pop(); }
      }
    }
    return sk.empty();
  }
};