//
//  main.cpp
//  第264题
//
//  Created by 张星宇 on 16/2/25.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n) {
    vector<long> uglyNumbers = vector<long>(n);
    uglyNumbers[0] = 1;
    int twoIndex = 0, threeIndex = 0, fiveIndex = 0;
    for (int i = 1; i < n; ++i) {
        long a = uglyNumbers[twoIndex], b = uglyNumbers[threeIndex], c = uglyNumbers[fiveIndex];
        uglyNumbers[i] = a * 2 < b * 3 ? min(a * 2, c * 5) : min(b * 3 , c * 5);
        while (a * 2 <= uglyNumbers[i]) {
            ++twoIndex;
            a *= 2;
        }
        while (b * 3 <= uglyNumbers[i]) {
            ++threeIndex;
            b *= 3;
        }
        while (c * 5 <= uglyNumbers[i]) {
            ++fiveIndex;
            c *= 5;
        }
    }
    return (int)uglyNumbers[n - 1];
}

int main(int argc, const char * argv[]) {
//    std::cout << nthUglyNumber(1) << endl;
//    std::cout << nthUglyNumber(2) << endl;
//    std::cout << nthUglyNumber(3) << endl;
//    std::cout << nthUglyNumber(4) << endl;
//    std::cout << nthUglyNumber(1484) << endl;
//    std::cout << nthUglyNumber(1485) << endl;
    for (int i = 1; i < 2000;  ++i) {
        std::cout << "i = " << i << " ugly number = " << nthUglyNumber(i) << endl;
    }
    return 0;
}
