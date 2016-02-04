//
//  main.cpp
//  第二十四题
//
//  Created by 张星宇 on 16/2/3.
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

ListNode* swapPairs(ListNode* head) {
    if (head == NULL) { return NULL; }
    if (head ->next == NULL) { return head; }
    
    ListNode *newHead = head->next;
    head->next = swapPairs(head->next->next);
    newHead->next = head;
    return newHead;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
