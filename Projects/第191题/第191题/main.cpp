//
//  main.cpp
//  第191题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

int hammingWeight(uint32_t n) {
    int c = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            ++c;
        }
        n = n >> 1;
    }
    return c;
}

int numberof1(int n) {
    int c = 0;
    while (n != 0) {
        ++c;
        n &= n -1;
    }
    return c;
}

int main(int argc, const char * argv[]) {
    std::cout << hammingWeight(10) << std::endl;
    std::cout << hammingWeight(7) << std::endl;
    std::cout << (-10 >> 10) << std::endl;
    return 0;
}
