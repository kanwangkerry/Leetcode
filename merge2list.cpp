
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *p = l1, *q = l2;
        ListNode *head, *index;
        if(p == NULL && q == NULL)
            return NULL;
        if(p != NULL && q == NULL)
            return p;
        if(p == NULL && q != NULL)
            return q;
        if(p->val > q->val){
            head = q;
            q = q->next;
        }
        else{
            head = p;
            p = p->next;
        }
        index = head;
        while(p != NULL && q != NULL){
            if(p -> val > q->val){
                index -> next = q;
                q = q->next;
                index = index->next;
            }
            else{
                index -> next = p;
                p = p->next;
                index = index->next;
            }
        }
        if(q != NULL)
            p = q;
        while(p != NULL){
            index ->next = p;
            p = p->next;
            index = index->next;
        }
        return head;
    }
};
