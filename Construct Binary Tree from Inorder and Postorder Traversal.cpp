/*
	根据中序遍历和后序遍历还原树，和105题几乎一模一样，分析略
*/

TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int l, int r, int rp) {
    if (r < l) { return NULL; }
    
    int anchor = l;
    for (; anchor <= r; ++anchor) {
        if (postorder[rp] == inorder[anchor]) {
            break;
        }
    }
    
    TreeNode *root = new TreeNode(inorder[anchor]);
    root->left = buildTreeHelper(inorder, postorder, l, anchor - 1, rp - 1 - r + anchor);
    root->right = buildTreeHelper(inorder, postorder, anchor + 1, r, rp - 1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, inorder.size()-1);
}