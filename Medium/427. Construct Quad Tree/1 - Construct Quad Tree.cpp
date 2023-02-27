/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(0, 0, grid.size(), grid);
    }

    Node* solve(int x, int y, int len, vector<vector<int>>& grid) {
        if (isSameValue(x, y, len, grid))
            return new Node(grid[x][y], true);
        
        Node* root = new Node();
        len >>= 1;

        root->topLeft = solve(x, y, len, grid);
        root->topRight = solve(x, y + len, len, grid);
        root->bottomLeft = solve(x + len, y, len, grid);
        root->bottomRight = solve(x + len, y + len, len, grid);

        return root;
    }

    bool isSameValue(int x, int y, int len, vector<vector<int>>& grid) {
        for (int i = x; i < x + len; ++i)
            for (int j = y; j < y + len; ++j)
                if (grid[i][j] != grid[x][y])
                    return false;
        
        return true;
    }
};
