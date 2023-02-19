# Binary Tree Zigzag Level Order Traversal

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/F9r-7SEdpCQ)

<br>

## code - C++

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode*> qu;
        qu.push(root);

        bool rightToLeft = false;
        
        while (!qu.empty()) {
            vector<int> curLevel;

            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                auto node = qu.front();
                qu.pop();
                
                curLevel.push_back(node->val);
                
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            }

            if (rightToLeft)
                reverse(curLevel.begin(), curLevel.end());
            
            rightToLeft = !rightToLeft;

            res.push_back(curLevel);
        }

        return res;
    }
};
```

# Code - JS
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
 * @return {number[][]}
 */
var zigzagLevelOrder = function(root) {
    if(!root) return [];

    const queue = [root], ret = [];
    let lvl = 0;
    while(queue.length) {
        const queueSize = queue.length;
        const level = [];

        for (let i = 0; i < queueSize; ++i) {
            const curNode = queue.shift();
            if (lvl & 1) level.unshift(curNode.val);
            else level.push(curNode.val);
            
            if (curNode.left) queue.push(curNode.left);
            if (curNode.right) queue.push(curNode.right);
        }
        
        ret.push(level)
        lvl++;
    }


    return ret;
};
```
