# Invert Binary Tree

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/invert-binary-tree/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/goJ5L5OJV8M)

<br>

## Code - C++

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
```

## Code - JS
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    const swap = (node) => {
        if (!node)
            return;
        
        [node.left, node.right] = [node.right, node.left];
        
        swap(node.left);
        swap(node.right);
    };
  
    swap(root);
  
    return root;
};
```
