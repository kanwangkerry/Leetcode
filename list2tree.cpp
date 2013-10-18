
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *mid = head;
        ListNode *pre_mid = NULL;
        ListNode *pt = head;
        bool flag = false;
        if(pt == NULL)
            return NULL;
        while(pt->next != NULL){
            if(flag){
                flag = false;
            }
            else{
                flag = true;
                pre_mid = mid;
                mid = mid->next;
            }
            pt = pt->next;
        }
        TreeNode *left = NULL, *right = NULL;
        if(pre_mid != NULL){
            pre_mid ->next = NULL;
            left = sortedListToBST(head);
        }
        if(mid != NULL){
            right = sortedListToBST(mid->next);
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = left;
        root->right = right;
        return root;
    }
};
