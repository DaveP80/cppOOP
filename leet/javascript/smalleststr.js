//LeetCode No. 988
//Smallest String Starting From Leaf
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
 * @return {string}
 */
var smallestFromLeaf = function(root) {
    
    function dfs(root, x) {
        if (!root) {
            return 
        }
        x = String.fromCharCode(root.val+97) + x;
        if (root?.left && root?.right) {
            let a = dfs(root.left, x);
            let b = dfs(root.right, x);
            return a > b ? b : a;
        }
        if (root?.left) {
            return dfs(root.left, x)
        }
        if (root?.right) {
            return dfs(root.right, x)
        }
        return x
    }

    return dfs(root, "")
    
};