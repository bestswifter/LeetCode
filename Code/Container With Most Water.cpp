/*
    题解：

    假设在Xi的位置有一个最大值，显然从X1到Xi可以提取出一个严格旦增的数列，其他数字可以直接抛弃。这些数字不可能被选作边。
    同理，从Xi到Xn可以提取出一个严格单减的数列。

    考虑接下来的数字，左边的边一定出现在X1到Xi中，右边的边一定出现在Xi到Xn中。
    对于任何一条边，假设它是木桶的短边，则长边一定在另一侧离它尽可能远的地方且值不小于它
    所以可以用两个指针，从左右两侧向中间逼近
*/

int maxArea(vector<int>& height) {
    int result = 0, left = 0, right = 0;
    
    for (int begin = 0, end = (int)height.size() - 1; begin != end; ) {
        if (height[begin] < left) {
            ++begin;
            continue;
        }
        
        left = height[begin];
        
        if (height[end] < right) {
            --end;
            continue;
        }
        
        right = height[end];
        
        result = max((end - begin) * min(left, right), result);
        if (left < right) {
            ++begin;
        }
        else {
            --end;
        }
    }
    
    return result;
}