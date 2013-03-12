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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int d_left, d_right;
        bool left, right;
        if(root == NULL) return true;
        if(root->left == NULL){
            left = true;
            d_left = 0;
        }
        else{
            left = isBalanced(root->left);
            d_left = root->left->val;
            
        }
        if(root->right == NULL){
            d_right = 0;
            right = true;
        }
        else{
            right = isBalanced(root->right);
            d_right = root->right->val;
        }
        root->val = (d_right > d_left)?d_right:d_left;
        root->val = root->val+1;
        if(left && right && (abs(d_left - d_right) <= 1)) return true;
        else return false;
    }
};
