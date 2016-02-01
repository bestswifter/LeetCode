//
//  main.cpp
//  第一百五五题
//
//  Created by 张星宇 on 16/2/1.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> nums;
    stack<int> min;
public:
    void push(int x) {
        nums.push(x);
        if ((!min.empty() && min.top() >= x) || min.empty()) {
            min.push(x);
        }
    }
    
    void pop() {
        int top = nums.top();
        nums.pop();
        if (min.top() == top) {
            min.pop();
        }
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return min.top();
    }
};

int main(int argc, const char * argv[]) {
    MinStack sstack = MinStack();
    sstack.push(5);sstack.push(4);sstack.push(1);sstack.push(2);sstack.push(3);sstack.push(10);
    sstack.push(9);sstack.push(8);sstack.push(6);sstack.push(7);sstack.push(15);sstack.push(0);
    
    std::cout << sstack.getMin() << endl;
    sstack.pop();
    std::cout << sstack.getMin() << endl;
    return 0;
}
