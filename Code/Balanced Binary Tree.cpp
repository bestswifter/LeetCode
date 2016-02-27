/*
    题目分析：判断一棵树是不是平衡的

    解题思路：利用 后序遍历 的思想，一次性访问完所有节点。
*/

int isBalancedHelper(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int leftHeight = isBalancedHelper(root -> left);
    int rightHeight = isBalancedHelper(root ->right);
    
    if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1) {
        return -1;
    }
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return isBalancedHelper(root) != -1;
}