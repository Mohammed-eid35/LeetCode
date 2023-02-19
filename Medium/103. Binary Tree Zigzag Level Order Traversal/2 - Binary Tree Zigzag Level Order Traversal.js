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
