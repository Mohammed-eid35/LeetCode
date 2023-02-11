class Solution {
private:
    const int OO = 0x3f3f3f3f;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>(n));
        for (auto &edge : redEdges)
            graph[edge[0]].push_back({edge[1], 0});
        
        for (auto &edge : blueEdges)
            graph[edge[0]].push_back({edge[1], 1});
        
        return BFS(0, n, graph);
    }

    vector<int> BFS(int src, int n, vector<vector<pair<int, int>>> &graph) {
        queue<vector<int>> qu;
        qu.push({src, 0, 0});
        qu.push({src, 0, 1});

        vector<int> dis(n, -1);
        dis[0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(2));

        while (!qu.empty()) {
            auto vc = qu.front();
            qu.pop();

            int node = vc[0], nodeDis = vc[1], nodeColor = vc[2];
            visited[node][nodeColor] = true;
            
            for (auto &[neighbor, neighborColor] : graph[node]) {
                if (!visited[neighbor][neighborColor] && nodeColor != neighborColor) {
                    if (dis[neighbor] == -1)
                        dis[neighbor] = nodeDis + 1;
                    
                    qu.push({neighbor, nodeDis + 1, neighborColor});
                }
            }
        }
        
        return dis;
    }
};
