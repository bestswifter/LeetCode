//
//  main.cpp
//  第136题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int i = nums[0];
    for (int j = 1; j < nums.size(); ++j) {
        i = i ^ nums[j];
    }
    return i;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,1,2,2,3};
    std::cout << singleNumber(nums1) << endl;
    return 0;
}
