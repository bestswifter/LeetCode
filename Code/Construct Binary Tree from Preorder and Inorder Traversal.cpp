/*
	题目分析：

		根据前序遍历和中序遍历的结果还原树

	解题思路：

		前序遍历数组中最前面的元素是根节点，然后去中序遍历数组中找到这个节点。
		在中序数组中，这个节点前面的部分都是左子树，后面的部分都是右子树，因此可以递归处理
*/

/**
 *  根据前序遍历和中序遍历的结果还原树
 *
 *  @param preorder 前序遍历下的数组
 *  @param inorder  中序遍历下的数组
 *  @param l        中序遍历数组辅助的左边界
 *  @param r        中序遍历数组辅助的右边界
 *  @param rp       根节点在前序遍历数组中的下标
 *
 *  @return 数的根节点的指针
 */
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int l, int r, int rp) {
	// 其实下面这一段代码都可以被省略
    // if (r - l == 2 && preorder[rp] == inorder[l+1]) { // 三个数且根节点在中序遍历中排在第二个
    //     TreeNode *left = new TreeNode(inorder[l]);
    //     TreeNode *right = new TreeNode(inorder[r]);
    //     TreeNode *root = new TreeNode(inorder[l+1]);
    //     root->left = left;
    //     root->right = right;
    //     return root;
    // }
    // if (r - l == 1) {  // 两个数字
    //     TreeNode *root = new TreeNode(preorder[rp]);
    //     TreeNode *leaf = new TreeNode(preorder[rp+1]);
    //     if (preorder[rp] == inorder[l]) {
    //         root->right = leaf;
    //     }
    //     else {
    //         root->left = leaf;
    //     }
    //     return root;
    // }
    // if (r == l) {
    //     return new TreeNode(inorder[l]);
    // }
    if (r < l) {
        return NULL;
    }
    
    int anchor = l;
    for (; anchor <= r; ++anchor) {
        if (preorder[rp] == inorder[anchor]) {
            break;
        }
    }
    
    TreeNode *root = new TreeNode(inorder[anchor]);
    root->left = buildTreeHelper(preorder, inorder, l, anchor - 1, rp + 1);
    root->right = buildTreeHelper(preorder, inorder, anchor + 1, r, rp + 1 + anchor - l);
    return root;
}