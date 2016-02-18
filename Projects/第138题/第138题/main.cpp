//
//  main.cpp
//  第138题
//
//  Created by 张星宇 on 16/2/18.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void RandomListPrint(RandomListNode *head) {
    RandomListNode *node = head;
    while (node)
    {
        cout << node->label << " -> ";
        node = node->next;
    }
    cout << endl;
    
    node = head;
    while (node) {
        if (node->random) {
            cout << node->label << " -> " << node->random->label;
            cout << endl;
        }
        node = node->next;
    }
    cout << endl;
}

RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) { return NULL; }
    RandomListNode *cursor = head;
    while (cursor) {  // 第一遍循环，简单的复制节点和label
        RandomListNode *right = new RandomListNode(cursor->label);
        right->next = cursor->next;
        cursor->next = right;
        cursor = right->next;
    }
    
    cursor = head;
    while (cursor) {  // 第二遍循环，复制random指针
        cursor->next->random = cursor->random ? cursor->random->next : NULL;
        cursor = cursor->next->next;
    }
    
    RandomListNode *newHead = head->next;
    head->next = newHead->next;
    cursor = newHead->next;
    RandomListNode *originListCursor = head;
    RandomListNode *copiedListCursor = newHead;
    
    while (cursor) {    // 第三遍循环，分割双倍链表
        originListCursor->next = cursor;
        originListCursor = originListCursor->next;
        copiedListCursor->next = cursor->next;
        copiedListCursor = copiedListCursor->next;
        cursor = cursor->next->next;
    }
    originListCursor->next = NULL;  // 记得删掉小尾巴
    return newHead;
}

int main(int argc, const char * argv[]) {
    RandomListNode *node1 = new RandomListNode(1);
    RandomListNode *node2 = new RandomListNode(2);
    RandomListNode *node3 = new RandomListNode(3);
    RandomListNode *node4 = new RandomListNode(4);
    RandomListNode *node5 = new RandomListNode(5);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    node1->random = node3;
    node2->random = node5;
    node4->random = node2;
    
    RandomListNode *copy = copyRandomList(node1);
    RandomListPrint(copy);
    RandomListPrint(node1);
    
    RandomListNode *node6 = new RandomListNode(-1);
    RandomListNode *node7 = new RandomListNode(1);
    node6->next = node7;
    cout << node7 << endl;
    RandomListNode *copy2 = copyRandomList(node6);
    RandomListPrint(copy2);
    RandomListPrint(node6);
    cout << node6->next << endl;
    cout << copy2->next << endl;
    
    
    return 0;
}
