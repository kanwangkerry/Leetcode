
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
        ListNode *q;
        while(p != NULL){
            q = p->next;
            while(q!= NULL && q->val == p->val){
                p->next = q->next;
                q = p->next;
            }
            p = q;
        }
        return head;
    }
};
