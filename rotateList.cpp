
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *p, *q;
        p = head;
        int i = 0;
        if(head == NULL)
            return head;
        int len = 0;
        while(p!= NULL){
            len ++;
            p = p->next;
        }
        k = k%len;
        
        p = head;
        while(i < k && p != NULL){
            p = p->next;
            i++;
        }
        if(p == head || p == NULL)
            return head;
        q = head;
        while(p ->next != NULL){
            p = p->next;
            q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};
