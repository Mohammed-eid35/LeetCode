class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        lo = hi = nums[0]
        freq = {}

        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            lo = min(lo, num)
            hi = max(hi, num)
        
        idx = 0
        for num in range(lo, hi + 1):
            while freq.get(num, 0) > 0:
                nums[idx] = num
                idx += 1
                freq[num] -= 1
        
        return nums
