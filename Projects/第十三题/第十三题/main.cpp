//
//  main.cpp
//  第十三题
//
//  Created by 张星宇 on 16/1/23.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    int result = 0;
    unordered_map<char, int> hashMap = {{'I',1}, {'V',5}, {'X',10}, {'L', 50}, {'C', 100}, {'D',500}, {'M',1000}};
    for (int i = 0; i < s.length(); ++i) {
        if ((s[i] == 'I' || s[i] == 'X' || s[i] == 'C') && i < (int)s.length() - 1) {
            int current = hashMap[s[i]], next = hashMap[s[i+1]];
            if (next > current) {
                result += next - current;
                ++i;
                continue;
            }
            result += current;
        }
        else {
            result += hashMap[s[i]];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << romanToInt("XIX") << endl;
    std::cout << romanToInt("XX") << endl;
    std::cout << romanToInt("XLV") << endl;
    std::cout << romanToInt("MCMLXXX") << endl;
    return 0;
}
