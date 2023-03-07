class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        lo, hi, res = 0, min(time) * totalTrips, 0
        while lo <= hi:
            mid = lo + (hi - lo) // 2

            if self.numOfTrips(mid, time) >= totalTrips:
                res = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return res

    def numOfTrips(self, curTime: int, time: List[int]) -> int:
        counter = 0
        for t in time:
            counter += curTime // t
        
        return counter
