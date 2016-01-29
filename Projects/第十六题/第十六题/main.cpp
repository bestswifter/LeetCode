//
//  main.cpp
//  第十六题
//
//  Created by 张星宇 on 16/1/28.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int oneSumClosest(vector<int>& nums, int target, int max) {
//    if (max == 0) {
//        return nums[0];
//    }
//    int diff = abs(nums[0] - target);
//    int oneSum = nums[0];
//    for (int i = 1; i <= max; ++i) {
//        int newDiff = abs(nums[i] - target);
//        if (newDiff < diff) {
//            diff = newDiff;
//            oneSum = nums[i];
//        }
//    }
//    return oneSum;
//}
//
//int twoSumClosest(vector<int>& nums, int target, int max) {
//    if (max == 1) {
//        return nums[0] + nums[1];
//    }
//    int previousTwo = twoSumClosest(nums, target, max - 1);
//    int previousOne = oneSumClosest(nums, target - nums[max], max - 1);
//    return abs(target - previousTwo) < abs(target - nums[max] - previousOne) ? previousTwo : previousOne + nums[max];
//}
//
//int threeSumClosest(vector<int>& nums, int target, int max) {
//    if (max == 2) {
//        return nums[0] + nums[1] + nums[2];
//    }
//    int previousThree = threeSumClosest(nums, target, max - 1);
//    int previousTwo = twoSumClosest(nums, target - nums[max], max - 1);
//    return abs(target - previousThree) < abs(target - nums[max] - previousTwo) ? previousThree : previousTwo + nums[max];
//}

int threeSumClosest(vector<int>& nums, int target) {
//    return threeSumClosest(nums, target, nums.size() - 1);
    sort(nums.begin(), nums.end());
    int sum = nums[0] + nums[1] + nums[nums.size() - 1], diff = abs(target - sum);
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        int j = i + 1, k = nums.size() - 1;
        while (j != k) {
            int newSum = nums[i] + nums[j] + nums[k];
            if (abs(target - newSum) < diff) {
                sum = newSum;
                diff = abs(target - newSum);
            }
            if (newSum > target) {
                --k;
            }
            else {
                ++j;
            }
            if (sum == target) {
                return sum;
            }
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {-1, 2, 1, -4};
    vector<int> nums2 = {-3,-1,2,3,6};
    vector<int> nums3 = {43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
    vector<int> nums4 = {1,2,4,8,16,32,64,128};
    std::cout << threeSumClosest(nums1, 1) << endl;
    std::cout << threeSumClosest(nums2, 4) << endl;
    std::cout << threeSumClosest(nums3, 284) << endl;
    std::cout << threeSumClosest(nums4, 82) << endl;
    return 0;
}
