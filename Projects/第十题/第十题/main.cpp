//
//  main.cpp
//  第十题
//
//  Created by 张星宇 on 16/1/19.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
bool isMatch(string s, string p);

int main(int argc, const char * argv[]) {

    std::cout << isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s") << std::endl;
    return 0;
}

bool isMatch(string s, string p) {
    int sLenght = s.length(), pLength = p.length();
    vector<vector<bool>> r(sLenght + 1, vector<bool>(pLength + 1, false));
    r[0][0] = true;
    for (int i = 0; i < sLenght + 1; ++i) {
        for (int j = 1; j < pLength + 1; ++j) {
            if (p[j - 1] == '*') {
                r[i][j] = r[i][j-2] || (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) && r[i-1][j];
            }
            else {
                r[i][j] = i > 0 && r[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
            }
        }
    }
    
    return r[sLenght][pLength];
}

/*
 "aa"
 "a"
 "aa"
 "aa"
 "aaa"
 "*aa"
 "aa"
 "a*"
 "aa"
 ".*"
 "ab"
 ".*"
 "aab"
 "c*a*b"
*/