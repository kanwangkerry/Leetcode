
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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        lastNode = NULL;
        return traverse(root);
        
    }
    
    TreeNode *lastNode = NULL;
    bool traverse(TreeNode *root){
        if(root == NULL)
            return true;
        if(!traverse(root->left))
            return false;
        if(lastNode != NULL && lastNode->val >= root->val)
            return false;
        lastNode = root;
        if(!traverse(root->right))
            return false;
        if(lastNode != root && lastNode->val <= root->val)
            return false;
        return true;
    }
};
