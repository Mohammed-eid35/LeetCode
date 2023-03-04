class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        n, res = len(nums), 0
        minPos = maxPos = leftBound = -1

        for i in range(n):
            if nums[i] < minK or nums[i] > maxK:
                leftBound = i
            
            if nums[i] == minK:
                minPos = i
            
            if nums[i] == maxK:
                maxPos = i

            res += max(0, min(maxPos, minPos) - leftBound)
                
        return res
