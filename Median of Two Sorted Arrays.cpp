class Solution {
public:
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
        double median = myFind(nums1, nums2, 1);
        if(median == -1){
            std::cout << "开始反向测试" << endl;
            return myFind(nums2, nums1, 2);
        }
        else{
            return median;
        }
    }
    
    double myFind(vector<int>& nums1, vector<int>& nums2, int arrayName){
        int size1 = nums1.size(), size2 = nums2.size(), left2, right2;
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
                else{
                    isEqual = true;
                    break;
                }
            }
            int direction = 0;
            if(isEqual){  // index2和index1处值相同
                direction = target - index1 - index2 - (size1 + size2) % 2;
                std::cout << "Equal!! target = " << target << " index1 = " << index1 << " index2 = " << index2 << " direction = " << direction << endl;
                if((size1 + size2) % 2 == 1){
                    if(direction > 0){
                        if(direction == 1){
                            std::cout << "取后一个值 index1处的值为 " <<  nums1[index1] << " 另一个数是 " << getNextMedian(nums1, nums2, index1, index2, arrayName) << endl;
                            return (double)getNextMedian(nums1, nums2, index1, index2, arrayName);
                        }
                        left1 = index1 + 1;
                    }
                    else if(direction < 0){
                        right1 = index1 - 1;
                    }
                    else{
                        std::cout << "返回一个数为 " << nums1[index1] << endl;
                        return (double)nums1[index1];
                    }
                }
                else{
                    if(direction > 0){
                        if(direction == 1){
                            std::cout << "取平均值 index1处的值为 " <<  nums1[index1] << " 另一个数是 " << getNextMedian(nums1, nums2, index1, index2, arrayName) << endl;
                            return (double)(nums1[index1] + getNextMedian(nums1, nums2, index1, index2, arrayName)) / 2;
                        }
                        left1 = index1 + 1;
                    }
                    else if(direction < 0){
                        right1 = index1 - 1;
                    }
                    else{
                        std::cout << "取平均值 index1处的值为 " <<  nums1[index1] << " 另一个数是 " << nums2[index2] << endl;
                        return (double)(nums1[index1] + nums2[index2]) / 2;
                    }
                }
            }
            else{  //index2处的值小于index1
                direction = target - index1 - index2;
                if (nums2[index2] <= nums1[index1]) {
                    --direction;
                }
                std::cout << "Not Equal!! target = " << target << " index1 = " << index1 << " index2 = " << index2 << " direction = " << direction << endl;
                if((size1 + size2) % 2 == 1){
                    if(direction > 0){
                        left1 = index1 + 1;
                    }
                    else if(direction < 0){
                        right1 = index1 - 1;
                    }
                    else if(nums2[index2] <= nums1[index1] || (nums2[index2] > nums1[index1] && index1 == target)){
                        std::cout << "返回一个数为 " << nums1[index1] << endl;
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
                        std::cout << "取平均值 index1处的值为 " <<  nums1[index1] << " 另一个数是 " << getNextMedian(nums1, nums2, index1, index2, arrayName) << endl;
                        return (double)(nums1[index1] + getNextMedian(nums1, nums2, index1, index2, arrayName)) / 2;
                    }
                    else if(nums2[index2] > nums1[index1] && index1 == target){
                        std::cout << "取平均值 index1处的值为 " <<  nums1[index1] << " index2处的值是 " << nums2[index2] << endl;                   
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
    
    int getNextMedian(vector<int>& nums1, vector<int>& nums2, int index1, int index2, int arrayName){
        if(arrayName == 1){  //index属于第一个数组
            if(index1 == nums1.size() - 1){
                return nums2[index2 + 1];
            }
            if(index2 == nums2.size() -1 ){
                return nums1[index1 + 1];
            }
            return nums1[index1 + 1] < nums2[index2 + 1] ? nums1[index1 + 1] : nums2[index2 + 1];
        }
        else{
            if(index2 == nums2.size() - 1){
                return nums1[index1 + 1];
            }
            if(index1 == nums1.size() - 1){
                return nums2[index2 + 1];
            }
            return nums1[index1 + 1] < nums2[index2 + 1] ? nums1[index1 + 1] : nums2[index2 + 1];
        }
    }
    
    double getSingleVectorMedian(vector<int>& nums){
        int length = nums.size();
        if(length % 2 == 0){
            return (double)(nums[(length - 1) / 2] + nums[(length + 1) / 2]) / 2;
        }
        else{
            return (double)nums[(length - 1) / 2];
        }
    }
};