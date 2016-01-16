class Solution {
public:
    int reverse(int x) {
        std::stack<int> stack;
        long result = 0;
    
        while (x != 0) {
            stack.push(x % 10);  // 把每一位数字放到数组中
            x /= 10;
        }
    
        for (int i = 0; !stack.empty(); ++i) {
            result += std::pow(10, i) * stack.top();
            stack.pop();
        }   
        return result > INT_MAX || result < INT_MIN ? 0 : (int)result;
    }
};