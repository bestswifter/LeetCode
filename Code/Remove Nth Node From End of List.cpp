/*
    题目解析：

        移除数组倒数第n个节点，只用一次遍历

    解题思路：

        可以从头结点开始向后走n个节点，然后前后两个指针同时向后移动，当前面的指针走到链表结尾时，
        后面的指针正好停在倒数第n个节点

        注意一些临界情况的分析
*/

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