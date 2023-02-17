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
