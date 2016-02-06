/*
	题目分析： 找到旋转数组中的最小值，默认不存在重复元素

	解题思路：和寻找元素类似，使用二分法。本体使用循环实现，比使用递归更简洁，效率更高。	
*/

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, min = nums[0];
    
    while (l <= r) {
        int m = (l + r + 1) / 2;
        if (nums[m] < nums[l]) {    // 右侧数组单调递增
            min = std::min(min, nums[m]);
            r = m - 1;
        }
        else {  // 根据题意，没有重复元素，这里可以认为nums[m] > nums[l]
            min = std::min(min, nums[l]);
            l = m + 1;
        }
    }
    return min;
}