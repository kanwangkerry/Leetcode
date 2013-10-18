
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
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pbegin, 
    int pend, int ibegin, int iend){
        if(pbegin == pend) return NULL;
        int root = preorder[pbegin];

        int imid=0, pmid = 0;
        for(int i = ibegin ; i < iend ; i++){
            if(inorder[i] == root){
               imid = i;
               pmid = imid-ibegin+pbegin;
               break;
            }
        }
        TreeNode *root_node = new TreeNode(root);
        root_node -> left = buildTreeHelper(preorder, inorder, pbegin+1, pmid+1, ibegin, imid);
        root_node -> right = buildTreeHelper(preorder, inorder, pmid+1, pend, imid+1, iend);
        return root_node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeHelper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
       
    }
};
