# Subarray Sums Divisible by K

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/szWfCyRsyAU)

<br>

## code

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq = {{0, 1}};

        int pre = 0, ans = 0;
        for (auto &num : nums) {
            pre = (pre + num % k + k) % k;
            ans += freq[pre];

            freq[pre]++;
        }

        return ans;
    }
};
```
