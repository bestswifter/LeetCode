//
//  main.cpp
//  第112题
//
//  Created by 张星宇 on 16/2/16.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

bool hasPathSum(TreeNode* root, int sum) {
    if (!root || (!root->left && !root->right)) {
        return root && sum == root->val;
    }
    return hasPathSum(root->left, sum- root->val) || hasPathSum(root->right, sum- root->val);
}

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(2,1,2);
    std::cout << hasPathSum(root1, 1) << std::endl;
    
    TreeNode *root2 = TreeCreate(15,5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1);
    std::cout << hasPathSum(root2, 22) << std::endl;
    return 0;
}
