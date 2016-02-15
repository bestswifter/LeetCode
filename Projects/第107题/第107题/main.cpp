//
//  main.cpp
//  第107题
//
//  Created by 张星宇 on 16/2/15.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

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
    vector<vector<int>> temp;
    buildVector(root, 0, temp);
    vector<vector<int>> result;
    int length = temp.size();
    for (int i = 0; i < length; ++i) {
        result.push_back(temp[length-i-1]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
