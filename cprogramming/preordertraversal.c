//LeetCode No. 144
//return array (pointer) of the integer node values in a binary tree.
void traverse(struct TreeNode* root, int* result, int* idx);
int num_elems(struct TreeNode* root)
{
    return root?1+num_elems(root->left)+num_elems(root->right):0;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = num_elems(root);
int *arr = (int*)calloc(*returnSize, sizeof(int)), idx=0;
    traverse(root, arr, &idx);

    return arr;
}

void traverse(struct TreeNode* root, int* result, int* idx) {
    if (root) {
        if (result) {
            result[(*idx)++] = root->val;
        }
        traverse(root->left, result, idx);
        traverse(root->right, result, idx);
    }
}