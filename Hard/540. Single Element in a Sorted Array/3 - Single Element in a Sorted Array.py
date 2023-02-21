class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums);
        lo, hi, res = 0, n // 2, -1
        
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            idx = mid * 2

            if idx + 1 >= n or nums[idx] != nums[idx + 1]:
                res = nums[idx];
                hi = mid - 1
            else:
                lo = mid + 1

        return res
