# Naming a Company

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/naming-a-company/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/LJG_o25WVWM)

<br>

## code

```cpp
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> groups(26);
        for (auto &idea : ideas)
            groups[idea[0] - 'a'].insert(idea.substr(1));
        
        long long numOfNames = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int numOfSuffixes = 0;
                for (auto &idea : groups[i])
                    numOfSuffixes += groups[j].count(idea);
                
                numOfNames += 2LL * (groups[i].size() - numOfSuffixes) * (groups[j].size() - numOfSuffixes);
            }
        }

        return numOfNames;
    }
};
```
