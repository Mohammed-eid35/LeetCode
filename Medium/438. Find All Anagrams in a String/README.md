# Find All Anagrams in a String

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/NW_KDyDHyVI)

<br>

## code

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int szs = s.size(), szp = p.size();
        if (szs < szp)
            return {};
        
        vector<int> frs(26), frp(26);
        for (int i = 0; i < szp; ++i) {
            frs[s[i] - 'a']++;
            frp[p[i] - 'a']++;
        }

        vector<int> res;
        for (int i = 0; i < szs - szp; ++i) {
            if (frs == frp)
                res.push_back(i);

            frs[s[i] - 'a']--;
            frs[s[i + szp] - 'a']++;
        }

        if (frs == frp)
            res.push_back(szs - szp);

        return res;
    }
};
```
