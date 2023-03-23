class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice, maxProfit = prices[0], 0
        
        for price in prices:
            minPrice = min(minPrice, price)
            maxProfit = max(maxProfit, price - minPrice)

        return maxProfit