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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *p = head;
        ListNode *q = p;
        ListNode *prev, *temp;
        prev = NULL;
        while(1){
            int i = 0;
            temp = p;
            while(p != NULL && i++ < k){
                p = p->next;
            }
            if(p == NULL && i != k) break;
            if(prev == NULL) head =reverse(q, k, p);
            else prev->next = reverse(q, k, p);
            prev = temp;
            q = p;
        }
        return head;
        
    }
    
    ListNode *reverse(ListNode *head, int x, ListNode *nextHead){
        ListNode *p, *q, *prev, *temp;
        p = head;
        prev = nextHead;
        while(x--){
            temp = p->next;
            p -> next = prev;
            prev = p;
            p = temp;
        }
        return prev;
        
    }
};
