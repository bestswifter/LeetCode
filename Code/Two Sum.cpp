class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //至少要遍历一次数组，在寻找另一个下标时，使用hash表可以把把时间复杂度从遍历的O(N)降低到O(1)。
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            int numberToFind = target - nums[i];  // 要找的数，也是hash表的键
            if(hashMap.find(numberToFind) != hashMap.end()){
                //如果找到了，就直接返回vector了
                vector<int> vec;
                vec.push_back(hashMap[numberToFind]);  //因为第一次找到时，hash表中还没有数据，所以这里的i其实是比较大的那个下标，注意顺序
                vec.push_back(i+1);
                return vec;
            }
            //如果没找到，就把这条记录插入到hash表中。hash表的键是在数组中得值，而值是数组中的下标
            hashMap[nums[i]] = i + 1;
        }
        //该算法时间复杂度O（n），空间复杂度O（n）
    }
};