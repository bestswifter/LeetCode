/*
    解题思想：

        和3Sum类似，多了一层遍历而已

    收获总结：

        1. 数组排序后可以进行一些优化，排除某些情况，比如最小的几个数加起来已经过大了，就可以停止了。
        2. 双指针的思想，在有序数组中通常可以起到降维的效果
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) {
        return result;
    }
    
    std::sort(nums.begin(), nums.end());
    int l = nums.size();
    
    for (int i = 0; i < l - 3; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;   // 跳过重复的元素
        }
        if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
            break;   // 预判，排除不可能的情况
        }
        if (nums[i] + nums[l-1] + nums[l-2] + nums[l-3] < target) {
            continue;
        }
        int threeSum = target - nums[i];
        
        for (int j = i + 1; j < l - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;   // 跳过重复的元素
            }
            if (nums[j] + nums[j+1] + nums[j+2] > threeSum) {
                break;   // 预判，排除不可能的情况
            }
            if (nums[j] + nums[l-1] + nums[l-2] < threeSum) {
                continue;
            }
            int twoSum = threeSum - nums[j];
            int m = j + 1, n = l - 1;
            while (true) {
                while (m > j + 1 && nums[m] == nums[m-1]) { ++m; }   // 跳过重复的元素
                while (n < l - 1 && nums[n] == nums[n+1]) { --n; }   // 跳过重复的元素
                if (m >= n) {
                    break;
                }
                if (nums[m] + nums[n] < twoSum) { ++m; }
                else if (nums[m] + nums[n] > twoSum) { --n; }
                else {    // 找到了一组解，加入result中，再往后查找
                    vector<int> tuple = {nums[i],nums[j],nums[m],nums[n]};
                    result.push_back(tuple);
                    ++m, --n;
                }
            }
        }
    }
    
    return result;
}