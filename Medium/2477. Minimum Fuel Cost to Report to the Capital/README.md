# Minimum Fuel Cost to Report to the Capital

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/Gq6HHNT3eg4)

<br>

## code

```cpp
class Solution {
private:
    long long numOfLiters = 0;
    vector<vector<int>> graph;
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        graph = vector<vector<int>> (n + 1);

        for (auto &road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        DFS(0, -1, seats);

        return numOfLiters;
    }

    int DFS(int node, int parent, int seats) {
        int representatives = 1;

        for (auto child : graph[node])
            if (child != parent)
                representatives += DFS(child, node, seats);
        
        if (node != 0)
            numOfLiters += (representatives + seats - 1) / seats;
        
        return representatives;
    }
};
```
