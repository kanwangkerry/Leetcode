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
    void flatten(TreeNode *root) {
        TreeNode *leftT = NULL;
        TreeNode *rightT = NULL;
        if(root == NULL)
            return;
        if(root->left != NULL){
            flatten(root->left);
            leftT=root->left;
        }
        if(root->right != NULL){
            flatten(root->right);
            rightT=root->right;
        }
        
        root->left = NULL;
        TreeNode *p;
        if(leftT!=NULL){
            p = leftT;
            while(p->right !=NULL){
                p = p->right;
            }
            p->right = rightT;  
            root->right = leftT;
        }
        else{
            root->right = rightT;            
        }
    }
};
