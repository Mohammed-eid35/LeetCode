class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);

        for (int i = 0; i < n; ++i)
            projects[i] = {capital[i], profits[i]};
        
        sort(projects.rbegin(), projects.rend());

        priority_queue<int> maxProfit;
        while (k--) {
            while (!projects.empty() && projects.back().first <= w) {
                maxProfit.push(projects.back().second);
                projects.pop_back();
            }

            if (maxProfit.empty())
                break;
            
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
