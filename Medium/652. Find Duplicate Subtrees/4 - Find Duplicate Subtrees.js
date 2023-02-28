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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function(root) {
    const subTrees = {}, res = [];

    const traverse = root => {
        if (!root)
            return "";

        const subTree = root.val + "#" + traverse(root.left) + "#" + traverse(root.right);

        subTrees[subTree] = subTrees[subTree] + 1 || 1;

        if (subTrees[subTree] == 2)
            res.push(root);

        return subTree;
    };

    traverse(root);
    return res;
};
