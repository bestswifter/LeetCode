//
//  main.cpp
//  第98题
//
//  Created by 张星宇 on 16/2/16.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

void buildVector(TreeNode *root, vector<int> &v) {
    if (!root) {
        return ;
    }
    v.push_back(root->val);
    buildVector(root->left, v);
    buildVector(root->right, v);
}

bool inorder(TreeNode *root, vector<int> &v, bool &flag) {
    if (!root) {
        return true;
    }
    inorder(root->left,v, flag);
    v.push_back(root->val);
    if (v.size() > 1 && v[v.size()-2] >= root->val) {
        flag = false;
    }
    inorder(root->right,v, flag);
    return flag;
}

//bool isValidBST(TreeNode* root) {
//    if (!root) {
//        return true;
//    }
//    if (root->left) {
//        vector<int> temp;
//        buildVector(root->left, temp);
//        for (int i = 0; i < temp.size(); ++i) {
//            if (temp[i] >= root->val) {
//                return false;
//            }
//        }
//    }
//    if (root->right) {
//        vector<int> temp;
//        buildVector(root->right, temp);
//        for (int i = 0; i < temp.size(); ++i) {
//            if (temp[i] <= root->val) {
//                return false;
//            }
//        }
//    }
//    return isValidBST(root->left) && isValidBST(root->right);
//}

bool isValidBST(TreeNode* root) {
    vector<int> temp;
    bool flag = true;
    return inorder(root, temp, flag);
}

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(9, 1,2,3,INT_MAX,INT_MAX,4,INT_MAX,INT_MAX,5);
    std::cout << isValidBST(root1) << std::endl;
    
    TreeNode *root2 = TreeCreate(7, 8,6,10,5,7,9,11);
    std::cout << isValidBST(root2) << std::endl;
    
    TreeNode *root3 = TreeCreate(7, 10,5,15,INT_MAX,INT_MAX,6,20);
    std::cout << isValidBST(root3) << std::endl;

    return 0;
}
