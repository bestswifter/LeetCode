/*
	题目分析：交换链表中每两个相邻的节点

	解题思路：显然用递归的思想，交换前两个，然后把第三个节点作为参数开始新的递归
*/

ListNode* swapPairs(ListNode* head) {
    if (head == NULL) { return NULL; }
    if (head ->next == NULL) { return head; }
    
    ListNode *nextNode = head->next;
    ListNode *node = head->next->next;
    nextNode->next = head;
    head->next = swapPairs(node);
    return nextNode;
}