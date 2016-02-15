/*
	题目分析：求一个二叉树的镜像

	解题思路：只要交换root的左右子节点，然后递归调用即可。
*/

TreeNode* invertTree(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return root;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}