/*
    题目分析：找出数组中仅有的两个 只出现一次的数字

    解题思路: 首先全部异或一遍，得到的结果是两个只出现一次的数的异或结果。找到这个结果中第一个1（一定存在，
    不然就是0了）。这说明原来两个数在这一位上一定一个是1，一个是0.

    再遍历一次数组，把数组中所有数字分为两种，一种是这一位是0，一种是这一位上是1.显然相同的数字只会分到统一组中
    但要求的两个数字肯定分别处于两个组中。然后这个两个组中的数字，异或的结果就分别是要求的两个数字了。

*/

bool isOneAtBit(int number, int bit) {
    for (int i = 0; i < bit; ++i) {
        number = number >> 1;
    }
    return number & 1;
}

vector<int> singleNumber(vector<int>& nums) {
    int xorNum = 0, bitOfOne = 0, a = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
        xorNum ^= nums[i];
    }
    while (xorNum != 0 && (xorNum & 1) == 0) {
        ++bitOfOne;
        xorNum = xorNum >> 1;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (isOneAtBit(nums[i], bitOfOne)) {
            a ^= nums[i];
        }
        else {
            b ^= nums[i];
        }
    }
    return {a, b};
}