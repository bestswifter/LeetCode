/*
	题目分析：找出和最大的子数组

	解题思路：运用动态规划的思想，记S[i]表示从0到i的数组中，和最大的子数组的和，则有：

		 = nums[i] if i == 0 或 S[i-1] < 0
	S[i]
		 = nums[i] + S[i-1]	 否则
*/

int maxSubArrayHelper(vector<int>& nums, int end, int &max) {
    if (end == 0) {
        return nums[0];
    }
    int m = maxSubArrayHelper(nums, end - 1, max);
    int cmax = m < 0 ? nums[end] : nums[end] + m;
    if (cmax > max) {
        max = cmax;
    }
    
    return cmax;
}

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    maxSubArrayHelper(nums, nums.size() - 1, maxSum);
    return maxSum;
}