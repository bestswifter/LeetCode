//
//  main.cpp
//  第十五题
//
//  Created by 张星宇 on 16/1/25.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
        return result;
    }
    std::sort(nums.begin(), nums.end());
    unordered_map<int, int> hashMap;
    
    int previous = nums[0] - 1;
    for (int i = 0; i < nums.size(); ++i) {
//        if (i > 0 && nums[i] != previous) {
            hashMap[nums[i]] = i;
//        }
//        else {
//            previous = nums[i];
//        }
    }
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] == previous) {
            continue;
        }
        previous = nums[i];
        
        int temp  = nums[i] - 1;
        for (int j = i + 1; j < nums.size(); ++j) {
            int numbersToFind = 0 - nums[i] - nums[j];
            if (nums[j] == temp) {
                continue;
            }
            temp = nums[j];
            if (hashMap.find(numbersToFind) != hashMap.end() && hashMap[numbersToFind] > j) {
                result.push_back({nums[i],nums[j],nums[hashMap[numbersToFind]]});
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {-5,-5,-3,-4,-2,-1,1,0,-1,-2,3,2,5,4,3,6};
//    vector<int> numbers = {-5,-5,-5,-5,-1,-1,-1,-1,6,6,6,6};
//    vector<int> numbers = {0,0,0};
    vector<vector<int>> result = threeSum(numbers);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << "，";
        }
        std::cout << endl;
    }
    return 0;
}
