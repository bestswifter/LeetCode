/*
    题目分析：用两个栈实现队列。

    解题思路：push都放在右侧栈，pop都从左侧栈拿出。当左侧栈空了时，逆序将右侧栈中所有元素放到左侧
*/

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