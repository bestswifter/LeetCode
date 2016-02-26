/*
	题目分析：从数组中找到第一个不连续的正数

	解题思路：和第268题思路相同
*/

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i + 1)
            return i + 1;
    return nums.size() + 1;
}