/*
	题目分析：判断二叉树是否为二叉搜索树，难点在于左右结点不仅需要与父节点比较，还需要与父节点的祖先比较。

	解题思路：可以根据定义，判断根节点是否比左子树中所有元素大，是否比右子树中所有节点小。然后递归判断左右子树是否是二叉搜索树。缺点在于时间复杂度较高。

	改进思路：根据二叉搜索树的定义，它的中序遍历结果是严格单调递增的数列。只要在构造这个数列时判断新加入的数字是否比原来的最后一个大即课。
*/	

// 利用中序遍历实现：
bool inorder(TreeNode *root, vector<int> &v, bool &flag) {
    if (!root) {
        return true;
    }
    inorder(root->left,v, flag);
    v.push_back(root->val);
    if (v.size() > 1 && v[v.size()-2] >= root->val) {
        flag = false;
    }
    inorder(root->right,v, flag);
    return flag;
}

bool isValidBST(TreeNode* root) {
    vector<int> temp;
    bool flag = true;
    return inorder(root, temp, flag);
}

// 按照定义实现
void buildVector(TreeNode *root, vector<int> &v) {
    if (!root) {
        return ;
    }
    v.push_back(root->val);
    buildVector(root->left, v);
    buildVector(root->right, v);
}
bool isValidBST(TreeNode* root) {
   if (!root) {
       return true;
   }
   if (root->left) {
       vector<int> temp;
       buildVector(root->left, temp);
       for (int i = 0; i < temp.size(); ++i) {
           if (temp[i] >= root->val) {
               return false;
           }
       }
   }
   if (root->right) {
       vector<int> temp;
       buildVector(root->right, temp);
       for (int i = 0; i < temp.size(); ++i) {
           if (temp[i] <= root->val) {
               return false;
           }
       }
   }
   return isValidBST(root->left) && isValidBST(root->right);
}