# Restore IP Addresses

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/restore-ip-addresses/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/PFb5zPn0vvY)

<br>

## code

```cpp
class Solution {
private:
    int n;
    vector<string> validAddresses;
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        solve(0, 0, "", s);
        return validAddresses;
    }

    void solve(int idx, int numOfIntegers, string curAddress, string &s) {
        if (numOfIntegers > 4)
            return;
        
        if (numOfIntegers == 4 && idx == n) {
            curAddress.pop_back();
            validAddresses.push_back(curAddress);
            return;
        }

        for (int i = 1; i <= 3 && idx + i <= n; ++i) {
            string curInteger = s.substr(idx, i);
            
            if (curInteger[0] == '0' && i != 1)
                break;
            
            if (stoi(curInteger) <= 255)
                solve(idx + i, numOfIntegers + 1, curAddress + curInteger + ".", s);
        }
    }
};
```
