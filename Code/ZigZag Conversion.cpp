class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || s.size() == 0) {return s;}
        string returnString(s);
        int t = 2 * numRows - 2;
        
        for(int i = 1; i <= s.size(); i++){
            if(i % t == 0){
                //说明在一各周期的最后一个位置
                returnString[(s.size() - 1) / t + 1 + (t == 2 ? (i - 1) / t : 2 * i / t - 1)] = s[i - 1];
            }
            else{
                int root = i % t <= numRows ? i % t : 2 * numRows - i % t;  // 找到这个数所在行最左边的数字
                int offset = i % t <= numRows ? ((root % numRows <= 1) ? 1 : 2) * (i / t) : 2 * (i / t) + 1;  //计算和最左边的数字的偏移量
                int pos = ((2 * root - 3) < 0 ? 0 : (2 * root - 3))  * (s.size() / t) + (s.size() % t <= root - 1 ? s.size() % t : root - 1 + std:: max(0, (int)(s.size() % t - 2 * numRows + root)));  // 计算root在新的字符串中的下标
                returnString[pos + offset] = s[i - 1];
            }
        }
        return returnString;
    }
};