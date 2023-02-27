/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        return solve(0, 0, grid.length, grid);
    }

    public Node solve(int x, int y, int len, int[][] grid) {
        if (isSameValue(x, y, len, grid))
            return new Node(grid[x][y] == 1, true);
        
        Node root = new Node();
        len >>= 1;

        root.topLeft = solve(x, y, len, grid);
        root.topRight = solve(x, y + len, len, grid);
        root.bottomLeft = solve(x + len, y, len, grid);
        root.bottomRight = solve(x + len, y + len, len, grid);

        return root;
    }

    public boolean isSameValue(int x, int y, int len, int[][] grid) {
        for (int i = x; i < x + len; ++i)
            for (int j = y; j < y + len; ++j)
                if (grid[i][j] != grid[x][y])
                    return false;
        
        return true;
    }
}
