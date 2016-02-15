//
//  Tool.hpp
//  第226题
//
//  Created by 张星宇 on 16/2/15.
//  Copyright © 2016年 zxy. All rights reserved.
//

#ifndef Tool_hpp
#define Tool_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <queue>
#include <cstdarg>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};

void ArrayPrint(int arr[], int count);

vector<int> IntVectorCreate(int count, ...);
void IntVectorPrint(const vector<int> &vec);
void IntVector2DPrint(const vector<vector<int>> &vec);

vector<string> StringVectorCreate(int count, ...);
void StringVectorPrint(const vector<string> &vec);

TreeNode *TreeCreate(int count, ...);
void TreePrint(TreeNode *root);

ListNode *ListCreate(int count, ...);
void ListPrint(ListNode *head);

#endif /* Tool_hpp */
