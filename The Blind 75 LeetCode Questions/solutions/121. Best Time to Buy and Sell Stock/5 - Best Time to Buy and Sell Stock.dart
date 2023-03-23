class Solution {
    int maxProfit(List<int> prices) {
        int minPrice = prices[0], maxProfit = 0;

        for (int price in prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
}