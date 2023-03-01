class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int lo = INT_MAX, hi = INT_MIN;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
            lo = min(lo, nums[i]);
            hi = max(hi, nums[i]);
        }

        int idx = 0;
        for (int num = lo; num <= hi; ++num)
            while (freq[num]--)
                nums[idx++] = num;
        
        return nums;
    }
};
