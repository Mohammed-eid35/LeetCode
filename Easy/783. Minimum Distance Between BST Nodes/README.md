# Minimum Distance Between BST Nodes

<br>

## The Problem: [LeetCode Link](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

<br>

## Video Solution: [Youtube Link](https://youtu.be/rAPvpq61iB8)

<br>

## code - 1
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
private:
    vector<int> values;
public:
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        int n = values.size(), minDiff = INT_MAX;
        for (int i = 1; i < n; ++i)
            minDiff = min(minDiff, values[i] - values[i - 1]);
        
        return minDiff;
    }

    void inorderTraversal(TreeNode* root) {
        if (!root)
            return;
        
        inorderTraversal(root->left);
        values.push_back(root->val);
        inorderTraversal(root->right);
    }
};
```

## code - 2
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
private:
    int minDiff = INT_MAX;
    int preValue = -1;
public:
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);

        return minDiff;
    }

    void inorderTraversal(TreeNode* root) {
        if (!root)
            return;
        
        inorderTraversal(root->left);

        if (preValue != -1)
            minDiff = min(minDiff, root->val - preValue);
        
        preValue = root->val;
        
        inorderTraversal(root->right);
    }
};
```
