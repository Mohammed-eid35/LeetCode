# Maximum Depth of Binary Tree

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/on_-LAV20L4)

<br>

## code

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```
