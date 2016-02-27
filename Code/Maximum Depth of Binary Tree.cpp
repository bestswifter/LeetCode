/*
	题目分析：求二叉树的深度

	解题思路：递归左右子树。。。
*/

int maxDepth(TreeNode* root) {
    if (!root) { return 0; }
    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}