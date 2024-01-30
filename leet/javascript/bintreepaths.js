//Leetcode No. 257 Binary Tree Paths
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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {

    let stor = [];


    function dfs(rt, str) {
        if (!rt) return;
        if (!rt.left && !rt.right) {
            str += `${rt.val}`;
        stor.push(str);
        } else {
        str += `${rt.val}->`
        }
        dfs(rt.left, str);
        dfs(rt.right, str);
    }

    dfs(root, "");
    return stor;
};