//
//  main.cpp
//  第263题
//
//  Created by 张星宇 on 16/2/25.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

bool isUgly(int num) {
    if (num <= 0) { return false; }
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

int main(int argc, const char * argv[]) {
    std::cout << isUgly(14) << std::endl;
    std::cout << isUgly(6) << std::endl;
    std::cout << isUgly(8) << std::endl;
    std::cout << isUgly(1) << std::endl;
    std::cout << isUgly(0) << std::endl;
    std::cout << isUgly(-1) << std::endl;
    return 0;
}
