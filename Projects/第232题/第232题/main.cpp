//
//  main.cpp
//  第232题
//
//  Created by 张星宇 on 16/2/5.
//  Copyright © 2016年 zxy. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Queue {
    stack<int> left;
    stack<int> right;
public:
    // Push element x to the back of queue.
    void push(int x) {
        right.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if (left.empty()) {
            reverse();
        }
        left.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if (left.empty()) {
            reverse();
        }
        return left.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return left.empty() && right.empty();
    }
    
private:
    void reverse() {
        while (!right.empty()) {
            left.push(right.top());
            right.pop();
        }
    }
};

int main(int argc, const char * argv[]) {
    Queue q = Queue();
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    q.pop();
    q.push(3);
    q.pop();
    cout << q.peek() << endl;
    return 0;
}
