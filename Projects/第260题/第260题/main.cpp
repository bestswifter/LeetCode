//
//  main.cpp
//  第260题
//
//  Created by 张星宇 on 16/2/27.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include "Tool.hpp"

bool isOneAtBit(int number, int bit) {
    for (int i = 0; i < bit; ++i) {
        number = number >> 1;
    }
    return number & 1;
}

vector<int> singleNumber(vector<int>& nums) {
    int xorNum = 0, bitOfOne = 0, a = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
        xorNum ^= nums[i];
    }
    while (xorNum != 0 && (xorNum & 1) == 0) {
        ++bitOfOne;
        xorNum = xorNum >> 1;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (isOneAtBit(nums[i], bitOfOne)) {
            a ^= nums[i];
        }
        else {
            b ^= nums[i];
        }
    }
    return {a, b};
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,1,3,2,5};
    IntVectorPrint(singleNumber(nums1));
    
    vector<int> nums2 = {2,4,3,6,3,2,5,5};
    IntVectorPrint(singleNumber(nums2));
    
    vector<int> nums3 = {2,4};
    IntVectorPrint(singleNumber(nums3));
    return 0;
}
