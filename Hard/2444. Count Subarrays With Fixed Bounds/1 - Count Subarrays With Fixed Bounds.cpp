class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;
        int minPos = -1, maxPos = -1, leftBound = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if (nums[i] == minK) 
                minPos = i;
            
            if (nums[i] == maxK)
                maxPos = i;

            res += max(0, min(maxPos, minPos) - leftBound);
        }
        
        return res;
    }
};
