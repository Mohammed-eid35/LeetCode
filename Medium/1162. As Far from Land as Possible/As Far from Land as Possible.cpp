class Solution {
private:
    const int OO = 0x3f3f3f3f;
    vector<int> dx = {0,  0, 1, -1};
    vector<int> dy = {1, -1, 0,  0};
    int n;

public:
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n));
        queue<pair<int, int>> qu;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = OO;
                if (grid[i][j]) {
                    qu.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!qu.empty()) {
            auto [i, j] = qu.front();
            qu.pop();
            
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (valid(x, y) && !grid[x][y] && dis[x][y] > dis[i][j] + 1) {
                    dis[x][y] = dis[i][j] + 1;
                    qu.push({x, y});
                }
            }
        }
        
        int mx = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dis[i][j] != OO && dis[i][j]) 
                    mx = max(mx, dis[i][j]);

        return mx;
    }
    
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};
