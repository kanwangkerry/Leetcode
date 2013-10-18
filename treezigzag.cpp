
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        int level = 0, len = 1, index = 0;
        q.push(root);
        TreeNode *t;
        result.push_back(* (new vector<int>(len)));
        while(!q.empty()){
            t = q.front();
            q.pop();
            result[level][index] = t->val;
            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);
            if(level%2){
                index --;
            }
            else{
                index ++;
            }
            if(index == -1){
                if(q.empty())
                    break;
                level += 1;
                index = 0;
                len = q.size();
                result.push_back( *(new vector<int>(len)));
            }
            if(index == len){
                if(q.empty())
                    break;
                level += 1;
                len = q.size();
                index = len -1;
                result.push_back(*(new vector<int>(len)));
            }
        }
        return result;
    }
};
