# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    subTrees = collections.Counter()
    res = []

    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.subTrees.clear()
        self.res.clear()

        self.traverse(root)
        return self.res
    
    def traverse(self, root):
        if not root:
            return ""

        subTree = str(root.val) + "#" + self.traverse(root.left) + "#" + self.traverse(root.right)

        self.subTrees[subTree] += 1

        if self.subTrees[subTree] == 2:
            self.res.append(root)

        return subTree
