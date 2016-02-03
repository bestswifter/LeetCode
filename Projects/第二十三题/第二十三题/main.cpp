//
//  main.cpp
//  第二十三题
//
//  Created by 张星宇 on 16/2/3.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size=lists.size();
    if(size==0)  return NULL;
    if(size==1)  return lists[0];
    
    ListNode *head = new ListNode(0), *cursor = head;
    priority_queue<ListNode *,vector<ListNode *>, compare> queue;
    
    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i] != NULL) {
            queue.push(lists[i]);
        }
    }
    
    while (!queue.empty()) {
        ListNode *currentMin = queue.top();
        cursor->next = currentMin;
        cursor = cursor->next;
        queue.pop();
        if (currentMin->next != NULL) {
            queue.push(currentMin->next);
        }
    }
    
    return head->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
