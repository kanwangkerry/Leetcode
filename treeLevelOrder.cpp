
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        queue<TreeNode*> q;
        TreeNode *t;
        if(root == NULL)
            return result;
        q.push(root);
        int len = 1;
        int index = 0;
        int level = 0;
        result.push_back(*(new vector<int>(len)));
        while(!q.empty()){
            t = q.front();
            q.pop();
            result[level][index] = t->val;
            index ++;
             if(t->left != NULL){
                q.push(t->left);
            }
            if(t->right != NULL){
                q.push(t->right);
            }
            if(index == len && !q.empty()){
                len = q.size();
                index = 0;
                result.push_back(*(new vector<int>(len)));
                level ++;
            }
           
        }
        return result;
    }
};
