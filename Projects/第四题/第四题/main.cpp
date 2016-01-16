//
//  main.cpp
//  第四题
//
//  Created by 张星宇 on 15/9/19.
//  Copyright © 2015年 张星宇. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double myFind(vector<int>& nums1, vector<int>& nums2);
int getNextMedian(vector<int>& nums1, vector<int>& nums2, int index1, int index2);
double getSingleVectorMedian(vector<int>& nums);
bool equals(double value, double correntAnswer);

int main(int argc, const char * argv[]) {
    vector<int> v1 = {1,2};
    vector<int> v2 = {0,1,2};
    vector<int> v3 = {0,1};
    vector<int> v4 = {0};
    vector<int> v5 = {0,1,2,3};
    vector<int> v6 = {1,2,3,4,5};
    vector<int> v7 = {2,4};
    vector<int> v8 = {1};
    vector<int> v9 = {2,3,4,5};
    vector<int> v10 = {1,2,3};
    vector<int> v11 = {100000};
    vector<int> v12 = {100001};
    vector<int> v13 = {3};
    vector<int> v14 = {3,4};
    vector<int> v15 = {2,3,4};
    vector<int> v16 = {1,3};
    vector<int> v17 = {2};
    vector<int> v18 = {4};
    vector<int> v19 = {1,2,3};
    vector<int> v20 = {1,2,5};
    vector<int> v21 = {3,4,6};
    
    if(!equals(findMedianSortedArrays(v1,v2), 1)){
        std::cout << "第一组正向测试出错，输出值为:" << findMedianSortedArrays(v1,v2) << "标准值为" << 1 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v2,v1), 1)){
        std::cout << "第一组反向测试出错，输出值为:" << findMedianSortedArrays(v2,v1) << "标准值为" << 1 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v1,v3), 1)){
        std::cout << "第二组正向测试出错，输出值为:" << findMedianSortedArrays(v1,v3) << "标准值为" << 1 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v3,v1), 1)){
        std::cout << "第二组反向测试出错，输出值为:" << findMedianSortedArrays(v3,v1) << "标准值为" << 1 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v1,v4), 1)){
        std::cout << "第三组正向测试出错，输出值为:" << findMedianSortedArrays(v1,v4) << "标准值为" << 1 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v4,v1), 1)){
        std::cout << "第三组反向测试出错，输出值为:" << findMedianSortedArrays(v4,v1) << "标准值为" << 1 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v1,v5), 1.5)){
        std::cout << "第四组正向测试出错，输出值为:" << findMedianSortedArrays(v1,v5) << "标准值为" << 1.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v5,v1), 1.5)){
        std::cout << "第四组反向测试出错，输出值为:" << findMedianSortedArrays(v5,v1) << "标准值为" << 1.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v6,v7), 3)){
        std::cout << "第五组正向测试出错，输出值为:" << findMedianSortedArrays(v6,v7) << "标准值为" << 3 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v7,v6), 3)){
        std::cout << "第五组反向测试出错，输出值为:" << findMedianSortedArrays(v7,v6) << "标准值为" << 3 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v8,v9), 3)){
        std::cout << "第六组正向测试出错，输出值为:" << findMedianSortedArrays(v8,v9) << "标准值为" << 3 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v9,v8), 3)){
        std::cout << "第六组反向测试出错，输出值为:" << findMedianSortedArrays(v9,v8) << "标准值为" << 3 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v1,v10), 2)){
        std::cout << "第七组正向测试出错，输出值为:" << findMedianSortedArrays(v6,v7) << "标准值为" << 2 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v10,v1), 2)){
        std::cout << "第七组反向测试出错，输出值为:" << findMedianSortedArrays(v7,v6) << "标准值为" << 2 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v11,v12), 100000.5)){
        std::cout << "第八组正向测试出错，输出值为:" << findMedianSortedArrays(v11,v12) << "标准值为" << 100000.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v12,v11), 100000.5)){
        std::cout << "第八组反向测试出错，输出值为:" << findMedianSortedArrays(v12,v11) << "标准值为" << 100000.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v1,v13), 2)){
        std::cout << "第九组正向测试出错，输出值为:" << findMedianSortedArrays(v1,v13) << "标准值为" << 2 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v13,v1), 2)){
        std::cout << "第九组反向测试出错，输出值为:" << findMedianSortedArrays(v13,v1) << "标准值为" << 2 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v1,v14), 2.5)){
        std::cout << "第十组正向测试出错，输出值为:" << findMedianSortedArrays(v1,v13) << "标准值为" << 2.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v14,v1), 2.5)){
        std::cout << "第十组反向测试出错，输出值为:" << findMedianSortedArrays(v13,v1) << "标准值为" << 2.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v4,v10), 1.5)){
        std::cout << "第十一组正向测试出错，输出值为:" << findMedianSortedArrays(v4,v10) << "标准值为" << 1.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v10,v4), 1.5)){
        std::cout << "第十一组反向测试出错，输出值为:" << findMedianSortedArrays(v10,v4) << "标准值为" << 1.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v15,v8), 2.5)){
        std::cout << "第十二组正向测试出错，输出值为:" << findMedianSortedArrays(v15,v8) << "标准值为" << 2.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v8,v15), 2.5)){
        std::cout << "第十二组反向测试出错，输出值为:" << findMedianSortedArrays(v8,v15) << "标准值为" << 2.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v16,v17), 2)){
        std::cout << "第十三组正向测试出错，输出值为:" << findMedianSortedArrays(v16,v17) << "标准值为" << 2 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v17,v16), 2)){
        std::cout << "第十三组反向测试出错，输出值为:" << findMedianSortedArrays(v17,v16) << "标准值为" << 2 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v18,v19), 2.5)){
        std::cout << "第十四组正向测试出错，输出值为:" << findMedianSortedArrays(v18,v19) << "标准值为" << 2.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v19,v18), 2.5)){
        std::cout << "第十四组反向测试出错，输出值为:" << findMedianSortedArrays(v19,v18) << "标准值为" << 2.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v20,v21), 3.5)){
        std::cout << "第十五组正向测试出错，输出值为:" << findMedianSortedArrays(v20,v21) << "标准值为" << 3.5 << std::endl;
    }
    if(!equals(findMedianSortedArrays(v21,v20), 3.5)){
        std::cout << "第十五组反向测试出错，输出值为:" << findMedianSortedArrays(v21,v20) << "标准值为" << 3.5 << std::endl;
    }
    
    std::cout << "测试结束" << endl;
    
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() == 0){
        return getSingleVectorMedian(nums2);
    }
    if(nums2.size() == 0){
        return getSingleVectorMedian(nums1);
    }
    if(nums1.size() == 1 && nums2.size() == 1){
        return (double)(nums1[0] + nums2[0]) / 2;
    }
    double median = myFind(nums1, nums2);
    if(median == -1){
        return myFind(nums2, nums1);
    }
    else{
        return median;
    }
}

