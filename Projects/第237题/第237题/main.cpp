//
//  main.cpp
//  第237题
//
//  Created by 张星宇 on 16/2/12.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 *  删除给定节点
 *
 *  @param node 待删除节点，根据题意，这不是链表的尾部
 */
void deleteNode(ListNode* node) {
    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
    nextNode = NULL;
}

int main(int argc, const char * argv[]) {
    ListNode *head = new ListNode(0);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(0);
//    ListNode *node4 = new ListNode(4);
    
    head->next = node2;
    node2->next = node3;
//    node3->next = node4;
    
    deleteNode(head);
    
    while (head) {
        std::cout << "val = " << head->val << std::endl;
        head = head->next;
    }
    return 0;
}
