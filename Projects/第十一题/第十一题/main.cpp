//
//  main.cpp
//  第十一题
//
//  Created by 张星宇 on 16/1/22.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height);
int main(int argc, const char * argv[]) {
    
    std::vector<int> array1 = {1,2,2,1};
    std::vector<int> array2 = {1,2,3,5,8,6,4,2};
    std::vector<int> array3 = {1,0,0,5,8,4,12,5,0,6,3,2,17,4};
    std::vector<int> array4 = {1,5,8,4,12,5,6,3,2,17,4};
    std::vector<int> array5 = {1,5,8,4,12,5,6};
    
    std::cout << maxArea(array1) << std::endl;
    std::cout << maxArea(array2) << std::endl;
    std::cout << maxArea(array3) << std::endl;
    std::cout << maxArea(array4) << std::endl;
    std::cout << maxArea(array5) << std::endl;
    
    return 0;
}

int maxArea(vector<int>& height) {
    int result = 0, left = 0, right = 0;
    
    for (int begin = 0, end = (int)height.size() - 1; begin != end; ) {
        if (height[begin] < left) {
            ++begin;
            continue;
        }
        
        left = height[begin];
        
        if (height[end] < right) {
            --end;
            continue;
        }
        
        right = height[end];
        
        result = max((end - begin) * min(left, right), result);
        if (left < right) {
            ++begin;
        }
        else {
            --end;
        }
    }
    
    return result;
}