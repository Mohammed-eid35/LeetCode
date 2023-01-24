class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<pair<int, int>> idxs(n * n + 1);
        int idx = 1;
        
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0);
        
        for (int row = n - 1; row >= 0; --row) {
            for (auto col : cols)
                idxs[idx++] = {row, col};
            
            reverse(cols.begin(), cols.end());
        }

        return BFS(n, idxs, board);
    }

    int BFS(int n, vector<pair<int, int>> &idxs, vector<vector<int>> &board) {
        vector<int> dis(n * n + 1, -1);

        queue<int> qu;
        dis[1] = 0;
        qu.push(1);

        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();

            int m = min(cur + 6, n * n);
            for (int cell = cur + 1; cell <= m; ++cell) {
                auto [row, col] = idxs[cell];
                int nxt = board[row][col] != -1 ? board[row][col] : cell;

                if (dis[nxt] == -1) {
                    dis[nxt] = dis[cur] + 1;
                    qu.push(nxt);
                }
            }
        }

        return dis[n * n];
    }
};
