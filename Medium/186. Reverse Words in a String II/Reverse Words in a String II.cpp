//time o(n), space o(1), c++ istringstream;
class Solution{
public:
  void reverseWords(string& s){
    istringstream in(s);
    string str;
    in >> str;
    s = str;
    while(in >> str) {
      s = s + " " + str;
    }
  }
};

//reverse each words, and then reverse whole string
class Solution{
public:
  void reverseWords(string& s) {
    int left = 0;//word start index;
    for(int i = 0; i <= s.size(); i++) {
      if(s[i] == ' ' || i == s.size()) {
        reverse(s, left, i-1);
        left = i+1;
      }
    }
    reverse(s, 0, s.size());
  }

  void reverse(string& s, int left, int right) {
    while(left < right){
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      left++;
      right--;
    }
  }
};