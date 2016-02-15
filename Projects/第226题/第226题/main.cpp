//
//  main.cpp
//  第226题
//
//  Created by 张星宇 on 16/2/15.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

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

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(7, 4,2,7,1,3,6,9);
    TreePrint(invertTree(root1));
    
    TreeNode *root2 = TreeCreate(6, 4,2,7,1,INT_MAX,6);
    TreePrint(invertTree(root2));
    return 0;
}
