class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(n << 1);
        int x = 0, y = n, idx = 0;
        
        while (idx < (n << 1)) {
            res[idx++] = nums[x++];
            res[idx++] = nums[y++];
        }

        return res;
    }
};
