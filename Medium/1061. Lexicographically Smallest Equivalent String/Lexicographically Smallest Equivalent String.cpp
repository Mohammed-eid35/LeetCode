class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);

        int sz = s1.size();
        for (int i = 0; i < sz; ++i)
            merge(s1[i] - 'a', s2[i] - 'a', parent);
        
        string ret = "";
        for (auto &ch : baseStr)
            ret += (find(ch - 'a', parent) + 'a');
        
        return ret;
    }

    void merge(int u, int v, vector<int> &parent) {
        u = find(u, parent);
        v = find(v, parent);

        if (u != v)
            parent[max(u, v)] = min(u, v);
    }

    int find(int x, vector<int> &parent) {
        if (parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x], parent);
    }
};
