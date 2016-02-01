/*
    题目解析：

        重新设计一个栈，修改它的push、pop方法，使得获取栈中最小元素的时间复杂度为O(1)

    方法：

        内部放两个栈，其中一个用于存储数据，另一个用于存储每次新发现的最小值。
*/

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