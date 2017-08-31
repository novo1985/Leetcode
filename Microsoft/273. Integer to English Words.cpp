class Solution {
public:
    string numberToWords(int num) {
      vector<string> unit = {"", " Thousand", " Million", " Billion"};
      string res;
      int i = 0; //i ranges from 0 - 3
      while(num) {//num > 0
        if(num % 1000) {//num % 1000 > 0, which indicates num is bigger than 1000
          res = getword(num % 1000) + unit[i] + res;//getword deal with number [1,..999]
        }
        i++;
        num = num/1000;
      }
      return res.empty()? "Zero" : res.substr(1);
    }

    /* number [1,..999]
     * 1) how many hundreds?
     * 2) how many tens?
     * 3) how about 11 - 19?
     * 4) how many ones?*/
    string getword(int num) {
      vector<string> ones = {"", " One", " Two", " Three", " Four", " Five", " Six",
                                                                 " Seven", " Eight", " Nine"};//1-9
      vector<string> teen = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen",
                                                       " Seventeen", " Eighteen", " Nineteen"};//10-19
      vector<string> tens = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy",
                                                                        " Eighty", " Ninety"};//10-90
      string res;
      if(num > 99) {
        res += ones[num/100] + " Hundred";
      }
      num = num % 100;//if num < 100, doesn't change value
      if(num > 19){
        res += tens[num/10];
        num = num % 10;
        res += ones[num];
      }else if(num > 9 && num < 20) {
        res += teen[num%10];
      }else if(num <= 9){
          res += ones[num];
      }
      return res;
    }
};