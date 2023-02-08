# Jump Game II

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/jump-game-ii/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/m8guN8W-psk)

<br>

## code

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jumps = 0, left = 0, right = 0;

        while (right < n - 1) {
            int newRight = right + 1;
            for (int i = left; i <= right; ++i)
                newRight = max(newRight, i + nums[i]);
            
            left = right + 1;
            right = newRight;
            jumps++;
        }

        return jumps;
    }
};
```
