class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n);
        for (auto &edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n);
        DFS(0, -1, ans, tree, labels);
        return ans;
    }

    vector<int> DFS(int node, int parent, vector<int> &ans, vector<vector<int>> &tree, string &label) {
        vector<int> ret(26);
        ret[label[node] - 'a']++;
        
        for (auto child : tree[node]) {
            if (child != parent) {
                auto childSubTree = DFS(child, node, ans, tree, label);
                for (int i = 0; i < 26; ++i)
                    ret [i] += childSubTree[i];
            }
        }

        ans[node] = ret[label[node] - 'a'];
        return ret;
    }
};
