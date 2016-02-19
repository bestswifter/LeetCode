/*
    题目分析：找到数组中第k大的数

    实现方法：使用二叉树类型的结构，保存前k大的数。如果有必要则删除最小的，然后插入新的。

    补充：实际上还可以利用partion的思路来做，但是会修改原数组。
*/

int findKthLargest(vector<int>& nums, int k) {
    if (nums.size() == 0) { return -1; }
    multiset<int> knums;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (knums.size() < k) { // multiset未满
            knums.insert(nums[i]);
        }
        else {
            if (*knums.begin() < nums[i] ) {
                knums.erase(knums.begin());
                knums.insert(nums[i]);
            }
        }
    }
    return *knums.begin();
}