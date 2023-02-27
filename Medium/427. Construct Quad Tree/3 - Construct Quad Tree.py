"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.solve(0, 0, len(grid), grid)
    
    def solve(self, x, y, len, grid):
        if self.isSameValue(x, y, len, grid):
            return Node(grid[x][y], True)
        
        root = Node()
        len >>= 1

        root.topLeft = self.solve(x, y, len, grid)
        root.topRight = self.solve(x, y + len, len, grid)
        root.bottomLeft = self.solve(x + len, y, len, grid)
        root.bottomRight = self.solve(x + len, y + len, len, grid)

        return root
    
    def isSameValue(self, x, y, len, grid):
        for i in range(x, x + len):
            for j in range(y, y + len):
                if grid[i][j] != grid[x][y]:
                    return False
        
        return True
