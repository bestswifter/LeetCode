//
//  main.cpp
//  第225题
//
//  Created by 张星宇 on 16/2/6.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> left;
    queue<int> right;
public:
    // Push element x onto stack.
    void push(int x) {
        if (left.empty()) {
            left.push(x);
            while (!right.empty()) {
                left.push(right.front());
                right.pop();
            }
        }
        else {
            right.push(x);
            while (!left.empty()) {
                right.push(left.front());
                left.pop();
            }
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        left.empty() ? right.pop() : left.pop();
    }
    
    // Get the top element.
    int top() {
        return left.empty() ? right.front() : left.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return left.empty() && right.empty();
    }
};

int main(int argc, const char * argv[]) {
    Stack s = Stack();
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
