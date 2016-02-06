/*
	题目分析： 找出唯一一个出现次数为1的元素

	解题思路：利用异或运算的特性完成，x ^ x = 0
*/

int singleNumber(vector<int>& nums) {
    int i = nums[0];
    for (int j = 1; j < nums.size(); ++j) {
        i = i ^ nums[j];
    }
    return i;
}