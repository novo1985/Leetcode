class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, string> map; //key: index, val: longest string starting from key.
        int n = s.size();
        for(int i = 0; i < n; i++){
            map[i] += s[i];
            int j = i+1;
            while(j < n){
                if (map[i].find(s[j]) == -1) {//new character
                   map[i] += s[j];
                   j++;
                }
                else break;

            }
        }
        int max = 0;
        for(const auto& it : map){
            if(it.second.size() > max){
                max = it.second.size();
            }
        }

        return max;
    }
};





