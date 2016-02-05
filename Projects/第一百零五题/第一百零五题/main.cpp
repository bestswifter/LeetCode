//
//  main.cpp
//  第一百零五题
//
//  Created by 张星宇 on 16/2/5.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    if (r - l == 2 && preorder[rp] == inorder[l+1]) { // 三个数且根节点在中序遍历中排在第二个
        TreeNode *left = new TreeNode(inorder[l]);
        TreeNode *right = new TreeNode(inorder[r]);
        TreeNode *root = new TreeNode(inorder[l+1]);
        root->left = left;
        root->right = right;
        return root;
    }
    if (r - l == 1) {  // 两个数字
        TreeNode *root = new TreeNode(preorder[rp]);
        TreeNode *leaf = new TreeNode(preorder[rp+1]);
        if (preorder[rp] == inorder[l]) {
            root->right = leaf;
        }
        else {
            root->left = leaf;
        }
        return root;
    }
    if (r == l) {
        return new TreeNode(inorder[l]);
    }
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


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeHelper(preorder, inorder, 0, inorder.size()-1, 0);
}

int main(int argc, const char * argv[]) {
//    vector<int> preorder = {1,2,4,7,3,5,6,8};
//    vector<int> inorder = {4,7,2,1,5,3,8,6};
//    vector<int> preorder = {4,1,2,3};
//    vector<int> inorder = {1,2,3,4};
    vector<int> preorder = {7,-10,-4,3,-1,2,-8,11};
    vector<int> inorder = {-4,-10,3,-1,7,11,-8,2};
    TreeNode *root = buildTree(preorder, inorder);
    if (root) {
        cout << root->val << endl;
    }

    return 0;
}
