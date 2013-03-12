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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        int i = 0;
        while(i < n){
            p = p->next;
            i++;
        }
        if(p == NULL) return head->next;
        while(p->next != NULL){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
        
        
    }
};
