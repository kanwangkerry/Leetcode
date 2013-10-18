
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() == 0)
            return NULL;
        return buildHelper(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
    TreeNode *buildHelper(vector<int> &inorder, vector<int> &postorder, int ibegin, int iend,
    int pbegin, int pend){
        int root, imid, pmid;
        if(ibegin == iend)
            return NULL;
        root = postorder[pend-1];
        for(int i = ibegin; i < iend ; i++){
            if(inorder[i] == root){
                imid = i;
                pmid = imid-ibegin + pbegin;
            }
        }
        TreeNode *root_node = new TreeNode(root);
        root_node->left = buildHelper(inorder, postorder, ibegin, imid, pbegin, pmid);
        root_node->right = buildHelper(inorder, postorder, imid+1, iend, pmid, pend-1);
        return root_node;
    }
};
