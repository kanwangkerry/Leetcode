
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *p = head;
        ListNode *prev, *q;
        while(p != NULL){
            q = p->next;
            while(q!= NULL && q->val == p->val)
                q = q->next;
            if(q != p->next){
                //remove from p to q
                if(p == head){
                    head = q;
                }
                else{
                    prev->next = q;
                }
            
            }
            else{
                prev = p;
            }
            p = q;
        }
        return head;
    }
};
