class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> idxs;
        
        for (int i = 0; i < n; ++i)
            idxs[arr[i]].push_back(i);
        
        return BFS(n, idxs, arr);
    }

    int BFS(int n, unordered_map<int, vector<int>>& idxs, vector<int>& arr) {
        queue<int> qu;
        qu.push(0);

        vector<bool> vis(n);
        vis[0] = true;

        int steps = 0;
        while (!qu.empty()) {
            int level = qu.size();
            while (level--) {
                int idx = qu.front();
                qu.pop();

                if (idx == n - 1) 
                    return steps;
                
                vector<int>& nxtIdxs = idxs[arr[idx]];
                nxtIdxs.push_back(idx - 1);
                nxtIdxs.push_back(idx + 1);

                for (int nxt : nxtIdxs) {
                    if (nxt >= 0 && nxt < n && !vis[nxt]) {
                        qu.push(nxt);
                        vis[nxt] = true;
                    }
                }

                nxtIdxs.clear();
            }

            steps++;
        }

        return -1;
    }
};
