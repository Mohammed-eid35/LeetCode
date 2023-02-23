class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)
        
        projects = [(capital[i], profits[i]) for i in range(n)]
        projects.sort()

        maxProfit = []
        idx = 0
        for _ in range(k):
            while idx < n and projects[idx][0] <= w:
                heappush(maxProfit, -projects[idx][1])
                idx += 1

            if not maxProfit:
                break
            
            w -= heappop(maxProfit)

        return w;
