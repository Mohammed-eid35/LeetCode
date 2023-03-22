# solution - 1
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        
        return []



# solution - 2
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx = {}
        
        for i, num in enumerate(nums):
            if target - num in idx:
                return [idx[target - num], i]
            idx[num] = i
        
        return []