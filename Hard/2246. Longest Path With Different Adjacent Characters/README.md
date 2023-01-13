# Longest Path With Different Adjacent Characters

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)

<br>

## Video Solution: [Youtube Link](https://www.youtube.com/watch?v=tQADaLkER2I)

<br>

## code

```cpp
// C++

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i)
            tree[parent[i]].push_back(i);
        
        int globalMax = 0;
        DFS(0, globalMax, tree, s);
        return globalMax;
    }

    int DFS(int node, int &globalMax, vector<vector<int>> &tree, string &s) {
        priority_queue<int, vector<int>, greater<int>> max2;
        max2.push(0); max2.push(0);

        for (auto &child : tree[node]) {
            int maxFromChild = DFS(child, globalMax, tree, s);
            
            if (s[child] != s[node]) {
                max2.push(maxFromChild);
                max2.pop();
            }
        }

        int secondMax = max2.top(); max2.pop();
        int firstMax  = max2.top(); max2.pop();
        globalMax = max(globalMax, 1 + firstMax + secondMax);

        return 1 + firstMax;
    }
};
```
