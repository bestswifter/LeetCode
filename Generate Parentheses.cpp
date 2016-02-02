/*
    题目分析，给定数字n，输出n对有效的圆括号，要根据指定的格式输出。

    观察一下n=4的解答就可以发现以下规律，为了更容易发现，用1代替"(", 用0代替")"

    11110000
    11101000
    11100100
    11100010
    11011000
    11010100
    11010010
    11001100
    11001010
    10111000
    10110100
    10110010
    10101100
    10101010

    规律是输出时总是尽可能希望把1放在前面，也就是说能放1就放1，不能放1就放0.放0是需要保证到目前为止出现的0的次数不超过1

    所以构造了一个辅助的helper函数，参数l和r分别表示左括号和右括号还剩几个，参数s表示当前的字符串

    如果都不剩了，那么当前字符串一定已经满了，可以加到结果中

    否则，如果l还大于0就先加"("，同时l减一递归调用helper函数。
    如果剩下的右括号比左括号多，也就是r > l，此处还可以选择右括号。

    在generateParenthesis，调用helper函数，传入空字符串，l和r的值都是n表示初始条件下左右括号各剩n个
*/

void helper(vector<string> &v, string s, int l, int r) {
    if (l == 0 && r == 0) {
        v.push_back(s);
    }

    if (l > 0) { helper(v, s+'(', l-1, r); }
    if (r > l) { helper(v, s+')', l, r-1); }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper(result, "", n, n);
    return result;
}

/*
    错误解法：虽然输出内容正确，但是顺序错误

    vector<string> generateParenthesis(int n) {
        if (n < 2) {
            return n == 1 ? vector<string>({"()"}) : vector<string>({});
        }
        
        vector<string> base = generateParenthesis(n-1);
        int l = base.size();
        for (int i = 0; i < l; ++i) {
            base.push_back(base[i] + "()");
            
            if (i != l - 1) {
                base.push_back("()" + base[i]);
            }
            base[i] = '(' + base[i] + ')';
        }
        return base;
    }

*/