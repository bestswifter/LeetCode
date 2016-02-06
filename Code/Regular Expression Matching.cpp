/*题解：
    要求：

    给定字符串s和正则表达式p，判断s和p是否匹配

    错误思路，以匹配"abccccd"和"a.c*d"为例：

    1. s和p的第一个字符"a"匹配
    2. s的第二个字符"b"和p的第二个字符"."匹配
    3. s和p的第三个字符"c"匹配
    4. s的第四个字符和第三个字符相同，p的第四个字符是"*"，匹配
    5. 直到s的最后一个字符前都匹配
    6. s和p的最后一个字符d匹配

    问题在于，正则表达式".*"可以匹配一切，以上思路无法处理

    正确思路：

    使用动态规划的思想，记r[i][j]表示s[0..i]和p[0.j]是否匹配。

    状态转移方程是：
    r[i][j] = r[i-1][j-1]  如果p[j-1] != "*" 且p[j-1] = s[i-1]或p[j-1] = "."
    r[i][j] = r[i][j-2]  如果p[j-1] == "*" 且 p[j-2]并没有重复
    r[i][j] = r[i-1][j]  如果p[j-1] == "*" 且 p[j-2]重复至少一次

    实际处理中，考虑下面两点：

    如果r[i][j-2] = true且p[j-1] == "*"，则不用判断p[j-2]重复几次，总是可以认为它重复0次，因此r[i][j] = r[i][j-2]
    对于边界情况，r[0][0] = true, r[0][j] = false，因为空字符串显然不能匹配非空正则表达式
*/

bool isMatch(string s, string p) {
    int sLenght = s.length(), pLength = p.length();
    vector<vector<bool>> r(sLenght + 1, vector<bool>(pLength + 1, false));
    r[0][0] = true;
    for (int i = 0; i < sLenght + 1; ++i) {
        for (int j = 1; j < pLength + 1; ++j) {
            if (p[j - 1] == '*') {
                r[i][j] = r[i][j-2] || (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) && r[i-1][j];
            }
            else {
                r[i][j] = i > 0 && r[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
            }
        }
    }
    
    return r[sLenght][pLength];
}