
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()== 0)
            return NULL;
        return arrayRangeToBST(num, 0, num.size());
    }
    
    TreeNode *arrayRangeToBST(vector<int> &num, int begin, int end){
        if(end - begin == 1)
            return new TreeNode(num[begin]);
        int mid = begin + (end - begin)/2;
        TreeNode *root = new TreeNode(num[mid]);
        if(mid != begin){
            root->left = arrayRangeToBST(num, begin, mid);
        }
        if(mid+1 != end){
            root->right = arrayRangeToBST(num, mid+1, end);
        }
        return root;
        
    }
};
