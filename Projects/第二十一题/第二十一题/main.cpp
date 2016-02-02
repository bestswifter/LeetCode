//
//  main.cpp
//  第二十一题
//
//  Created by 张星宇 on 16/2/2.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0);
    ListNode *cursor = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2-> val) {
            cursor->next = l1;
            l1 = l1->next;
        }
        else {
            cursor->next = l2;
            l2 = l2->next;
        }
        cursor = cursor->next;
    }
    cursor->next = l1 == NULL ? l2 : l1;
    delete cursor;
    return head->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *l11 = new ListNode(1);
    ListNode *l21 = new ListNode(2);
    ListNode *l12 = new ListNode(3);
    ListNode *l22 = new ListNode(4);
    ListNode *l13 = new ListNode(5);
    ListNode *l23 = new ListNode(6);
    ListNode *l14 = new ListNode(7);
    ListNode *l24 = new ListNode(8);
    ListNode *l15 = new ListNode(9);
    ListNode *l25 = new ListNode(10);
//    ListNode *l26 = new ListNode(12);
//    ListNode *l27 = new ListNode(14);
    
    l11->next = l12;
    l12->next = l13;
    l13->next = l14;
    l21->next = l22;
    l22->next = l23;
    l23->next = l24;
    l14->next = l15;
    l24->next = l25;
//    l25->next = l26;
//    l26->next = l27;
    
    ListNode *merged = mergeTwoLists(l11, l21);
    
    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    
    delete merged;
    return 0;
}
