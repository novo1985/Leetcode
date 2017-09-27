/* The set [1,2,3,…,n] contains a total of n! unique permutations.
 * Given n and k, return the kth permutation sequence. */

//backtracking time limited!!!
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> res;
        string sol;
        vector<bool> visited(n, false);
        dfs(sol, res, visited, n, k);
        return res[k-1];
    }
    void dfs(string& sol, vector<string>& res, vector<bool>& visited, int n, int k) {
        if(res.size() == k) { return; }

        if(sol.size() == n) {
            res.push_back(sol);
        }

        for(int i = 1; i <= n; i++) {
            if(visited[i] == true) { continue; }
            visited[i] = true;
            sol.push_back(i + '0');
            dfs(sol, res, visited, n, k);
            sol.pop_back();
            visited[i] = false;
        }
    }
};

//







