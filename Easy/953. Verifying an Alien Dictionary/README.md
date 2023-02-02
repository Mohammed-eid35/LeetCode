# Verifying an Alien Dictionary

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/verifying-an-alien-dictionary/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/bv9FCCnZbCw)

<br>

## code

```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> weight;
        for (int i = 0; i < 26; ++i)
            weight[order[i]] = i;
        
        int n = words.size();
        for (int i = 1; i < n; ++i)
            if (compare(words[i - 1], words[i], weight))
                return false;
        
        return true;
    }

    // return true if w1 > w2
    bool compare(string &w1, string &w2, unordered_map<char, int> &weight) {
        int sz = min(w1.size(), w2.size());
        for (int i = 0; i < sz; ++i)
            if (weight[w1[i]] != weight[w2[i]])
                return weight[w1[i]] > weight[w2[i]];
        
        return w1.size() > w2.size();
    }
};
```
