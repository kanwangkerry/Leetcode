/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *result, *result_index;
        int c, u=0;
        ListNode *n1=l1;
        ListNode *n2=l2;
        
        c = n1->val + n2->val;
            if(c>=10){
                u = 1;
                c = c-10;
            }
            else u = 0;
            result_index= new ListNode(c);
            result = result_index;
            n1 = n1->next;
            n2 = n2->next;

        while(n1 != NULL && n2 != NULL){
            c = n1->val + n2->val + u;
            if(c>=10){
                u = 1;
                c = c-10;
            }
            else u = 0;
            result_index->next = new ListNode(c);
            result_index = result_index->next;            
            n1 = n1->next;
            n2 = n2->next;
        }
        while(n1 != NULL){
            c = n1->val + u;
            if(c>=10){
                u =1;
                c = c-10;
            }
            else u = 0;
            result_index->next = new ListNode(c);
            result_index = result_index->next;            
            n1 = n1->next;
        }
         while(n2 != NULL){
            c = n2->val + u;
            if(c>=10){
                u =1;
                c = c-10;
            }
            else u = 0;
            result_index->next = new ListNode(c);
            result_index = result_index->next;            
            n2 = n2->next;
        }
        if(u != 0) result_index->next =new ListNode(u);
        result_index = result_index->next;
        return result;
    }
};
