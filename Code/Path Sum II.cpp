/*
    题目分析：找到一条路径，使得所有节点的和为sum。打印出所有的路径

    解题思路：可以使用DFS的思想，用一个栈来记录当前路径中的节点。
*/

void findPath(TreeNode* root, int sum, vector<int> &row, vector<vector<int>> &result) {
    if (!root->left && !root->right) {
        if (sum == 0) {
            result.push_back(row);
        }
        return;
    }
    if (root->left) {
        row.push_back(root->left->val);
        findPath(root->left, sum - root->left->val, row, result);
        row.pop_back();
    }
    if (root->right) {
        row.push_back(root->right->val);
        findPath(root->right, sum - root->right->val, row, result);
        row.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    
    vector<int> row;
    row.push_back(root->val);
    findPath(root, sum - root->val, row, result);
    return result;
}