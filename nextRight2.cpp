
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
                if(temp->left != NULL && temp->right != NULL){
                    temp->left->next = temp->right;

                }
                else if(temp->left != NULL && temp->right ==NULL){
                    if(temp->next != NULL){
                        temp->left->next = getFirst(temp->next);
                    }
                }
                if(temp->right != NULL){
                    if(temp->next != NULL){
                        temp->right->next = getFirst(temp->next);
                    }
                    
                }
                temp = temp->next;
            }
            root = getFirst(root);
        }
        
    }
    
    TreeLinkNode *getFirst(TreeLinkNode *parent){
        if(parent->left != NULL) return parent->left;
        if(parent->right != NULL) return parent->right;
        if(parent->next != NULL) return getFirst(parent->next);
        return NULL;
        
    }
};
