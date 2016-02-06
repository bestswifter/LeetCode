//
//  main.cpp
//  第153题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {2,3,1};
    cout << findMin(nums2) << endl;
    return 0;
}
