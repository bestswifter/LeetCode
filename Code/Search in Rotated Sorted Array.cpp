/*
    题目分析：

        在旋转后的单调递增数组中寻找某个值，找不到则返回-1，假设数组中没有重复元素

    解题思路：
    
        递归的思想：数组一分为二，一定有一侧是旋转单增，另一侧是严格单增。分别调用递归函数和二分搜素即可。注意边界条件

*/

/**
 *  递增数列的二分搜索
 *
 *  @param nums   数组
 *  @param target 待搜索值
 *  @param l      搜索范围的左边界
 *  @param r      搜索范围的右边界
 *
 *  @return 待搜索值的下标，如果找不到返回-1
 */
int bsearch(vector<int>& nums, int target, int l, int r) {
    if (l > r) {
        return -1;
    }
    
    int m = (l + r) / 2;
    if (nums[m] == target) {
        return m;
    }
    if (nums[m] < target) {
        return bsearch(nums, target, m + 1, r);
    }
    else {
        return bsearch(nums, target, l, m -1);
    }
}

/**
 *  旋转后的递增数列中寻找指定元素
 *
 *  @param nums   数组
 *  @param target 待搜索值
 *  @param l      搜索范围的左边界
 *  @param r      搜索范围的右边界
 *
 *  @return 待搜索值的下标，如果找不到返回-1
 */
int search(vector<int>& nums, int target, int l, int r) {
    if (l > r) {
        return -1;
    }
    
    int m = (l + r + 1) / 2;
    if (target == nums[m]) {
        return m;
    }
    if (nums[m] > nums[l]) { // 左侧单增
        if (target >= nums[l] && target < nums[m]) { // 在左侧递增区间内
            return bsearch(nums, target, l, m - 1);  // 调用二分搜索
        }
        else {  // 在右侧不规则区间内
            return search(nums, target, m + 1, r);  // 递归调用
        }
    }
    else { // 右侧单增
        if (target <= nums[r] && target > nums[m]) {  // 在右侧递增区间内
            return bsearch(nums, target, m + 1, r); // 二分搜索
        }
        else {  // 在左侧不规则区间内
            return search(nums, target, l, m - 1);  // 递归调用
        }
    }
}

int search(vector<int>& nums, int target) {
    return search(nums, target, 0, nums.size() - 1);
}