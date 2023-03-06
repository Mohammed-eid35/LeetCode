# solution - 1
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for num in arr:
            if num <= k:
                k += 1
            else:
                break

        return k


# solution - 2
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        lo, hi = 0, len(arr) - 1
        while lo <= hi:
            mid = lo + (hi - lo >> 1)
            
            if arr[mid] - mid - 1 < k:
                lo = mid + 1
            else:
                hi = mid - 1
        
        return lo + k
