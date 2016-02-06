/*
	题目描述：给一个数组，和target，求出最接近target的三个数字和，返回这个和

	我的思路：模拟动态规划的思想，对于n个数来说，要找三个数，使它们的和最接近target，这有两种可能：这三个都在前n-1个数中，或只有两个数在前n-1个数中，第三个数是a[n-1]。问题在于这不是动态规划，时间复杂度是O(n^3)导致超时。

	正确思路：虽然计算所有可能性的时间复杂度是O(n^3)，但可以略去其中的一些情况。首先对数组排序，然后固定a[i]，如果a[i] + a[j] + a[k]已经大于target，那么需要减少这三个数的和来更接近target。所以这个时候a[i] + a[j+1] + a[k]的情况不用考虑，应该考虑a[i] + a[j] + a[k-1]。这样，在固定a[i]时，时间复杂度为O(n)，总的时间复杂度为O(n^2)

	收获：
		并不是一提到遍历，就需要很大的时间复杂度，如果合理选择，比如两个pointer从两端向中间逼近，时间复杂度只有O(n)
*/

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());	// 先对数组排序
    int sum = nums[0] + nums[1] + nums[nums.size() - 1], diff = abs(target - sum);	// 初始化的一些赋值
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        int j = i + 1, k = nums.size() - 1;	//j和k分别从两端向中间逼近
        while (j != k) {
            int newSum = nums[i] + nums[j] + nums[k];
            if (abs(target - newSum) < diff) {	// 如果比原来更接近target就更新sum和diff
                sum = newSum;
                diff = abs(target - newSum);
            }
            if (newSum > target) {	//根据情况判断是增加sum还是减少sum
                --k;
            }
            else {
                ++j;
            }
            if (sum == target) {	//如果已经相等，直接返回sum，不可能更接近了
                return sum;
            }
        }
    }
    return sum;
}

// 错误代码，时间复杂度太高
/*int oneSumClosest(vector<int>& nums, int target, int max) {
    if (max == 0) {
        return nums[0];
    }
    int diff = abs(nums[0] - target);
    int oneSum = nums[0];
    for (int i = 1; i <= max; ++i) {
        int newDiff = abs(nums[i] - target);
        if (newDiff < diff) {
            diff = newDiff;
            oneSum = nums[i];
        }
    }
    return oneSum;
}

int twoSumClosest(vector<int>& nums, int target, int max) {
    if (max == 1) {
        return nums[0] + nums[1];
    }
    int previousTwo = twoSumClosest(nums, target, max - 1);
    int previousOne = oneSumClosest(nums, target - nums[max], max - 1);
    return abs(target - previousTwo) < abs(target - nums[max] - previousOne) ? previousTwo : previousOne + nums[max];
}

int threeSumClosest(vector<int>& nums, int target, int max) {
    if (max == 2) {
        return nums[0] + nums[1] + nums[2];
    }
    int previousThree = threeSumClosest(nums, target, max - 1);
    int previousTwo = twoSumClosest(nums, target - nums[max], max - 1);
    return abs(target - previousThree) < abs(target - nums[max] - previousTwo) ? previousThree : previousTwo + nums[max];
}

int threeSumClosest(vector<int>& nums, int target) {
    return threeSumClosest(nums, target, nums.size() - 1);
}*/