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
    ListNode *swapPairs(ListNode *head) {
        ListNode *p;
        ListNode *q;
        ListNode *prev;
        if(head == NULL || head ->next == NULL){
            return head;
        }
        p = head;
        q = p->next;
        p->next = q->next;
        q -> next = p;
        head = q;
        while(p->next != NULL && p->next->next != NULL){
            prev = p;
            p = prev->next;
            q = prev->next->next;
            p->next = q->next;
            q->next = p;
            prev->next = q;
        }
        return head;
    }
};
