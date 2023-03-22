// solution - 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (nums[i] + nums[j] == target)
                    return {i, j};

        return {};
    }
};



// solution - 2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        const int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (idx.count(target - nums[i]))
                return {idx[target - nums[i]], i};
            
            idx[nums[i]] = i;
        }

        return {};
    }
};