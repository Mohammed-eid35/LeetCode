class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int dp[][] = new int[n + 1][m + 1];

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(
                        dp[i][j - 1],    // insert
                        dp[i - 1][j],    // delete
                        dp[i - 1][j - 1] // replace
                    );
            }
        }

        return dp[n][m];
    }

    public int min(int x, int y, int z) {
        return Math.min(x, Math.min(y, z));
    }
}
