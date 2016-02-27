//
//  main.cpp
//  第110题
//
//  Created by 张星宇 on 16/2/27.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"
#include <math.h>

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

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(10, 1,2,3,4,5,INT_MAX,6,INT_MAX,INT_MAX,7);
    std::cout << isBalanced(root1) << endl;
    
    TreeNode *root2 = nullptr;
    std::cout << isBalanced(root2) << endl;
    
    
    TreeNode *root3 = TreeCreate(1, 1);
    std::cout << isBalanced(root3) << endl;
    
    TreeNode *root4 = TreeCreate(3, 1,INT_MAX, 2);
    std::cout << isBalanced(root4) << endl;
    
    TreeNode *root5 = TreeCreate(3, 1,INT_MAX, 2);
    std::cout << isBalanced(root5) << endl;
    return 0;
}
