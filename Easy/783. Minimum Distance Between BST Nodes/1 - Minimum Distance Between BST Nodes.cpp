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
