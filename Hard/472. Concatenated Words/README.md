# Concatenated Words

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/concatenated-words/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/ARFt1KUt1RQ)

<br>

## code

```cpp
class Solution {
private:
    unordered_set<string> dictionary;
    unordered_map<string, int> dp;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dictionary = unordered_set(words.begin(), words.end());

        vector<string> res;
        for (auto &word : words)
            if (numOfConcatenatedWords(word) > 1)
                res.push_back(word);

        return res;
    }

    int numOfConcatenatedWords(string word) {
        if (word.empty()) return 0;
        if (dp.count(word)) return dp[word];

        string curPrefix = "";
        int sz = word.size(), maxNumOfWords = INT_MIN;
        for (int i = 0; i < sz; ++i) {
            curPrefix += word[i];
            
            if (dictionary.count(curPrefix))
                maxNumOfWords = max(
                    maxNumOfWords,
                    1 + numOfConcatenatedWords(word.substr(i + 1))
                );
        }

        return dp[word] = maxNumOfWords;
    }
};
```
