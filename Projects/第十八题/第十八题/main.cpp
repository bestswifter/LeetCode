//
//  main.cpp
//  第十八题
//
//  Created by 张星宇 on 16/1/31.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) {
        return result;
    }
    
    std::sort(nums.begin(), nums.end());
    int l = nums.size();
    
    for (int i = 0; i < l - 3; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;   // 跳过重复的元素
        }
        if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
            break;   // 预判，排除不可能的情况
        }
        if (nums[i] + nums[l-1] + nums[l-2] + nums[l-3] < target) {
            continue;
        }
        int threeSum = target - nums[i];
        
        for (int j = i + 1; j < l - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;   // 跳过重复的元素
            }
            if (nums[j] + nums[j+1] + nums[j+2] > threeSum) {
                break;   // 预判，排除不可能的情况
            }
            if (nums[j] + nums[l-1] + nums[l-2] < threeSum) {
                continue;
            }
            int twoSum = threeSum - nums[j];
            int m = j + 1, n = l - 1;
            while (true) {
                while (m > j + 1 && nums[m] == nums[m-1]) { ++m; }   // 跳过重复的元素
                while (n < l - 1 && nums[n] == nums[n+1]) { --n; }   // 跳过重复的元素
                if (m >= n) {
                    break;
                }
                if (nums[m] + nums[n] < twoSum) { ++m; }
                else if (nums[m] + nums[n] > twoSum) { --n; }
                else {    // 找到了一组解，加入result中，再往后查找
                    vector<int> tuple = {nums[i],nums[j],nums[m],nums[n]};
                    result.push_back(tuple);
                    ++m, --n;
                }
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
//    vector<int> nums = {1, 0, -1, 0, -2, 2};
//    vector<int> nums = {1, 0, 0, 0, -1, -1, -2, -2, 2,2, -1, 0, -2, 2};
//    vector<int> nums = {0,0,0,0};
//    vector<int> nums = {0,0,0};
//    vector<int> nums = {1,4,-3,0,0,0,5,0};
//    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = fourSum(nums, -1);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << endl;
    }
    return 0;
}
