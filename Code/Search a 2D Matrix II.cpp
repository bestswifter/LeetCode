/*
	题目分析： 矩阵中每一行，每一列都是单调递增的，设计一种算法查找矩阵中某个元素是否存在

	解题思路：从右上角开始，如果这个元素比target大，则删去那一列，如果比target小则删除那一行。直到找到为止
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) { return false; }
    int row = 0, column = matrix[0].size() - 1;
    
    while (row < matrix.size() && column >= 0) {
        if (matrix[row][column] == target) { return true;}
        else if (matrix[row][column] > target) {--column;}
        else {++row;}
    }
    return false;
}