class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> vc(n);
        for (int i = 0; i < n; ++i)
            vc[i] = {ages[i], scores[i]};
        
        sort(vc.begin(), vc.end());

        return highestScore(n, vc);
    }

    int highestScore(int n, vector<pair<int, int>> &vc) {
        int maxScore = 0;
        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = vc[i].second;
            
            for (int j = i - 1; j >= 0; --j) 
                if (vc[i].second >= vc[j].second)
                    dp[i] = max(dp[i], dp[j] + vc[i].second);
            
            maxScore = max(maxScore, dp[i]);
        }

        return maxScore;
    }
};
