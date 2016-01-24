//
//  main.cpp
//  第十四题
//
//  Created by 张星宇 on 16/1/24.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0 || strs[0].size() == 0) {
        return "";
    }
    string result = "";
    int minLength = strs[0].size();
    for (int i = 1; i < strs.size(); ++i) {
        if (strs[i].size() == 0) {
            return "";
        }
        if (minLength > strs[i].size()) {
            minLength = strs[i].size();
        }
    }
    for (int i = 0; i < minLength; ++i) {
        bool isAllEqual = true;
        for (int j = 1; j < strs.size(); ++j) {
            if (!(strs[j][i] == strs[0][i])) {
                isAllEqual = false;
                break;
            }
        }
        if (isAllEqual) {
            result += strs[0][i];
            continue;
        }
        break;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = {"12345678","1234567","123456","12345"};
//    std::cout << longestCommonPrefix(strs) << endl;
    
    vector<string> strs2 = {"","12345678","1234567","123456","12345"};
//    std::cout << longestCommonPrefix(strs2) << endl;
    
    vector<string> strs3 = {"aca","cba"};
    std::cout << longestCommonPrefix(strs3) << endl;
    return 0;
}
