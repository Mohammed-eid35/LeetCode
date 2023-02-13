# Count Odd Numbers in an Interval Range 

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/ze_-jOFHcBw)

<br>

## code

```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return ((high + 1) >> 1) - (low >> 1);
    }
};
```
