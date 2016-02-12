//
//  main.cpp
//  第26题
//
//  Created by 张星宇 on 16/2/12.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,1,1,1,1,1,2,2,2,2,3,3,3,4};
    vector<int> nums2 = {};
    
    for (int i = 0; i < removeDuplicates(nums1); ++i) {
        std::cout << nums1[i] << " ";
    }
    std::cout << endl;
    
    for (int i = 0; i < removeDuplicates(nums2); ++i) {
        std::cout << nums2[i] << " ";
    }
    std::cout << endl;
    
    return 0;
}
