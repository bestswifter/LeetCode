//
//  main.cpp
//  第十九题
//
//  Created by 张星宇 on 16/2/1.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head -> next == NULL) {
        return NULL;
    }
    ListNode *i = head;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    while (n-- > 0) {
        i = i->next;
    }
    if (i == NULL) {
        delete i;
        return newHead->next->next;
    }
    else{
        while (i != NULL) {
            i = i->next;
            newHead = newHead->next;
        }
        newHead->next = newHead->next->next;
        delete i,newHead;
        return head;
    }
}

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    ListNode *node = removeNthFromEnd(node1, 2);
    while (node != NULL) {
        std::cout << node->val << " " ;
        node = node->next;
    }
    std::cout << std::endl;
    return 0;
}
