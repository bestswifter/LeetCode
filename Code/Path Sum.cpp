/*
	题目分析：判断数组中是否存在一条路径，所有节点的和为sum

	解题思路：用sum减去当前节点的值，然后左右子树递归，直到遇到叶子节点。
*/

bool hasPathSum(TreeNode* root, int sum) {
    if (!root || (!root->left && !root->right)) {
        return root && sum == root->val;
    }
    return hasPathSum(root->left, sum- root->val) || hasPathSum(root->right, sum- root->val);
}