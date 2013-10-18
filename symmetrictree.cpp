
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        return mirrorTree(root->left, root->right);
    }
    
    bool mirrorTree(TreeNode *t1, TreeNode *t2){
        if(t1 == NULL && t2 == NULL)
            return true;
        if((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL))
            return false;
        return (t1->val == t2->val) && mirrorTree(t1->left , t2->right) && mirrorTree(t1->right, t2->left);
    }
};
