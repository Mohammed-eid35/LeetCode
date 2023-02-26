class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (!i || !j)
                    dp[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],    // insert
                        dp[i - 1][j],    // delete
                        dp[i - 1][j - 1] // replace
                    });
            }
        }

        return dp[n][m];
    }
};
