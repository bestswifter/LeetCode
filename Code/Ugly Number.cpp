/*
    题目分析：丑数是指 只含有 2、3、5 因子的正整数

    解题思路：循环除以2、3、5即可。如果是丑数，最后的结果应该是1
*/

bool isUgly(int num) {
    if (num <= 0) { return false; }
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}