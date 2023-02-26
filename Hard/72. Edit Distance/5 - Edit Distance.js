/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    const n = word1.length, m = word2.length;
    const dp = new Array(n + 1).fill(0).map(item => new Array(m + 1).fill(0));

    for (let i = 0; i <= n; ++i) {
        for (let j = 0; j <= m; ++j) {
            if (!i || !j)
                dp[i][j] = i + j;
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + Math.min(
                    dp[i][j - 1],    // insert
                    dp[i - 1][j],    // delete
                    dp[i - 1][j - 1] // replace
                );
        }
    }

    return dp[n][m];
};
