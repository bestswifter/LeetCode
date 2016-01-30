//
//  main.cpp
//  第十七题
//
//  Created by 张星宇 on 16/1/30.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
    vector<vector<string>> map = {{"a","b","c"}, {"d","e","f"}, {"g","h","i"},
        {"j","k","l"}, {"m","n","o"}, {"p","q","r","s"}, {"t","u","v"}, {"w","x","y","z"}};
    vector<string> result;
    for (int i = 0; i <digits.length(); ++i) {
        if (digits[i] == '0' || digits[i] == '1') {
            return result;
        }
    }
    if (digits.size() > 0) {
        for (int i = 0; i < map[digits[0] - 50].size(); ++i) {
            result.push_back(map[digits[0] - 50][i]);
        }
    }
    
    for (int i = 1; i < digits.length(); ++i) {
        int currentSize = result.size();
        for (int j = 0; j < currentSize; ++j) {
            for (int k = 1; k < map[digits[i]-50].size(); ++k) {
                result.push_back(result[j] + map[digits[i] - 50][k]);
            }
        }
        for (int j = 0; j < currentSize; ++j) {
            result[j] += map[digits[i] - 50][0];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> result = letterCombinations("");
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << endl;
    }
    return 0;
}
