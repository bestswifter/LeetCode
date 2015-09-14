/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node = new ListNode(0);
        ListNode *cursor1 = l1;
        ListNode *cursor2 = l2;
        ListNode *cursorNode = node;

        //首先创建三个临时指针用于遍历链表
        
        int addition = 0;
        if(cursor1->val + cursor2->val >= 10){
            addition = 1;
        }
        cursorNode->val = (cursor1->val + cursor2->val) % 10;  //算出node的第一个值
        if(cursor1->next == NULL && cursor2->next == NULL && addition == 1){
            cursorNode->next = new ListNode(addition);  // 说明两个参数链表都是长度为一，考虑需要进位的情况。
            return node;
        }
        //当其中一个链表还没结束
        while(cursor1->next != NULL || cursor2->next != NULL){
            cursor1 = cursor1->next;
            cursor2 = cursor2->next;

            //为空链表临时赋值，相当于加0
            if(cursor1 == NULL){
                cursor1 = new ListNode(0);
            }
            if(cursor2 == NULL){
                cursor2 = new ListNode(0);
            }
            cursorNode->next = new ListNode((cursor1->val + cursor2->val + addition) % 10);
            cursorNode = cursorNode->next;
            
            if(cursor1->val + cursor2->val + addition >= 10){
                addition = 1;
            }
            else{
                addition = 0;
            }
            
            //如果两个链表都已经结束
            if(cursor1->next == NULL && cursor2->next == NULL && addition == 1){
                cursorNode->next = new ListNode(addition);
            }
        }
        return node;
    }
};