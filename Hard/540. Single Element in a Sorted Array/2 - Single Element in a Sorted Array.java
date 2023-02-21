class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        int lo = 0, hi = n / 2, res = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int idx = mid * 2;

            if (idx + 1 >= n || nums[idx] != nums[idx + 1]) {
                res = nums[idx];
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return res;
    }
}
