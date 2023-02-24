class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        mn = 2000000000
        pq = []
        
        for num in nums:
            if num & 1:
                num <<= 1
            
            mn = min(mn, num)
            heappush(pq, -num)

        res = 2000000000
        while True:
            mx = -heappop(pq)

            res = min(res, mx - mn)

            if mx & 1:
                break
            
            mn = min(mn, mx >> 1)
            heappush(pq, -(mx >> 1))

        return res
