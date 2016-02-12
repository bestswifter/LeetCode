/*
	题目分析： 移除数组中重复的元素

	解题思路：双指针，前面的用于遍历数组，后面的用于标记新的最大元素放在哪里
*/

int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0) {return 0;}
    int l = 0, r = 1;
    while (r < nums.size()) {
        if (nums[r] > nums[l]) {
            nums[++l] = nums[r];
        }
        ++r;
    }
    return l+1;
}