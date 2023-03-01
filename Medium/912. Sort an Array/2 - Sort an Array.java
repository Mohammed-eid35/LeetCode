class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        int lo = nums[0], hi = nums[0];
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            lo = Math.min(lo, nums[i]);
            hi = Math.max(hi, nums[i]);
        }

        int idx = 0;
        for (int num = lo; num <= hi; ++num) {
            while (freq.getOrDefault(num, 0) > 0) {
                nums[idx++] = num;
                freq.put(num, freq.get(num) - 1);
            }
        }
        
        return nums;
    }
}
