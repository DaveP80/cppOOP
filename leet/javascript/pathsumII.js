//LeetCode No. 113 Path Sum II
//Medium
var pathSum = function(root, targetSum) {
    if (root === null) return [];
    const res = [];
    backtrack(root, targetSum, []);
    return res;
  
    function backtrack(root, sum, temp) {
      if (root === null) return;
      if (!root ?.left && !root ?.right && sum === root.val) {
        return res.push([...temp, root.val]);
      }
      temp.push(root.val);
      backtrack(root.left, sum - root.val, temp);
  
      backtrack(root.right, sum - root.val, temp);
      temp.pop();
    }
  };