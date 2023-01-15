# 2421. Number of Good Paths

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/number-of-good-paths/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/ShcXjwJhM0k)

<br>

## code

```cpp
class Solution {
private:
    struct DSU {
        vector<int> par, sz;
        int cnt;

        void init(int n) {
            par = vector<int>(n);
            iota(par.begin(), par.end(), 0);

            sz = vector<int>(n, 1);
            cnt = n;
        }

        int find(int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]);
        }

        void merge(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return;

            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
            cnt--;
        }
    };
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        vector<vector<int>> tree(n);
        for (auto &edge : edges) {
            if (vals[edge[0]] >= vals[edge[1]])
                tree[edge[0]].push_back(edge[1]);
            else
                tree[edge[1]].push_back(edge[0]);
        }
        
        map<int, vector<int>> nodesHasSameValue;
        for (int i = 0; i < n; ++i)
            nodesHasSameValue[vals[i]].push_back(i);

        DSU dsu;
        dsu.init(n);
        
        int numOfPathes = 0;
        for (auto &[value, nodes] : nodesHasSameValue) {
            for (auto &node : nodes)
                for (auto &child : tree[node])
                    dsu.merge(node, child);
            
            unordered_map<int, int> component;
            for (auto &node : nodes)
                component[dsu.find(node)]++;
            
            numOfPathes += nodes.size();
            
            for (auto &[xx, cnt] : component)
                numOfPathes += cnt * (cnt - 1) / 2;
        }

        return numOfPathes;
    }
};
```
