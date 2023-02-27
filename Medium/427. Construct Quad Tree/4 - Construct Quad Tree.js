/**
 * // Definition for a QuadTree node.
 * function Node(val,isLeaf,topLeft,topRight,bottomLeft,bottomRight) {
 *    this.val = val;
 *    this.isLeaf = isLeaf;
 *    this.topLeft = topLeft;
 *    this.topRight = topRight;
 *    this.bottomLeft = bottomLeft;
 *    this.bottomRight = bottomRight;
 * };
 */

/**
 * @param {number[][]} grid
 * @return {Node}
 */
var construct = function(grid) {
    return solve(0, 0, grid.length, grid);
};

const solve = (x, y, len, grid) => {
    if (isSameValue(x, y, len, grid))
        return new Node(grid[x][y], true);
    
    len >>= 1;

    return new Node(
        false,
        false,
        solve(x, y, len, grid),
        solve(x, y + len, len, grid),
        solve(x + len, y, len, grid),
        solve(x + len, y + len, len, grid)
    );
}

const isSameValue = (x, y, len, grid) => {
    for (let i = x; i < x + len; ++i)
        for (let j = y; j < y + len; ++j)
            if (grid[i][j] != grid[x][y])
                return false;
    
    return true;
}
