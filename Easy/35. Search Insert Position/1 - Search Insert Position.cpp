class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] <= target)
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    }
};
