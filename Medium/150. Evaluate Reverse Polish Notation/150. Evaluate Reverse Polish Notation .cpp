/* 第一个出现的运算符，其前面必有两个数字，当这个运算符和之前两个数字完成运算后从原数组中删去，
 * 把得到一个新的数字插入到原来的位置，继续做相同运算，直至整个数组变为一个数字。*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int> s;
       for(const auto& str : tokens){
           if(str != "+" && str != "-" && str != "*" && str != "/") {
               s.push(stoi(str));
           }else {
               int a = s.top();
               s.pop();
               int b = s.top();
               s.pop();
               if(str == "+") { s.push(b+a); }//the order is important
               if(str == "-") { s.push(b-a); }
               if(str == "*") { s.push(b*a); }
               if(str == "/") { s.push(b/a); }
           }
       }
        return s.top();
    }
};