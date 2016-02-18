//
//  main.cpp
//  第113题
//
//  Created by 张星宇 on 16/2/16.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

void findPath(TreeNode* root, int sum, vector<int> &row, vector<vector<int>> &result) {
    if (!root->left && !root->right) {
        if (sum == 0) {
            result.push_back(row);
        }
        return;
    }
    if (root->left) {
        row.push_back(root->left->val);
        findPath(root->left, sum - root->left->val, row, result);
        row.pop_back();
    }
    if (root->right) {
        row.push_back(root->right->val);
        findPath(root->right, sum - root->right->val, row, result);
        row.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    
    vector<int> row;
    row.push_back(root->val);
    findPath(root, sum - root->val, row, result);
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(2,1,2);
//    IntVector2DPrint(pathSum(root1, 1));
    TreeNode *root2 = TreeCreate(13, 5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1);
    TreePrint(root2);
    IntVector2DPrint(pathSum(root2, 22));
    return 0;
}
