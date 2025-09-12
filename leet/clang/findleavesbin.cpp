//LeetCode No. 366
//Find Leaves of Binary Tree
class Solution {
    public:
        vector<vector<int>> findLeaves(TreeNode* root) {
            vector<vector<int>> ans;
            dfs(root, ans);
            return ans;
        };
        int dfs(TreeNode* node, vector<vector<int>>& ans) {
            if (!node)
                return -1;
            int leftH = dfs(node->left, ans);
            int rightH = dfs(node->right, ans);
            int currH = max(leftH, rightH) + 1;
    
            if (ans.size() <= currH) {
                ans.push_back({});
            }
            ans[currH].push_back(node->val);
    
            return currH;
        };
    };