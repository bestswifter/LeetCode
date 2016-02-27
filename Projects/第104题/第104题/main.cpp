//
//  main.cpp
//  第104题
//
//  Created by 张星宇 on 16/2/27.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

using namespace std;

int maxDepth(TreeNode* root) {
    if (!root) { return 0; }
    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(10, 1,2,3,4,5,INT_MAX,6,INT_MAX,INT_MAX,7);
    std::cout << maxDepth(root1) << endl;
    
    TreeNode *root2 = nullptr;
    std::cout << maxDepth(root2) << endl;
    
    
    TreeNode *root3 = TreeCreate(1, 1);
    std::cout << maxDepth(root3) << endl;
    
    TreeNode *root4 = TreeCreate(3, 1,INT_MAX, 2);
    std::cout << maxDepth(root4) << endl;
    return 0;
}
