# Add to Array-Form of Integer

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/add-to-array-form-of-integer/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/Xj3bzE7wcLo)

<br>

## code

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        for (int i = n - 1; i >= 0; --i) {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10; 
        }

        while (k) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }

        return num;
    }
};
```
