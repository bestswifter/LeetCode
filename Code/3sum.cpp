/*
    题目简介：
    给定一个数组，找出所有不重复的，和为0的一组三个数

    解题思想：
    找两个和为定值的数已经做过，时间复杂度为O（n），本题只要在外面再套一个循环即可
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
        return result;
    }
    std::sort(nums.begin(), nums.end());
    unordered_map<int, int> hashMap;
    
    int previous = nums[0] - 1;
    for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]] = i;
    }
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] == previous) {
            continue;
        }
        previous = nums[i];
        
        int temp  = nums[i] - 1;
        for (int j = i + 1; j < nums.size(); ++j) {
            int numbersToFind = 0 - nums[i] - nums[j];
            if (nums[j] == temp) {
                continue;
            }
            temp = nums[j];
            if (hashMap.find(numbersToFind) != hashMap.end() && hashMap[numbersToFind] > j) {
                result.push_back({nums[i],nums[j],nums[hashMap[numbersToFind]]});
            }
        }
    }
    return result;
}