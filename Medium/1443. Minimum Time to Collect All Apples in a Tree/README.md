# Minimum Time to Collect All Apples in a Tree

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

<br>

## Video Solution: [Youtube Link](https://www.youtube.com/watch?v=hIVslN8zDco)

<br>

## code

```cpp
// C++

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        for (auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        return max(0, DFS(0, -1, tree, hasApple) - 2);
    }

    int DFS(int node, int parent, vector<vector<int>> &tree, vector<bool> &hasApple) {
        int time = 0;
        for (auto child : tree[node]) {
            if (child != parent)
                time += DFS(child, node, tree, hasApple);
        }

        return (time > 0 || hasApple[node] ? time + 2 : 0);
    }
};
```
