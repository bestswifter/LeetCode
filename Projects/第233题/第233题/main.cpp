//
//  main.cpp
//  第233题
//
//  Created by 张星宇 on 16/2/20.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

// 每一个后面都有10种，每一个前面都可以加上1。

int getBitsOfNumber(int n) {
    int bits = 0;
    while (n) {
        ++bits;
        n /= 10;
    }
    return bits;
}

int countDigitOne(int n) {
    int number = 0;
    for (int bits = getBitsOfNumber(n); n > 0; --bits) {// bits表示n是几位数，比如621345是6位数
        int powerOfTen = pow(10, bits - 1); // 这是10的若干次方，数量级不大于n，如n=621345，这个数等于100000
        int firstBit = n / powerOfTen;  // 第一位数字，比如621345的第一位是6
        n -= firstBit * powerOfTen;   // 去掉了首位的n，比如621345变成21345
        number += firstBit * (bits - 1) * pow(10, bits - 2) + (firstBit > 1 ? pow(10, bits - 1) : (firstBit == 1 ? n + 1 : 0));
    }
    return number;
}

int main(int argc, const char * argv[]) {
    std::cout << countDigitOne(621345) << " == 418821" << endl;
    std::cout << countDigitOne(101) << " == 23" << endl;
    return 0;
}
