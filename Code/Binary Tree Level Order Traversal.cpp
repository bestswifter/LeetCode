/*	
	题目分析：广度优先遍历一棵树

	解题思路：

		1. 使用迭代解法：维护两个队列，一个用于存放这一层的指针，另一侧存放子节点的指针

		2. 使用递归解法：需要判断何时向二维数组中添加一个新的一维数组
*/

/*
	迭代解法
*/
vector<vector<int>> levelOrder(TreeNode* root) {
   vector<vector<int>> result;
   if (!root) {
       return result;
   }
   queue<TreeNode*> nums1,nums2;
   nums1.push(root);
   
   while (!nums1.empty() || !nums2.empty()) {
       vector<int> row;
       if (!nums1.empty()) {
           while (!nums1.empty()) {
               row.push_back(nums1.front()->val);
               if (nums1.front()->left) {
                   nums2.push(nums1.front()->left);
               }
               if (nums1.front()->right) {
                   nums2.push(nums1.front()->right);
               }
               nums1.pop();
           }
       }
       else {
           while (!nums2.empty()) {
               row.push_back(nums2.front()->val);
               if (nums2.front()->left) {
                   nums1.push(nums2.front()->left);
               }
               if (nums2.front()->right) {
                   nums1.push(nums2.front()->right);
               }
               nums2.pop();
           }
       }
       result.push_back(row);
   }
   return result;
}

/*
	递归解法：
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
    vector<vector<int>> result;
    buildVector(root, 0, result);
    return result;
}