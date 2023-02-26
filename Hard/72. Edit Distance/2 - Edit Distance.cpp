class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int minDistance(string word1, string word2) {
        n = word1.size(), m = word2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        
        return solve(n, m, word1, word2);
    }
    
    int solve(int i, int j, string &str1, string &str2) {
        if (!i || !j) return i + j;
        
        int &ret = dp[i][j];
        if (~ret) return ret;
        
        if (str1[i - 1] == str2[j - 1])
            return ret = solve(i - 1, j - 1, str1, str2);

        return ret = 1 + min({
            solve(i, j - 1, str1, str2),    // insert
            solve(i - 1, j, str1, str2),    // delete
            solve(i - 1, j - 1, str1, str2) // replace
        });
    }
};
