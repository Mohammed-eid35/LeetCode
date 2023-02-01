# Greatest Common Divisor of Strings

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/611hikvil4Y)

<br>

## code

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int sz = min(str1.size(), str2.size());
        string cur = "", divisor = "";
        for (int i = 0; i < sz; ++i) {
            cur += str1[i];

            if (isDivisor(cur, str1) && isDivisor(cur, str2))
                divisor = cur;
        }

        return divisor;
    }

    bool isDivisor(string &div, string &str) {
        string divisor = div;
        while (divisor.size() < str.size())
            divisor += div;
        
        return divisor == str;
    }
};
```
