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
