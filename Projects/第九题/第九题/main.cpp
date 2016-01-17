//
//  main.cpp
//  第九题
//
//  Created by 张星宇 on 16/1/17.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <cmath>

bool isPalindrome(int x);
void check(bool result, bool expeced);

int main(int argc, const char * argv[]) {
    
    check(isPalindrome(0), true);
    check(isPalindrome(2), true);
    check(isPalindrome(4), true);
    check(isPalindrome(9), true);
    check(isPalindrome(10), false);
    check(isPalindrome(11), true);
    check(isPalindrome(12), false);
    check(isPalindrome(99), true);
    check(isPalindrome(100), false);
    check(isPalindrome(12321), true);
    check(isPalindrome(12322), false);
    check(isPalindrome(1000021), false);
    return 0;
}

int getNumberAtIndex(int number, int index, int totalBits) {
    return (number / (int)pow(10, totalBits - index - 1)) % 10;
}

bool isPalindrome(int x) {
    if (x < 0) { return false; }
    
    int bits = 0, localValue = x, i = 0;
    while (localValue != 0) {
        bits++;
        localValue /= 10;
    }
    
    while (bits > 1) {
        if (getNumberAtIndex(x, i, bits) != getNumberAtIndex(x, bits - i - 1, bits)) {
            return false;
        }
        ++i;
        bits -= 2;
    }
    return true;
}

void check(bool result, bool expeced){
    if (result == expeced) {
        std::cout << "测试通过" << std::endl;
    }
    else {
        std::cout << "测试不通过，结果是：" << result << " 应该是：" << expeced << std::endl;
    }
}
