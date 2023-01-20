class Solution {
private:
    int n;
    vector<int> cur;
    set<vector<int>> subsequences;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);
        return vector(subsequences.begin(), subsequences.end());
    }

    void solve(int idx, vector<int> &nums) {
        if (idx == n) {
            if (cur.size() > 1)
                subsequences.insert(cur);
            
            return;
        }

        if (cur.empty() || cur.back() <= nums[idx]) {
            cur.push_back(nums[idx]);
            solve(idx + 1, nums);
            cur.pop_back();
        }

        solve(idx + 1, nums);
    }
};
