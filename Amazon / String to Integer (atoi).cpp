class Solution{
public:
  int myAtoi(string str) {
    //if(!str.empty()) {return 0;}
    long res = 0;
    int sign = 1;
    int i = 0;
    //skip leading space
    while(str[i] == ' '){ i++; }

    //if leading char is non-digit nor sign, return 0
    if(!isdigit(str[i]) && str[i] != '+' && str[i] != '-') { return res; }

    //sign
    if(str[i] == '+' || str[i] == '-'){
      sign = str[i] == '-' ? -1 : 1;
      i++;
    }

    //
    while(isdigit(str[i])){
      res = res * 10 + (str[i] - '0');
      if(res*sign >= INT_MAX) { return INT_MAX; }
      if(res*sign <= INT_MIN) { return INT_MIN; }
      i++;
    }

    return res*sign;
  }
};

