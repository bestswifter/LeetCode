/*
    这题没什么说的，栈的基本使用。
*/

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