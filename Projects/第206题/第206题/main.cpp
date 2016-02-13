//
//  main.cpp
//  第206题
//
//  Created by 张星宇 on 16/2/13.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 *  迭代实现
 *
 *  @param head 原链表的头指针
 *
 *  @return 新链表的头指针
 */
//ListNode* reverseList(ListNode* head) {
//    ListNode *newHead = new ListNode(0);
//    while (head != NULL) {
//        ListNode *next = newHead->next, *oldNext = head->next;
//        head->next = newHead->next;
//        newHead->next = head;
//        head = oldNext;
//    }
//    return newHead->next;
//}

ListNode* reverseHelper(ListNode* head, ListNode* newHead) {
    if (head == NULL) {
        return newHead;
    }
    ListNode *next = head->next;
    head->next = newHead;
    return reverseHelper(next, head);
}

ListNode* reverseList(ListNode* head) {
    return reverseHelper(head, NULL);
}


ListNode* createListFromVector(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    ListNode *head = new ListNode(nums[0]);
    ListNode *cursor = head;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode *node = new ListNode(nums[i]);
        cursor->next = node;
        cursor = cursor->next;
    }
    return head;
}

void printList(ListNode *node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1};
    vector<int> nums3 = {};
    ListNode *list1 = createListFromVector(nums1);
    ListNode *list2 = createListFromVector(nums2);
    ListNode *list3 = createListFromVector(nums3);
    printList(reverseList(list1));
    printList(reverseList(list2));
    printList(reverseList(list3));
    
    return 0;
}
