
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        prev = NULL;
        w1 = NULL;
        w2 = NULL;
        traverse(root);

        if(w1 != NULL && w2 != NULL)
            swap(w1, w2);
        if(w1 != NULL && w2 == NULL){
            swap(w1, prev);
        }
    }
    
    TreeNode *prev = NULL;
    TreeNode *w1 = NULL;
    TreeNode *w2 = NULL;
    
    void swap(TreeNode* n1, TreeNode* n2){
        int temp = 0;
        temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
    }
    
    void traverse(TreeNode *root){
        if(root == NULL)
            return;
        traverse(root->left);
        if(prev != NULL){
            if(prev->val > root->val && w1 == NULL){
                w1 = prev;
            }
            if(prev->val > root->val && w1 != NULL){
                w2 = root;
            }
        }
        prev = root;
        traverse(root->right);
    }
};
