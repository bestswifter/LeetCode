/*
    题目分析：复制复杂链表，链表节点中有一个random指针，可能随即指向链表中的任何一个节点或null

    解题思路：可以选择哈希表，避免复制random指针时O(n)的查找，也可以不用哈希表，只要遍历链表三次即可：

    1. 假设链表为1->2->3->4->5，先把每个节点复制一次，变成1->1->2->2->3->3->4->4->5->5
    2. 复制random指针，核心思想如下：cursor->next->random = cursor->random->next
    3. 将链表一分为二，间隔排列，返回深拷贝后的链表
*/

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
