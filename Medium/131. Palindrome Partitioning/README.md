# Palindrome Partitioning

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/palindrome-partitioning/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/9xtJz4R-2gw)

<br>

## code

```cpp
class Solution {
private:
    int n;
    vector<vector<string>> res;
    vector<string> cur;
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        solve(0, s);
        return res;
    }

    void solve(int idx, string &s) {
        if (idx == n) {
            res.push_back(cur);
            return;
        }

        string curPalindrome = "";
        for (int i = idx; i < n; ++i) {
            curPalindrome += s[i];

            if (isPalindrome(curPalindrome)) {
                cur.push_back(curPalindrome);
                solve(i + 1, s);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string &str) {
        int sz = str.size();
        for (int i = 0; i < sz / 2; ++i)
            if (str[i] != str[sz - i - 1])
                return false;

        return true;
    }
};
```
