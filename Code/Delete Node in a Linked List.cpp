/*
	题目分析： 给一个节点作为参数，删除这个节点。本题简化了条件，这个节点不是链表的结尾

	解题思路： 一般来说，删除某个节点的next比较容易。但是本题要求O（1）的时间复杂度。解决方法是变通一下，
	把next的值赋给自己，然后删除next。

	补充：如果这个节点是链表的结尾，还是要用O（n）的时间复杂度去遍历，但这毕竟只是特殊情况
*/

/**
 *  删除给定节点
 *
 *  @param node 待删除节点，根据题意，这不是链表的尾部
 */
void deleteNode(ListNode* node) {
    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
    nextNode = NULL;
}