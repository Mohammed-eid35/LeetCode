# Permutation in String

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/permutation-in-string/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/p_EmtOlPL6o)

<br>

## code

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        if (sz1 > sz2)
            return false;
        
        vector<int> fr1(26), fr2(26);
        for (int i = 0; i < sz1; ++i) {
            fr1[s1[i] - 'a']++;
            fr2[s2[i] - 'a']++;
        }

        for (int i = 0; i < sz2 - sz1; ++i) {
            if (isPermutation(fr1, fr2))
                return true;
            
            fr2[s2[i] - 'a']--;
            fr2[s2[i + sz1] - 'a']++;
        }

        return isPermutation(fr1, fr2);
    }

    bool isPermutation(vector<int> &fr1, vector<int> &fr2) {
        for (int i = 0; i < 26; ++i)
            if (fr1[i] != fr2[i])
                return false;
        
        return true;
    }
};
```
