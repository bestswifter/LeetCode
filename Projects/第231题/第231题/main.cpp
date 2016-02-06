//
//  main.cpp
//  第231题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & n-1) == 0 ;
}

int main(int argc, const char * argv[]) {
    for (int i = 1; i < 18; ++i) {
        std::cout << isPowerOfTwo(i) << std::endl;
    }
    return 0;
}
