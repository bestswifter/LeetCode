//
//  main.cpp
//  第53题
//
//  Created by 张星宇 on 16/2/20.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubArrayHelper(vector<int>& nums, int end, int &max) {
    if (end == 0) {
        return nums[0];
    }
    int m = maxSubArrayHelper(nums, end - 1, max);
    int cmax = m < 0 ? nums[end] : nums[end] + m;
    if (cmax > max) {
        max = cmax;
    }
    
    return cmax;
}

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    maxSubArrayHelper(nums, nums.size() - 1, maxSum);
    return maxSum;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maxSubArray(nums1) << endl;
    
    vector<int> nums2 = {1,-2,3,10,-4,7,2,-5};
    std::cout << maxSubArray(nums2) << endl;
    return 0;
}
