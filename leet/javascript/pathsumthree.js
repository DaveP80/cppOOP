//LeetCode No. 437
//Return all paths to target sum that exists in a binary tree
//Average time complexity 0(n^2)
//Best case balanced tree 0(n logn)
var pathSum = function(root, targetSum) {
    let ans = 0;

    function dfs(root, currSum) {
        if (!root) {
            return;
        }

        ans += callback(root, currSum, targetSum);

        dfs(root.left, currSum);
        dfs(root.right, currSum);
    }

    function callback(node, currSum, targetSum) {
        if (!node) {
            return 0;
        }

        currSum += node.val;

        let totalPaths = currSum === targetSum ? 1 : 0;

        totalPaths += callback(node.left, currSum, targetSum);
        totalPaths += callback(node.right, currSum, targetSum);

        return totalPaths;
    }

    dfs(root, 0);

    return ans;
};