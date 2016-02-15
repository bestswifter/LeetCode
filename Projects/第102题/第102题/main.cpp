//
//  main.cpp
//  第102题
//
//  Created by 张星宇 on 16/2/15.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

//vector<vector<int>> levelOrder(TreeNode* root) {
//    vector<vector<int>> result;
//    if (!root) {
//        return result;
//    }
//    queue<TreeNode*> nums1,nums2;
//    nums1.push(root);
//    
//    while (!nums1.empty() || !nums2.empty()) {
//        vector<int> row;
//        if (!nums1.empty()) {
//            while (!nums1.empty()) {
//                row.push_back(nums1.front()->val);
//                if (nums1.front()->left) {
//                    nums2.push(nums1.front()->left);
//                }
//                if (nums1.front()->right) {
//                    nums2.push(nums1.front()->right);
//                }
//                nums1.pop();
//            }
//        }
//        else {
//            while (!nums2.empty()) {
//                row.push_back(nums2.front()->val);
//                if (nums2.front()->left) {
//                    nums1.push(nums2.front()->left);
//                }
//                if (nums2.front()->right) {
//                    nums1.push(nums2.front()->right);
//                }
//                nums2.pop();
//            }
//        }
//        result.push_back(row);
//    }
//    return result;
//}

void buildVector(TreeNode *root, int depth, vector<vector<int>> &result) {
    if (!root) {
        return;
    }
    if (result.size() == depth) {
        result.push_back(vector<int>());
    }
    
    result[depth].push_back(root->val);
    
    buildVector(root->left, depth+1, result);
    buildVector(root->right, depth+1, result);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    buildVector(root, 0, result);
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root1 = TreeCreate(7, 3,9,20,INT_MAX,INT_MAX,15,7);
    IntVector2DPrint(levelOrder(root1));
    return 0;
}
