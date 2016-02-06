/*
	题目分析： 旋转数组中查找指定元素，数组中单调递增但是可能有重复元素

	解题思路：和没有重复元素的情况类似，但是要考虑nums[m] == nums[l]的情况，此时不具备可比性，所以从
	l的后面一位开始。

	最坏的情况下，时间复杂度为O(n)
*/

bool bsearch(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return false;
        }
    
        int m = (l + r) / 2;
        if (nums[m] == target) {
            return true;
        }
        if (nums[m] < target) {
            return bsearch(nums, target, m + 1, r);
        }
        else {
            return bsearch(nums, target, l, m -1);
        }
    }
    
    bool search(vector<int>& nums, int target, int l, int r) {
        if (l > r) {
            return false;
        }
    
        int m = (l + r + 1) / 2;
        if (target == nums[m]) {
            return true;
        }
        if (nums[m] > nums[l]) { // 左侧单增
            if (target >= nums[l] && target < nums[m]) { // 在左侧递增区间内
                return bsearch(nums, target, l, m - 1);  // 调用二分搜索
            }
            else {  // 在右侧不规则区间内
                return search(nums, target, m + 1, r);  // 递归调用
            }
        }
        else if (nums[m] < nums[l]) { // 右侧单增
            if (target <= nums[r] && target > nums[m]) {  // 在右侧递增区间内
                return bsearch(nums, target, m + 1, r); // 二分搜索
            }
            else {  // 在左侧不规则区间内
                return search(nums, target, l, m - 1);  // 递归调用
            }
        }
        else {
            return search(nums, target, l + 1, r);
        }
    }

    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }