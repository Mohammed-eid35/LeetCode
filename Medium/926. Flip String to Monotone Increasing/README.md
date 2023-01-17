# Flip String to Monotone Increasing

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/o3o_cr3gQ3w)

<br>

## code

```cpp
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int numOfFlips = 0;
        for (auto &c : s)
            numOfFlips += (c == '0');
        
        int minFlips = numOfFlips;
        for (auto &c : s) {
            if (c == '0')
                minFlips = min(minFlips, --numOfFlips);
            else
                ++numOfFlips;
        }

        return minFlips;
    }
};
```
