//
//  main.cpp
//  第41题
//
//  Created by 张星宇 on 16/2/26.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i + 1)
            return i + 1;
    return nums.size() + 1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,0};
    std::cout << firstMissingPositive(nums1) << endl;
    
    vector<int> nums2 = {3,4,-1,1};
    std::cout << firstMissingPositive(nums2) << endl;
    return 0;
}
