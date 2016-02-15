/*
    题目分析：逆向的BFS，和第102题基本类似

    解题思路：在102题的基础上，颠倒数组即可。
*/

void buildVector(TreeNode *root, int depth, vector<vector<int>> &result) {
    if (!root) {
            return;
        }
    if (result.size() == depth) {
            result.push_back(vector<int>());
        }

    result[depth].push_back(root->val);

    buildVector(root->left, depth+1, result);
    buildVector(root->right, depth+1, result);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> temp;
    buildVector(root, 0, temp);
    vector<vector<int>> result;
    int length = temp.size();
    for (int i = 0; i < length; ++i) {
        result.push_back(temp[length-i-1]);
    }
    return result;
}