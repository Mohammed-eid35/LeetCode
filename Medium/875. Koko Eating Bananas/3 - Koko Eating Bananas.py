class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lo, hi, k = 1, max(piles), -1
        
        while lo <= hi:
            mid = lo + ((hi - lo) >> 1)

            if self.numOfHours(mid, piles) <= h:
                k = mid
                hi = mid - 1
            else:
                lo = mid + 1

        return k

    def numOfHours(self, k: int, piles: List[int]) -> int:
        totalHours = 0
        for pile in piles:
            totalHours += math.ceil(pile / k)

        return totalHours
