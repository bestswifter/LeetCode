//
//  main.cpp
//  第268题
//
//  Created by 张星宇 on 16/2/26.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != i && nums[i] < n) {
            swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    return nums.size();
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {};
    std::cout << missingNumber(nums1) << endl;
    
    vector<int> nums2 = {0};
    std::cout << missingNumber(nums2) << endl;
    
    vector<int> nums3 = {0,1};
    std::cout << missingNumber(nums3) << endl;
    
    vector<int> nums4 = {0,1,3};
    std::cout << missingNumber(nums4) << endl;
    
    vector<int> nums5 = {3,2,0};
    std::cout << missingNumber(nums5) << endl;
    
    vector<int> nums6 = {4,1,0,2};
    std::cout << missingNumber(nums6) << endl;
    
    vector<int> nums7 = {5,4,3,2,0};
    std::cout << missingNumber(nums7) << endl;
    
    vector<int> nums8 = {9,6,4,2,3,5,7,0,1};
    std::cout << missingNumber(nums8) << endl;
    return 0;
}
