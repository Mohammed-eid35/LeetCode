// solution - 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int n = nums.size();
        for (int i = 1; i < n; ++i)
            if (nums[i - 1] == nums[i])
                return true;
        
        return false;
    }
};



// solution - 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num))
                return true;
            
            seen.insert(num);
        }

        return false;
    }
};