// solution - 1
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return new int[] {i, j};
                }
            }
        }
        return new int[] {};
    }
}



// solution - 2
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> idx = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            if (idx.containsKey(target - nums[i])) {
                return new int[] {idx.get(target - nums[i]), i};
            }
            
            idx.put(nums[i], i);
        }

        return new int[] {};
    }
}