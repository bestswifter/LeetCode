//
//  main.cpp
//  第33题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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

int main(int argc, const char * argv[]) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums2 = {3,1};
    vector<int> nums3 = {1,3,5};
    vector<int> nums4 = {4,5,6,7,8,1,2,3};
    vector<int> nums5 = {7,8,1,2,3,4,5,6};
    vector<int> nums6 = {279,284,285,287,288,296,2,8,10,11,12,13,14,19,20,22,25,26,27,28,29,33,37,39,42,43,47,48,49,50,57,62,63,66,68,69,71,73,74,77,78,79,85,89,92,94,99,111,113,117,120,122,125,134,145,152,155,157,160,161,167,168,181,182,188,189,190,194,199,201,204,208,213,220,223,225,226,227,231,237,240,242,247,254,259,260,261,264,267,271,275};
    
    std::cout << search(nums, 4) << endl;
    std::cout << search(nums, 5) << endl;
    std::cout << search(nums, 6) << endl;
    std::cout << search(nums, 7) << endl;
    std::cout << search(nums, 0) << endl;
    std::cout << search(nums, 1) << endl;
    std::cout << search(nums, 2) << endl;
    std::cout << search(nums, 8) << endl;
    std::cout << search(nums2, 1) << endl;
    std::cout << search(nums3, 5) << endl;
    std::cout << search(nums4, 8) << endl;
    std::cout << search(nums5, 2) << endl;
    std::cout << search(nums6, 298) << endl;
    return 0;
}
