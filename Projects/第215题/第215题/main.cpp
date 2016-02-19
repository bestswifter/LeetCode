//
//  main.cpp
//  第215题
//
//  Created by 张星宇 on 16/2/19.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int findKthLargest(vector<int>& nums, int k) {
    if (nums.size() == 0) { return -1; }
    multiset<int> knums;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (knums.size() < k) { // multiset未满
            knums.insert(nums[i]);
        }
        else {
            if (*knums.begin() < nums[i] ) {
                knums.erase(knums.begin());
                knums.insert(nums[i]);
            }
        }
    }
    return *knums.begin();
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {3,2,1,5,6,4};
    std::cout << findKthLargest(nums1, 2) << endl;
    return 0;
}
