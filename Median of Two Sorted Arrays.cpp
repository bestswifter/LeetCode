class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0){
            return getSingleVectorMedian(nums2);
        }
        else if(nums2.size() == 0){
            return getSingleVectorMedian(nums1);
        }
        else if(nums1.size() == 1 && nums2.size() == 1){
            return (double)(nums1[0] + nums2[0]) / 2;
        }
        else{
            double median = myFind(nums1, nums2);
            if(median == -1){
                return myFind(nums2, nums1);
            }
            else{
                return median;
            }
        }
    }
    
    double myFind(vector<int>& nums1, vector<int>& nums2){
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
        int length = nums.size();
        if(length % 2 == 0){
            return (double)(nums[(length - 1) / 2] + nums[(length + 1) / 2]) / 2;
        }
        else{
            return (double)nums[(length - 1) / 2];
        }
    }
};