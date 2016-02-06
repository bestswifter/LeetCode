class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        std::stack<int> stack;
        bool found = false;
        int factor = 1;
    
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] < '1' || str[i] > '9') {
                if (found) {
                    if (str[i] == '0') {
                        stack.push(0);
                    }
                    else {
                        break;  // 有效的数字结束
                    }
                }
                else {
                    switch (str[i]) {
                        case '-':
                            factor = -1;
                            found = true;
                            break;
                        case '+':
                            factor = 1;
                            found = true;
                            break;
                        case ' ':
                        case '0':
                            continue;
                            break;
                        default:
                            return 0;
                    }
                }
            } else {  // 找到了第一个有效数字
                found = true;
                stack.push(str[i] - 48);
            }
        }
    
        for (int i = 0; !stack.empty(); ++i) {
            result += std::pow(10, i) * stack.top() * factor;
            if (result > INT_MAX) {
                result = 2147483647;
                break;
            }
            else if (result < INT_MIN) {
                result = -2147483648;
                break;
            }
            stack.pop();
        }
    
        return (int)result;   
    }
};