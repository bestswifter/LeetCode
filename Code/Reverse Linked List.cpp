/*
    题目分析：   反转链表
*/

/*
    递归解法：   每次让head-next指向head，然后对剩下的链表进行递归
*/

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

/**
 *  迭代实现
 *
 *  @param head 原链表的头指针
 *
 *  @return 新链表的头指针
 */
ListNode* reverseList(ListNode* head) {
    ListNode *newHead = new ListNode(0);
    while (head != NULL) {
        ListNode *next = newHead->next, *oldNext = head->next;
        head->next = newHead->next;
        newHead->next = head;
        head = oldNext;
    }
    return newHead->next;
}