double myFind(vector<int>& nums1, vector<int>& nums2){
    int size1 = (int)nums1.size(), size2 = (int)nums2.size(), left2, right2;
    int left1 = 0, right1 = size1 - 1;
    int target = (size1 + size2 - 1) / 2;
    int index1 = 0, index2 = 0;
    
    while(left1 <= right1){
        index1 = (left1 + right1) / 2;
        left2 = 0; right2 = size2 - 1;
        bool isEqual = false;
        while(left2 <= right2){
            index2 = (left2 + right2) / 2;
            if(nums2[index2] > nums1[index1]){
                right2 = index2 - 1;
            }
            else if(nums2[index2] < nums1[index1] && (index2 == size2 - 1 || nums2[index2 + 1] <= nums1[index1])){
                left2 = index2 + 1;
            }
            else if(nums2[index2] == nums1[index1]){
                isEqual = true;
                break;
            }
            else{
                break;
            }
        }
        int direction = 0;
        if(isEqual){  // index2和index1处值相同
            direction = target - index1 - index2 - (size1 + size2) % 2;
            if((size1 + size2) % 2 == 1){
                if(direction > 0){
                    if(direction == 1){
                        return (double)getNextMedian(nums1, nums2, index1, index2);
                    }
                    left1 = index1 + 1;
                }
                else if(direction < 0){
                    right1 = index1 - 1;
                }
                else{
                    return (double)nums1[index1];
                }
            }
            else{
                if(direction > 0){
                    if(direction == 1){
                        return (double)(nums1[index1] + getNextMedian(nums1, nums2, index1, index2)) / 2;
                    }
                    left1 = index1 + 1;
                }
                else if(direction < 0){
                    right1 = index1 - 1;
                }
                else{
                    return (double)(nums1[index1] + nums2[index2]) / 2;
                }
            }
        }
        else{  //index2处的值小于index1
            direction = target - index1 - index2 - 1;
            if (nums2[index2] > nums1[index1]) {
                ++direction;
            }
            if((size1 + size2) % 2 == 1){
                if(direction > 0){
                    left1 = index1 + 1;
                }
                else if(direction < 0){
                    right1 = index1 - 1;
                }
                else if(nums2[index2] <= nums1[index1] || (nums2[index2] > nums1[index1] && index1 == target)){
                    return (double)nums1[index1];
                }
                else{
                    break;
                }
            }
            else{  //偶数
                if(direction > 0){
                    left1 = index1 + 1;
                }
                else if(direction < 0){
                    right1 = index1 - 1;
                }
                else if(nums2[index2] <= nums1[index1]){
                    return (double)(nums1[index1] + getNextMedian(nums1, nums2, index1, index2)) / 2;
                }
                else if(nums2[index2] > nums1[index1] && index1 == target){
                    if(index1 != size1 -1 && nums1[index1 + 1] < nums2[index2]){
                        return (double)(nums1[index1] + nums1[index1 + 1]) / 2;
                    }
                    return (double)(nums1[index1] + nums2[index2]) / 2;
                }
                else{
                    break;
                }
            }
        }
    }
    return -1;
}

int getNextMedian(vector<int>& nums1, vector<int>& nums2, int index1, int index2){
    if(index1 == nums1.size() - 1){
        return nums2[index2 + 1];
    }
    if(index2 == nums2.size() -1 ){
        return nums1[index1 + 1];
    }
    return nums1[index1 + 1] < nums2[index2 + 1] ? nums1[index1 + 1] : nums2[index2 + 1];
}

double getSingleVectorMedian(vector<int>& nums){
    int length = (int)nums.size();
    if(length % 2 == 0){
        return (double)(nums[(length - 1) / 2] + nums[(length + 1) / 2]) / 2;
    }
    else{
        return (double)nums[(length - 1) / 2];
    }
}

bool equals(double value, double correntAnswer){
    return fabs(correntAnswer - value) < 0.001;
}
