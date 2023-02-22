class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        lo, hi, res = max(weights), sum(weights), 0
        while lo <= hi:
            mid = lo + (hi - lo >> 1)
            
            if self.numOfDaysNeeded(mid, weights) <= days:
                res = mid
                hi = mid - 1
            else:
                lo = mid + 1;
        
        return res


    def numOfDaysNeeded(self, capacity, weights):
        days, curCapacity= 1, 0
        for weight in weights:
            if curCapacity + weight > capacity:
                days += 1
                curCapacity = 0

            curCapacity += weight

        return days
