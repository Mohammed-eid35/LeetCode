# Shuffle the Array

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/shuffle-the-array/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/rtq9T_cq_YQ)

<br>

## code

```cpp
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
```
