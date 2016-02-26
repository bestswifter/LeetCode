/*
    题目分析：给出从 0 到 n 中的 n 个数，找到缺少的那个。

    解题思路：把i放到数组下标为i的地方，最后对应不上的就是缺少的数
*/

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != i && nums[i] < n) {
            swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    return nums.size();
}