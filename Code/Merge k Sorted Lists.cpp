/*
    题目分析：

        合并n个已经排序的数组

    解题思路：

        类似于合并两个数组的想法，把这n个数组的头放在priority_queue里面，然后每次取出
        队列的头元素，表示当前最小的。如果这个元素有后继，则把其后继加入到队列中。
*/

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