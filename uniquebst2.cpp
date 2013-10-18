
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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(1, n);
    }
    
    vector<TreeNode *> generate(int begin, int end) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> result, lsub, rsub;
        if(begin > end){
            result.push_back(NULL);
            return result;
        }
        if(begin == end){
            result.push_back(new TreeNode(begin));
            return result;
        }
        TreeNode* root;
        for(int i = begin ; i <= end ; i++){
            lsub = generate(begin, i-1);
            rsub = generate(i+1, end);
            for(TreeNode *l:lsub){
                for(TreeNode *r:rsub){
                    root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
    }
};
