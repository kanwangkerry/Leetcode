
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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p, *q;
        p = head;
        if(p == NULL || p->next == NULL || p->next->next == NULL)
            return;
        q = head;
        while(p != NULL && p->next != NULL){
            p = p->next->next;
            q = q->next;
        }
        ListNode *rhead = q;
        q = rhead->next;
        p = q->next;
        ListNode *temp;
        q -> next = NULL;
        while(p != NULL){
            temp = p->next;
            p->next = q;
            q = p;
            p = temp;
        }
        rhead->next = q;
        
        p = head;
        q = rhead->next;
        rhead->next = NULL;
        ListNode *temp1, *temp2;
        while(q != NULL){
            temp1 = p->next;
            temp2 = q->next;
            p->next = q;
            p = temp1;
            q->next = p;
            q = temp2;
        }
    }
};
