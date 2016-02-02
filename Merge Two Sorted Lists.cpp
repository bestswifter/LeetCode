/*
    题目分析： 合并两个有序链表

    我的算法：分别用两个指针指向这两个链表，每次选择最小的放入结果中，然后向后移一位。

    递归算法：找到两个链表中最小的header，然后排除这个header再执行自己这个函数
*/

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