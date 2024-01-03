#LeetCode No. 110
# Given a binary tree, determine if it is 
# height-balanced.
# Input: root = [3,9,20,null,null,15,7]
# Output: true
# Definition for a binary tree node.

# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        def dfs(root):
            if not root: return [True, 0]
            print('root val', root.val)

            leftval = dfs(root.left)
            rightval = dfs(root.right)
            balanced = (leftval[0] and rightval[0] and abs(leftval[1] - rightval[1])           <= 1)
            print('level ', 1+max(leftval[1], rightval[1]))
            return [balanced, 1+max(leftval[1], rightval[1])]
        return dfs(root)[0]