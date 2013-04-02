/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *temp;
  
        while(root != NULL){   
            temp = root;
            while(temp != NULL){
                if(temp->left != NULL){
                    temp->left->next = temp->right;
                     if(temp->next != NULL){
                        temp->right->next = temp->next->left;
                    }
                }
                temp = temp->next;
            }
            root = root->left;
        }
        
    }
};
