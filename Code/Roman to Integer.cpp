/*
    问题描述：
    把罗马数字转换成十进制阿拉伯数字

    思路很简单，对于L、X、C这三个字母，判断它后面的一个数字是不是比它大，如果是的话后面的减前面的
    如果不是这三个字母，直接找到对应的阿拉伯数字相加即可。
*/

int romanToInt(string s) {
    int result = 0;
    unordered_map<char, int> hashMap = {{'I',1}, {'V',5}, {'X',10}, {'L', 50}, {'C', 100}, {'D',500}, {'M',1000}};
    for (int i = 0; i < s.length(); ++i) {
        if ((s[i] == 'I' || s[i] == 'X' || s[i] == 'C') && i < (int)s.length() - 1) {
            int current = hashMap[s[i]], next = hashMap[s[i+1]];
            if (next > current) {
                result += next - current;
                ++i;
                continue;
            }
            result += current;
        }
        else {
            result += hashMap[s[i]];
        }
    }
    return result;
}