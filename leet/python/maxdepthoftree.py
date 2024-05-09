# LeetCode No. 104 Maximum depth of binary tree
class Solution(object):
    def maxDepth(self, root):

        if root is None:
            return 0

        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)

        return max(left_depth, right_depth) + 1