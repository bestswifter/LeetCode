/*
    题目分析：找到第 n 个丑数

    解题思路：用一个数组保存已有的丑数，然后分别用最接近这个丑数的三个数乘以 2、3、5，取最小即可。
    这是O(n) 时间复杂度的算法，相当于用空间换时间
*/

int nthUglyNumber(int n) {
    vector<long> uglyNumbers = vector<long>(n);
    uglyNumbers[0] = 1;
    int twoIndex = 0, threeIndex = 0, fiveIndex = 0;
    for (int i = 1; i < n; ++i) {
        long a = uglyNumbers[twoIndex], b = uglyNumbers[threeIndex], c = uglyNumbers[fiveIndex];
        uglyNumbers[i] = a * 2 < b * 3 ? min(a * 2, c * 5) : min(b * 3 , c * 5);
        while (a * 2 <= uglyNumbers[i]) {
            ++twoIndex;
            a *= 2;
        }
        while (b * 3 <= uglyNumbers[i]) {
            ++threeIndex;
            b *= 3;
        }
        while (c * 5 <= uglyNumbers[i]) {
            ++fiveIndex;
            c *= 5;
        }
    }
    return (int)uglyNumbers[n - 1];
}