# Find Closest Node to Given Two Nodes

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/iO027dE7r34)

<br>

## code

```cpp
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto dis1 = BFS(node1, n, edges);
        auto dis2 = BFS(node2, n, edges);

        int node = -1, x = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (x > max(dis1[i], dis2[i])) {
                node = i;
                x = max(dis1[i], dis2[i]);
            }
        }

        return node;
    }

    vector<int> BFS(int src, int n, vector<int> &edges) {
        vector<int> dis(n, INT_MAX);
        queue<int> qu;
        qu.push(src);
        dis[src] = 0;

        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();

            if (edges[node] != -1 && dis[edges[node]] == INT_MAX) {
                qu.push(edges[node]);
                dis[edges[node]] = dis[node] + 1;
            }
        }

        return dis;
    }
};
```
