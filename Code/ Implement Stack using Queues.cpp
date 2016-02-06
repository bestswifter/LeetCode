/*
    题目分析：用队列实现栈

    解题思路：push操作比较复杂，需要先向空队列中添加元素，然后把另一个队列的所有元素按顺序移到这个队列中。
*/

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