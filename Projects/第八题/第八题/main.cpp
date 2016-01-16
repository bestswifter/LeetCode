//
//  main.cpp
//  第八题
//
//  Created by 张星宇 on 16/1/16.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int myAtoi(string str);
void check(int result, int expectedValue);

int main(int argc, const char * argv[]) {
    
    string x1 = "123";
    string x2 = "-123";
    string x3 = "  1000";
    string x4 = "  -1000";
    string x5 = "0";
    string x6 = "1 23";
    string x7 = "+-11 23";
    string x8 = "+-+11 23";
    string x9 = "+-+ad";
    string x10 = "999999999999999999";
    string x11 = "-2147483649";
    string x12 = " b11228552307";
    string x13 = "010";
    
    check(myAtoi(x1), 123);
    check(myAtoi(x2), -123);
    check(myAtoi(x3), 1000);
    check(myAtoi(x4), -1000);
    check(myAtoi(x5), 0);
    check(myAtoi(x6), 1);
    check(myAtoi(x7), 0);
    check(myAtoi(x8), 0);
    check(myAtoi(x9), 0);
    check(myAtoi(x10), 2147483647);
    check(myAtoi(x11), -2147483648);
    check(myAtoi(x12), 0);
    check(myAtoi(x13), 10);
}

int myAtoi(string str) {
    long result = 0;
    std::stack<int> stack;
    bool found = false;
    int factor = 1;
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] < '1' || str[i] > '9') {
            if (found) {
                if (str[i] == '0') {
                    stack.push(0);
                }
                else {
                    break;  // 有效的数字结束
                }
            }
            else {
                switch (str[i]) {
                    case '-':
                        factor = -1;
                        found = true;
                        break;
                    case '+':
                        factor = 1;
                        found = true;
                        break;
                    case ' ':
                    case '0':
                        continue;
                        break;
                    default:
                        return 0;
                }
            }
        } else {  // 找到了第一个有效数字
            found = true;
            stack.push(str[i] - 48);
        }
    }
    
    for (int i = 0; !stack.empty(); ++i) {
        result += std::pow(10, i) * stack.top() * factor;
        if (result > INT_MAX) {
            result = 2147483647;
            break;
        }
        else if (result < INT_MIN) {
            result = -2147483648;
            break;
        }
        stack.pop();
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