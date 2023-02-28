/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private HashMap<String, Integer> subTrees = new HashMap<>();
    private List<TreeNode> res = new ArrayList<>();

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        traverse(root);
        return res;
    }

    public String traverse(TreeNode root) {
        if (root == null)
            return "";

        String subTree = root.val + "#" + traverse(root.left) + "#" + traverse(root.right);

        subTrees.put(subTree, subTrees.getOrDefault(subTree, 0) + 1);

        if (subTrees.get(subTree) == 2)
            res.add(root);

        return subTree;
    }
}
