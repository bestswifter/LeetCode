//
//  main.cpp
//  第一百零六题
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

int main(int argc, const char * argv[]) {
    
    vector<int> inorder = {4,7,2,1,5,3,8,6};
    vector<int> postorder = {7,4,2,5,8,6,3,1};
    
    TreeNode *root = buildTree(inorder, postorder);
    if (root) {
        cout << root->val << endl;
    }
    return 0;
}
