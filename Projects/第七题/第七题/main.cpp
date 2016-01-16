//
//  main.cpp
//  第七题
//
//  Created by 张星宇 on 16/1/16.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cmath>
#include <limits.h>

int reverse(int x);
void check(int result, int expectedValue);
int main(int argc, const char * argv[]) {
    int x1 = 123;
    int x2 = -123;
    int x3 = 1000;
    int x4 = -1000;
    int x5 = 1000000003;
    int x6 = -2147483648;
    
    check(reverse(x1), 321);
    check(reverse(x2), -321);
    check(reverse(x3), 1);
    check(reverse(x4), -1);
    check(reverse(x5), 0);
    check(reverse(x6), 0);
}

int reverse(int x) {
    if (x == 0) { return 0;}
    std::stack<int> stack;
    
    int isMinus = x / std::abs(x);
    long result = 0;
    x = std::abs(x);
    
    while (x != 0) {
        stack.push(x % 10);
        x /= 10;
    }
    
    if (!stack.empty()) {   // 如果stack为空，说明输入是0。可以直接返回result
        for (int i = 0; !stack.empty(); ++i) {
            result += std::pow(10, i) * stack.top() * isMinus;
            stack.pop();
        }
    }
    
    if (result > INT_MAX || result < INT_MIN) {
        return 0;
    }
    return (int)result;
}

void check(int result, int expectedValue) {
    if(result != expectedValue) {
        std::cout << "不通过！！！！结果是：" << result << "，正确答案是： " << expectedValue << std::endl;
    }
    else {
        std::cout << "测试通过" << std::endl;
    }
}