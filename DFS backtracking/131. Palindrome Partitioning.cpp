class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sol;
        dfs(0, s, sol, res);
        return res;
    }

    void dfs(int start, string s, vector<string>& sol, vector<vector<string>>& res) {
        //stop condtion or acceptable condition
        if(start >= s.size()) {
            res.push_back(sol);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(ispal(s, start, i)){
                sol.push_back(s.substr(start, i-start+1));
                dfs(i+1, s, sol, res);
                sol.pop_back();
            }
        }
    }

    bool ispal(string s, int start, int end) {
        if(s.empty()) return true;
        int left = start, right = end;
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};