
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

   
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *t;
        if(root == NULL)
            return result;
        
        t = root;
        
        while(t != NULL || !s.empty()){
            while(t != NULL){
                s.push(t);
                t = t->left;
            }
            t = s.top();    
            s.pop();
            result.push_back(t->val);
            t = t->right;
            
        }
        return result;
    }
};
