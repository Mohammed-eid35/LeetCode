class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], maxProfit = 0;
        
        for (int &price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
