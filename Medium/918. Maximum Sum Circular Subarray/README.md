# Maximum Sum Circular Subarray

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/maximum-sum-circular-subarray/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/0_a_FILr2eE)

<br>

## code

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;
        for (auto &num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
```
