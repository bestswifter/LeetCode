//
//  main.cpp
//  第二十题
//
//  Created by 张星宇 on 16/2/1.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stack.push(s[i]);
        }
        else {
            if (stack.empty() || (stack.top() != s[i] - 1 && stack.top() != s[i] - 2)) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main(int argc, const char * argv[]) {
    string s1 = "[";
    string s2 = "()[]{}";
    string s3 = "([)]";
    string s4 = "([])";
    
    std::cout << isValid(s1) << std::endl;
    std::cout << isValid(s2) << std::endl;
    std::cout << isValid(s3) << std::endl;
    std::cout << isValid(s4) << std::endl;
    return 0;
}
